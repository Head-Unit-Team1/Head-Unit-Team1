#include "gear.h"

Gear::Gear(QObject *parent) : QObject(parent)
{
}

void Gear::receiveGear(std::string command)
{
    qt_gear = QString::fromStdString(command);
    emit gearValueChanged();
}
