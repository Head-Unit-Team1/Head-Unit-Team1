#ifndef VSOMEIP_H
#define VSOMEIP_H
#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/IC_interProxy.hpp>

using namespace v0::commonapi;

class vsomeip
{
public:
    explicit vsomeip(){
        runtime = CommonAPI::Runtime::get();
        myProxy = runtime->buildProxy<IC_interProxy>("local", "commonapi.IC_service_inter");
        myProxy->getProxyStatusEvent().subscribe([this](const CommonAPI::AvailabilityStatus& status) {
            if (status == CommonAPI::AvailabilityStatus::AVAILABLE) {
                std::cout << "Proxy is now available" << std::endl;
            } else {
                std::cout << "Proxy became unavailable" << std::endl;
            }
        });
        myProxy->getGearStatusChangedEvent().subscribe([this](const std::string& gearValue){
            qt_gear = gearValue;
            std::cout << "Broadcast come"<<std::endl;
            });
    }
    std::string gearValue(){
    	return qt_gear;
    }
    void changeGear(std::string changedGear){
        int32_t result = 0;
        CommonAPI::CallStatus callStatus;
        std::cout<<"gear : "<<changedGear<<std::endl;
        myProxy->setGear_interAsync(changedGear,
            [this, changedGear](CommonAPI::CallStatus callStatus, int32_t result) {
                if (callStatus == CommonAPI::CallStatus::SUCCESS) {
                    std::cout << "Asynchronous result: " << result << std::endl;
                    qt_gear = changedGear;
                } else {
                    std::cout << "Failed to change gear asynchronously" << std::endl;
                }
            });
    }
    void changeLRsign(int32_t changedSign){
        int32_t result = 0;
        CommonAPI::CallStatus callStatus;
        std::cout<<"lrsign : "<<changedSign<<std::endl;
        myProxy->setLrsign_interAsync(changedSign,
            [this, changedSign](CommonAPI::CallStatus callStatus, int32_t result) {
                if (callStatus == CommonAPI::CallStatus::SUCCESS) {
                    std::cout << "Asynchronous result: " << result << std::endl;
                    qt_lrsign = changedSign;
                } else {
                    std::cout << "Failed to change lrsign asynchronously" << std::endl;
                }
            });
    }
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IC_interProxy<>> myProxy;
private:
    std::string qt_gear = "P";
    int32_t qt_lrsign = 0;

};

#endif // VSOMEIP_H
