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

int i2c_fd;
int main(int argc, char *argv[])
{
    CommonAPI::Runtime::setProperty("LogContext", "E01C");
    CommonAPI::Runtime::setProperty("LogApplication", "E01C");
    CommonAPI::Runtime::setProperty("LibraryBase", "IC_someip");

    std::shared_ptr<Gear> gearPtr = std::make_shared<Gear>();
    std::shared_ptr<Battery> batteryPtr = std::make_shared<Battery>();

    std::shared_ptr<ICStubImpl> Service =
            std::make_shared<ICStubImpl>(gearPtr.get(),batteryPtr.get());
    qRegisterMetaType<std::string>("std::string");

    batteryPtr->setICStubImpl(Service.get());


    std::shared_ptr<CommonAPI::Runtime> runtimePtr = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "commonapi.IC_service";

    bool successfullyRegistered = runtimePtr->registerService(domain, instance, Service);
    while (!successfullyRegistered) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        successfullyRegistered = runtimePtr->registerService(domain, instance, Service);
    }
    std::cout << "Successfully Registered Service!" << std::endl;


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;



    engine.rootContext()->setContextProperty("gearObject", gearPtr.get());
    engine.rootContext()->setContextProperty("batteryObject", batteryPtr.get());

    QObject::connect(Service.get(), &ICStubImpl::signalGear, gearPtr.get(), &Gear::receiveGear);

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


    /*///////////////////////////////////////////////////////// test Battery gauge with random value */
    qreal battery = 0.0;
    qreal previousBattery = 0.0;
    const qreal b_threshold = 2.0; // 1.0

    std::deque<qreal> batteryValues;
    const int smoothWindowSize = 10; //5

    std::srand(std::time(nullptr));
    QTimer *timer_test_rpm = new QTimer(&app);

    QPropertyAnimation animation(speedometerObj, "battery");
    animation.setDuration(1000);
    animation.setEasingCurve(QEasingCurve::OutCubic);

    QObject::connect(timer_test_rpm, &QTimer::timeout, [&](){
        battery = static_cast<qreal>(std::rand() % 101);

        //battery = readVoltage(i2c_fd);

        batteryValues.push_back(battery);

        if (batteryValues.size() > smoothWindowSize){
            batteryValues.pop_front();
        }

        qreal batterySum = std::accumulate(batteryValues.begin(), batteryValues.end(), 0.0) / batteryValues.size();
        int batteryPercentage = calculateBatteryPercentage(batterySum); // final battery value?

        qDebug() << "battery gap : " << batteryPercentage - previousBattery;
        if (std::fabs(batteryPercentage - previousBattery) >= b_threshold){

            animation.setStartValue(speedometerObj->property("battery"));
            animation.setEndValue(batteryPercentage); // battery
//            animation.setDuration(1500);
            animation.start();
            previousBattery = batteryPercentage;

        }
        engine.rootContext()->setContextProperty("battery_value", batteryPercentage); //static_cast<int>(battery)

        qDebug() << "Battery : " << battery;
        qDebug() << "Battery percentage : " << batteryPercentage;
        batteryPtr->setBatteryValue(battery);
    });
    timer_test_rpm->start(1000);




/*/////////////////////////////////////////////////team7 code end*/
//    if (engine.rootObjects().isEmpty())
//          return -1;

    return app.exec();
}
