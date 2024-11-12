#include "ic_interstubimpl.h"

IC_interStubImpl::IC_interStubImpl(Gear* gear, LRSign* lrsign, QObject *parent)
    : QObject(parent), gear_(gear), lrsign_(lrsign)
{
}

IC_interStubImpl::~IC_interStubImpl(){

}
void IC_interStubImpl::setGear_inter(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _gear, setGear_interReply_t _reply){
    std::cout << "gear changed from gamepad"<<_gear<<"\n";
    if(_gear == "P" || _gear == "D" || _gear == "N"){
        _reply(0);
        emit signalGear_inter(_gear);
    }else{
        _reply(-1);
    }
}

void IC_interStubImpl::setLrsign_inter(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _lrsign, setLrsign_interReply_t _relay){
    std::cout<<"LRsign changed from gamepad"<<_lrsign<<"\n";
    emit signalLrsign_inter(_lrsign);
}
