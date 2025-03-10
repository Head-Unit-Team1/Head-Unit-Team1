/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.14.v202310241606.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V0_COMMONAPI_IC_SOMEIP_PROXY_HPP_
#define V0_COMMONAPI_IC_SOMEIP_PROXY_HPP_

#include <v0/commonapi/ICProxyBase.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Proxy.hpp>
#include <CommonAPI/SomeIP/Types.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <string>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v0 {
namespace commonapi {

class ICSomeIPProxy
    : virtual public ICProxyBase,
      virtual public CommonAPI::SomeIP::Proxy {
public:
    ICSomeIPProxy(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection);

    virtual ~ICSomeIPProxy();

    virtual void setGear(std::string _gear, CommonAPI::CallStatus &_internalCallStatus, int32_t &_result, const CommonAPI::CallInfo *_info);

    virtual std::future<CommonAPI::CallStatus> setGearAsync(const std::string &_gear, SetGearAsyncCallback _callback, const CommonAPI::CallInfo *_info);

    virtual void getBattery(CommonAPI::CallStatus &_internalCallStatus, int32_t &_battery, int32_t &_result, const CommonAPI::CallInfo *_info);

    virtual std::future<CommonAPI::CallStatus> getBatteryAsync(GetBatteryAsyncCallback _callback, const CommonAPI::CallInfo *_info);

    virtual void getOwnVersion(uint16_t &_major, uint16_t &_minor) const;

    virtual std::future<void> getCompletionFuture();

private:

};

} // namespace commonapi
} // namespace v0

#endif // V0_COMMONAPI_IC_SOMEIP_PROXY_HPP_
