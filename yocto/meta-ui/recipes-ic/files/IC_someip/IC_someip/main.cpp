#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include "ICStubImpl.h"
//#include "speed.h"
#include "gear.h"
#include "battery.h"
#include <iostream>
#include <qmetatype.h>
#include "batteryupdate.h"
#include <QTimer>

#include <QDebug>
#include <QElapsedTimer>
#include <QCoreApplication>
#include <QPropertyAnimation>
#include <deque>
#include "Clock.h"
#include "speedProvider.h"
#include "battery_gauge.h"
#include "get_battery.h"
#include "receiver.h"
#include "mode.h"
#include "lrsign.h"
#include "ic_interstubimpl.h"
int i2c_fd;
int main(int argc, char *argv[])
{
    qRegisterMetaType<int32_t>("int32_t");

    CommonAPI::Runtime::setProperty("LogContext", "E01C");
    CommonAPI::Runtime::setProperty("LogApplication", "E01C");
    CommonAPI::Runtime::setProperty("LibraryBase", "IC_someip");

    std::shared_ptr<Gear> gearPtr = std::make_shared<Gear>();
    std::shared_ptr<Battery> batteryPtr = std::make_shared<Battery>();
    std::shared_ptr<Mode> modePtr = std::make_shared<Mode>();
    std::shared_ptr<LRSign> lrsignPtr = std::make_shared<LRSign>();

    std::shared_ptr<ICStubImpl> Service =
            std::make_shared<ICStubImpl>(gearPtr.get(),batteryPtr.get());

    std::shared_ptr<IC_interStubImpl> Service_inter =
            std::make_shared<IC_interStubImpl>(gearPtr.get(), lrsignPtr.get());
    qRegisterMetaType<std::string>("std::string");

    batteryPtr->setICStubImpl(Service.get());
    gearPtr->setICStubImpl(Service.get());

    std::shared_ptr<CommonAPI::Runtime> runtimePtr = CommonAPI::Runtime::get();
    std::string domain = "local";
    std::string instance = "commonapi.IC_service";
    std::string instance_inter = "commonapi.IC_service_inter";

    bool successfullyRegistered = runtimePtr->registerService(domain, instance, Service);
    bool successfullyRegistered_inter = runtimePtr->registerService(domain, instance_inter, Service_inter);

    while (!successfullyRegistered || !successfullyRegistered_inter) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        successfullyRegistered = runtimePtr->registerService(domain, instance, Service);
        successfullyRegistered_inter = runtimePtr->registerService(domain, instance_inter, Service_inter);
    }
    std::cout << "Successfully Registered Service!" << std::endl;


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;



    engine.rootContext()->setContextProperty("gearObject", gearPtr.get());
    engine.rootContext()->setContextProperty("batteryObject", batteryPtr.get());
    engine.rootContext()->setContextProperty("modeObject", modePtr.get());
    engine.rootContext()->setContextProperty("signObject", lrsignPtr.get());

    QObject::connect(Service.get(), &ICStubImpl::signalGear, gearPtr.get(), &Gear::receiveGear);
    QObject::connect(Service.get(), &ICStubImpl::signalStart, gearPtr.get(), &Gear::clientConnectedSignal);
    QObject::connect(Service.get(), &ICStubImpl::signalGear, Service_inter.get(), &IC_interStubImpl::notifyGearStatusChanged);
    QObject::connect(Service.get(), &ICStubImpl::signalMode, modePtr.get(), &Mode::receiveMode);
    QObject::connect(lrsignPtr.get(), &LRSign::broadcastDirection, Service.get(), &ICStubImpl::notifyLRSignStatusChanged);

    QObject::connect(Service_inter.get(), &IC_interStubImpl::signalGear_inter,gearPtr.get(), &Gear::receiveGear);
    QObject::connect(Service_inter.get(), &IC_interStubImpl::signalLrsign_inter,lrsignPtr.get(),&LRSign::sendLrsignRandom);
    QObject::connect(Service_inter.get(), &IC_interStubImpl::signalGear_inter,Service.get(), &ICStubImpl::notifyGearStatusChanged);
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


