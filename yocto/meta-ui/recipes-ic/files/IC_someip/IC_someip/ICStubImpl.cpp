#include "ICStubImpl.h"
#include "speed.h"
#include "battery.h"

ICStubImpl::ICStubImpl(Gear* gear, Battery * battery, QObject *parent)
    : QObject(parent), gear_(gear),battery_(battery) {
}
ICStubImpl::~ICStubImpl(){

}

void ICStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _gear, setGearReply_t _reply){
    std::cout << "gear :" << _gear << "\n";
    emit signalGear(_gear);
    if(_gear == "P" || _gear == "D" || _gear == "N"){
        _reply(0);
    }else{
        _reply(-1);
    }
}
void ICStubImpl::getBattery(const std::shared_ptr<CommonAPI::ClientId> _client, getBatteryReply_t _reply) {
    int32_t batteryValue = battery_->batteryValue();
    if(batteryValue >= 0 || batteryValue <= 100){
        _reply(batteryValue, 0);
    }else{
        _reply(batteryValue, -1);
    }
}
void ICStubImpl::notifyBatteryStatusChanged(int32_t batteryValue){
    if(batteryValue >=0 && batteryValue <= 100){
        qDebug()<<"bat has changed to"<<batteryValue;
        fireBatteryStatusChangedEvent(batteryValue);
    }
}
