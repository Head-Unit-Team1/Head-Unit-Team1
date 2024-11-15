#include "gear.h"

Gear::Gear(QObject *parent) : QObject(parent)
{
    runtime = CommonAPI::Runtime::get();

    myProxy = runtime->buildProxy<ICProxy>("local", "commonapi.IC_service");
    while(!myProxy->isAvailable()){
         std::cout << "proxy is not available"<<std::endl;
         usleep(1000);
    }
}

void Gear::changeGear(QString changedGear){
    int32_t result;
    std::string stringGear = changedGear.QString::toStdString();
    CommonAPI::CallStatus callStatus;
    std::cout<<"gear : "<<stringGear<<std::endl;
    myProxy->setGear(stringGear, callStatus,result);
    std::cout<<"result : "<<result<<std::endl;
    qt_gear = changedGear;
}
