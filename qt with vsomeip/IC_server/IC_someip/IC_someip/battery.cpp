#include "battery.h"

Battery::Battery(QObject *parent) : QObject(parent)
{

}

void Battery::setBatteryValue(int value){
    qt_battery = value;
    emit batteryValueChanged();
}

void Battery::q_setBatteryValue(int value){
    qt_battery = value;
    qDebug()<<qt_battery;
    batteryValueChanged();
}