/*////////////////////////////////////////////////// team7 code start*/
    qmlRegisterType<battery_gauge>("com.DESInstrumentClusterTeam7.speedometer", 1, 0, "Speedometer");

    /*///////////////////////////////////////////////////////// set running rate */
    QElapsedTimer runTime;
    runTime.start(); // record time

    QTimer timer_run;
    QObject::connect(&timer_run, &QTimer::timeout, [&engine, &runTime]() {
            qDebug() << "Timer is running.1";
            qint64 elapsedTime = runTime.elapsed() / 1000;
            engine.rootContext()->setContextProperty("elapsedTime", elapsedTime);
    });
    timer_run.start(500); // update time periodical : per 0.5 sec

    /*///////////////////////////////////////////////////////// clock */
    Clock clock;
    Receiver receiver;

    receiver.initialize();
    receiver.start();

    //SpeedProvider speedProvider;

    //speedProvider.setMinSpeed(-200);
    //speedProvider.setMaxSpeed(200);

    engine.rootContext()->setContextProperty("Clock", &clock);
    engine.rootContext()->setContextProperty("Receiver", &receiver);
    //engine.rootContext()->setContextProperty("speedProvider", &speedProvider);

    /*///////////////////////////////////////////////////////// connect & load engine */
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl){
            QCoreApplication::exit(-1);
        }
    }, Qt::QueuedConnection);
    engine.load(url);


    // find root object
    QObject *object = engine.rootObjects().isEmpty() ? nullptr : engine.rootObjects().first();
    if (!object) {
        qCritical() << "No root objects found!";
        return -1;
    }

    // find RPM speedometer object
    QObject *speedometerObj = object->findChild<QObject*>("Battery_Gauge");
    if (!speedometerObj) {
        qCritical() << "Speedometer object not found in QML!";
        return -1;
    }
    // engine.rootObjects() : bring root object from QML file
    // findChild : find QML object which is named 'speedoMeter'

    // casting to speedometer object
    battery_gauge *ptrSpeedometer = qobject_cast<battery_gauge*>(speedometerObj);
    if (!ptrSpeedometer) {
        qCritical() << "Failed to cast Speedometer object!";
        return -1;
    }
    ptrSpeedometer->setModeClass(modePtr.get());


    /*///////////////////////////////////////////////////////// test Battery gauge with random value */
    qreal battery = 0.0;
    qreal previousBattery = 0.0;
    const qreal b_threshold = 2.0; // 1.0
    qreal batterySum = 100;
    std::deque<qreal> batteryValues;
    const int smoothWindowSize = 10; //5

    std::srand(std::time(nullptr));
    QTimer *timer_test_rpm = new QTimer(&app);

    QPropertyAnimation animation(speedometerObj, "battery");
    animation.setDuration(1000);
    animation.setEasingCurve(QEasingCurve::OutCubic);

    i2c_fd = open(I2C_BUS, O_RDWR);
    if (i2c_fd , 0) {
        return -1;
    }
    if (ioctl(i2c_fd, I2C_SLAVE, INA219_ADDRESS) < 0){
        close(i2c_fd);
        return -1;
    }

    QObject::connect(timer_test_rpm, &QTimer::timeout, [&](){
        //battery = static_cast<qreal>(std::rand() % 3) +9;

        battery = readVoltage(i2c_fd);

        batteryValues.push_back(battery);

        if (batteryValues.size() > smoothWindowSize){
            batteryValues.pop_front();
        }

        batterySum = std::accumulate(batteryValues.begin(), batteryValues.end(), 0.0) / batteryValues.size();
        qDebug() << "batterySum : " << batterySum;

        int batteryPercentage = calculateBatteryPercentage(batterySum); // final battery value?

        qDebug() << "battery gap : " << batteryPercentage - previousBattery;
        qDebug() << "batteryPercentage : " << batteryPercentage;
        qDebug() << "previousBattery : " << previousBattery;

        if (std::fabs(batteryPercentage - previousBattery) >= b_threshold){
            animation.setStartValue(speedometerObj->property("battery"));
            animation.setEndValue(batteryPercentage); // battery
            animation.setDuration(1500);
            animation.start();
            previousBattery = batteryPercentage;

        }
        engine.rootContext()->setContextProperty("battery_value", batteryPercentage); //static_cast<int>(battery)

        qDebug() << "Battery : " << battery;
        qDebug() << "Battery percentage : " << batteryPercentage;
        batteryPtr->setBatteryValue(batteryPercentage);
    });
    timer_test_rpm->start(1000);


    QObject::connect(Service.get(), &ICStubImpl::signalMode, ptrSpeedometer, &battery_gauge::resetColor);


/*/////////////////////////////////////////////////team7 code end*/
//    if (engine.rootObjects().isEmpty())
//          return -1;

    return app.exec();
}
