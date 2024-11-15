#include "lrsign.h"

LRsign::LRsign(QObject * parent) : QObject(parent)
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
}

void LRsign::changeLRsign(int32_t changedSign){
    int32_t result = 0;
    CommonAPI::CallStatus callStatus;
    std::cout<<"lrsign : "<<changedSign<<std::endl;
    myProxy->setLrsign_interAsync(changedSign,
        [this, changedSign](CommonAPI::CallStatus callStatus, int32_t result) {
            if (callStatus == CommonAPI::CallStatus::SUCCESS) {
                std::cout << "Asynchronous result: " << result << std::endl;
                qt_lrsign = changedSign;
                emit lrValueChanged();
            } else {
                std::cout << "Failed to change lrsign asynchronously" << std::endl;
            }
        });
}
