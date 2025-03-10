/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.14.v202310241605.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V0_COMMONAPI_IC_inter_PROXY_HPP_
#define V0_COMMONAPI_IC_inter_PROXY_HPP_

#include <v0/commonapi/IC_interProxyBase.hpp>


#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {

template <typename ... _AttributeExtensions>
class IC_interProxy
    : virtual public IC_inter,
      virtual public IC_interProxyBase,
      virtual public _AttributeExtensions... {
public:
    IC_interProxy(std::shared_ptr<CommonAPI::Proxy> delegate);
    ~IC_interProxy();

    typedef ::v0::commonapi::IC_inter InterfaceType;


    /**
     * Returns the CommonAPI address of the remote partner this proxy communicates with.
     */
    virtual const CommonAPI::Address &getAddress() const;

    /**
     * Returns true if the remote partner for this proxy is currently known to be available.
     */
    virtual bool isAvailable() const;

    /**
     * Returns true if the remote partner for this proxy is available.
     */
    virtual bool isAvailableBlocking() const;

    /**
     * Returns the wrapper class that is used to (de-)register for notifications about
     * the availability of the remote partner of this proxy.
     */
    virtual CommonAPI::ProxyStatusEvent& getProxyStatusEvent();

    /**
     * Returns the wrapper class that is used to access version information of the remote
     * partner of this proxy.
     */
    virtual CommonAPI::InterfaceVersionAttribute& getInterfaceVersionAttribute();

    virtual std::future<void> getCompletionFuture();

    /**
     * Calls setGear_inter with synchronous semantics.
     *
     * All const parameters are input parameters to this method.
     * All non-const parameters will be filled with the returned values.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     */
    virtual void setGear_inter(std::string _gear, CommonAPI::CallStatus &_internalCallStatus, int32_t &_result, const CommonAPI::CallInfo *_info = nullptr);
    /**
     * Calls setGear_inter with asynchronous semantics.
     *
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> setGear_interAsync(const std::string &_gear, SetGear_interAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr);
    /**
     * Calls setLrsign_inter with synchronous semantics.
     *
     * All const parameters are input parameters to this method.
     * All non-const parameters will be filled with the returned values.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     */
    virtual void setLrsign_inter(int32_t _lrsign, CommonAPI::CallStatus &_internalCallStatus, int32_t &_result, const CommonAPI::CallInfo *_info = nullptr);
    /**
     * Calls setLrsign_inter with asynchronous semantics.
     *
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> setLrsign_interAsync(const int32_t &_lrsign, SetLrsign_interAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr);



 private:
    std::shared_ptr< IC_interProxyBase> delegate_;
};

typedef IC_interProxy<> IC_interProxyDefault;


//
// IC_interProxy Implementation
//
template <typename ... _AttributeExtensions>
IC_interProxy<_AttributeExtensions...>::IC_interProxy(std::shared_ptr<CommonAPI::Proxy> delegate):
        _AttributeExtensions(*(std::dynamic_pointer_cast< IC_interProxyBase>(delegate)))...,
        delegate_(std::dynamic_pointer_cast< IC_interProxyBase>(delegate)) {
}

template <typename ... _AttributeExtensions>
IC_interProxy<_AttributeExtensions...>::~IC_interProxy() {
}

template <typename ... _AttributeExtensions>
void IC_interProxy<_AttributeExtensions...>::setGear_inter(std::string _gear, CommonAPI::CallStatus &_internalCallStatus, int32_t &_result, const CommonAPI::CallInfo *_info) {
    delegate_->setGear_inter(_gear, _internalCallStatus, _result, _info);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> IC_interProxy<_AttributeExtensions...>::setGear_interAsync(const std::string &_gear, SetGear_interAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    return delegate_->setGear_interAsync(_gear, _callback, _info);
}
template <typename ... _AttributeExtensions>
void IC_interProxy<_AttributeExtensions...>::setLrsign_inter(int32_t _lrsign, CommonAPI::CallStatus &_internalCallStatus, int32_t &_result, const CommonAPI::CallInfo *_info) {
    delegate_->setLrsign_inter(_lrsign, _internalCallStatus, _result, _info);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> IC_interProxy<_AttributeExtensions...>::setLrsign_interAsync(const int32_t &_lrsign, SetLrsign_interAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    return delegate_->setLrsign_interAsync(_lrsign, _callback, _info);
}

template <typename ... _AttributeExtensions>
const CommonAPI::Address &IC_interProxy<_AttributeExtensions...>::getAddress() const {
    return delegate_->getAddress();
}

template <typename ... _AttributeExtensions>
bool IC_interProxy<_AttributeExtensions...>::isAvailable() const {
    return delegate_->isAvailable();
}

template <typename ... _AttributeExtensions>
bool IC_interProxy<_AttributeExtensions...>::isAvailableBlocking() const {
    return delegate_->isAvailableBlocking();
}

template <typename ... _AttributeExtensions>
CommonAPI::ProxyStatusEvent& IC_interProxy<_AttributeExtensions...>::getProxyStatusEvent() {
    return delegate_->getProxyStatusEvent();
}

template <typename ... _AttributeExtensions>
CommonAPI::InterfaceVersionAttribute& IC_interProxy<_AttributeExtensions...>::getInterfaceVersionAttribute() {
    return delegate_->getInterfaceVersionAttribute();
}


template <typename ... _AttributeExtensions>
std::future<void> IC_interProxy<_AttributeExtensions...>::getCompletionFuture() {
    return delegate_->getCompletionFuture();
}

} // namespace commonapi
} // namespace v0



// Compatibility
namespace v0_1 = v0;

#endif // V0_COMMONAPI_IC_inter_PROXY_HPP_
