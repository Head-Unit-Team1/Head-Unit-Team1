#include "ICStubImpl.h"
#include "vehiclecomponents.h"
#include "speed.h"
#include "battery.h"

ICStubImpl::ICStubImpl(VehicleComponents components, QObject *parent)
    : QObject(parent), components_(components) {
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
    int32_t batteryValue = components_.battery->batteryValue();
    if(batteryValue >= 0 || batteryValue <= 100){
        _reply(batteryValue, 0);
    }else{
        _reply(batteryValue, -1);
    }
}
