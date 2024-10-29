#include "batteryupdate.h"
#include <random>
#include <QDebug>

BatteryUpdate::BatteryUpdate(std::shared_ptr<Battery> battery, QObject *parent)
    : QObject(parent), m_battery(battery)  // m_battery 초기화
{
}

void BatteryUpdate::updateBatteryValue(int newvalue) {
}
