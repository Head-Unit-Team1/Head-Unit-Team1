#include "gear.h"

Gear::Gear(QObject *parent) : QObject(parent)
{
    runtime = CommonAPI::Runtime::get();
    myProxy = runtime->buildProxy<IC_interProxy>("local", "commonapi.IC_service_inter");
    myProxy->getProxyStatusEvent().subscribe([this](const CommonAPI::AvailabilityStatus& status) {
        if (status == CommonAPI::AvailabilityStatus::AVAILABLE) {
            std::cout << "Proxy is now available" << std::endl;
        } else {
            std::cout << "Proxy became unavailable" << std::endl;
        }
    });
//    while(!myProxy->isAvailable()){
//         std::cout << "proxy is not available"<<std::endl;
//    }
}

void Gear::changeGear(QString changedGear){
    int32_t result = 0;
    std::string stringGear = changedGear.toStdString();
    CommonAPI::CallStatus callStatus;
    std::cout<<"gear : "<<stringGear<<std::endl;
    myProxy->setGear_interAsync(stringGear,
        [this, changedGear](CommonAPI::CallStatus callStatus, int32_t result) {
            if (callStatus == CommonAPI::CallStatus::SUCCESS) {
                std::cout << "Asynchronous result: " << result << std::endl;
                qt_gear = changedGear;
                emit gearValueChanged();
            } else {
                std::cout << "Failed to change gear asynchronously" << std::endl;
            }
        });
}
