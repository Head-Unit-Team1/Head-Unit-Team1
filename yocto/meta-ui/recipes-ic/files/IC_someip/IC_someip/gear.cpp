#include "gear.h"
#include "ICStubImpl.h"
#include <QDebug>
Gear::Gear(QObject *parent) : QObject(parent), icStubImpl_(nullptr)
{
}

void Gear::setICStubImpl(ICStubImpl *icStubImpl){
    icStubImpl_ = icStubImpl;
}

void Gear::receiveGear(std::string command)
{
    qt_gear = QString::fromStdString(command);
    emit gearValueChanged();
}

void Gear::sendGearRandom(QString ChangedGear){
    qt_gear = ChangedGear;
    emit gearValueChanged();
    std::string stringGear = ChangedGear.QString::toStdString();
    icStubImpl_->notifyGearStatusChanged(stringGear);

}

void Gear::clientConnectedSignal(){
    emit clientConnected();
}
