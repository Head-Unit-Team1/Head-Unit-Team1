#include "carInfoController.h"
#include <QTimer>

CarInfoController::CarInfoController(QObject *parent)
    : QObject(parent), m_batteryLevel(80), m_modeColor("#A2F2D9"), m_direction("left"), qt_battery(0) {
    runtime = CommonAPI::Runtime::get();

    myProxy = runtime->buildProxy<ICProxy>("local","commonapi.IC_service");
    std::cout<<"Pailable"<<std::endl;

    while(!myProxy->isAvailable()){
         std::cout << "proxy is not available"<<std::endl;
    }

    myProxy->getProxyStatusEvent().subscribe([this](CommonAPI::AvailabilityStatus status){
        if(status == CommonAPI::AvailabilityStatus::AVAILABLE){
            std::cout<<"Proxy is Avbbbbbailable"<<std::endl;
        }else{
            std::cout<<"Proxy is NOT bbbbbbbbbAvailable"<<std::endl;
        }
    });


    myProxy->getBatteryStatusChangedEvent().subscribe([this](int32_t batValue){
        qDebug()<<"battery change" << batValue;
        this->qt_battery = batValue;
        emit batteryValueChanged();
    });
/*
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CarInfoController::getBattery);
    timer->start(1000);/*/
}

int CarInfoController::batteryLevel() const {
    return m_batteryLevel;
}

void CarInfoController::setBatteryLevel(int level) {
    if (m_batteryLevel != level) {
        m_batteryLevel = level;
        emit batteryLevelChanged();
    }
}

QString CarInfoController::modeColor() const {
    return m_modeColor;
}

void CarInfoController::setModeColor(const QString& color) {
    if (m_modeColor != color) {
        m_modeColor = color;
        emit modeColorChanged();
    }
}

QString CarInfoController::blinkDirection() const {
    return m_direction;
}

void CarInfoController::setDirection(const QString& direction) {
    if (m_direction != direction) {
        m_direction = direction;
        emit directionChanged();
    }
}

int CarInfoController::batteryValue() const {
    return qt_battery;
}

void CarInfoController::getBattery() {
    myProxy->getBatteryAsync([this](const CommonAPI::CallStatus &callStatus, int bat, int result){
        if (callStatus == CommonAPI::CallStatus::SUCCESS){
            qt_battery = bat;
            emit batteryValueChanged();
        }
        else{
            qDebug()<<"get battery failed";
        }
    });
}
