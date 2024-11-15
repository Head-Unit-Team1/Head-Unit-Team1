#include "battery.h"
#include "ICStubImpl.h"
Battery::Battery(QObject *parent) : QObject(parent), icStubImpl_(nullptr)
{

}

void Battery::setBatteryValue(int value){
    qt_battery = value;
    emit batteryValueChanged();
    qDebug()<<qt_battery;
    if (icStubImpl_){
        qDebug()<<"intheloop";
        icStubImpl_->notifyBatteryStatusChanged(qt_battery);
    }else{
        qDebug()<<"notintheloop";
    }
}

void Battery::setICStubImpl(ICStubImpl *icStubImpl){
    icStubImpl_ = icStubImpl;
}

void Battery::q_setBatteryValue(int value){
    qt_battery = value;
    qDebug()<<qt_battery;
    if (icStubImpl_){
        qDebug()<<"intheloop";
        icStubImpl_->notifyBatteryStatusChanged(qt_battery);
    }else{
        qDebug()<<"notintheloop";
    }
}
