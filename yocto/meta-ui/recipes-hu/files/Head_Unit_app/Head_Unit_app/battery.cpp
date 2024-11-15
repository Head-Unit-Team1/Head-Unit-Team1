#include "battery.h"

Battery::Battery(QObject *parent) : QObject(parent), qt_battery(0)
{
    runtime = CommonAPI::Runtime::get();

    myProxy = runtime->buildProxy<ICProxy>("local","commonapi.IC_service");
    myProxy->getProxyStatusEvent().subscribe([this](CommonAPI::AvailabilityStatus status){
        if(status == CommonAPI::AvailabilityStatus::AVAILABLE){
            std::cout<<"Proxy is Available"<<std::endl;
        }else{
            std::cout<<"Proxy is NOT Available"<<std::endl;
        }
    });

//    while(!myProxy->isAvailable()){
//         std::cout << "proxy is not available"<<std::endl;
//         usleep(1000);
//    }
}

void Battery::getBattery(){
//    CommonAPI::CallStatus callStatus;
//    myProxy->getBattery(callStatus,bat,result);
//    qDebug()<<bat<<result;
//    std::cout<<"bat: "<<bat<<"  result:"<<result;
//    qt_battery = bat;
//    batteryValueChanged();
//    myProxy->getBatteryAsync([this](const CommonAPI::CallStatus &callStatus, int bat, int result){
//        if (callStatus == CommonAPI::CallStatus::SUCCESS){
//            qt_battery = bat;
//            emit batteryValueChanged();
//        }
//        else{
//            qDebug()<<"get battery failed";
//        }
//    });
}
