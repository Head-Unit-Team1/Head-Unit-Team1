/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.14.v202310241606.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V0_COMMONAPI_IC_SOMEIP_STUB_ADAPTER_HPP_
#define V0_COMMONAPI_IC_SOMEIP_STUB_ADAPTER_HPP_

#include <v0/commonapi/ICStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {

template <typename _Stub = ::v0::commonapi::ICStub, typename... _Stubs>
class ICSomeIPStubAdapterInternal
    : public virtual ICStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< ICSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> ICSomeIPStubAdapterHelper;

    ~ICSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        ICSomeIPStubAdapterHelper::deinit();
    }

    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v0::commonapi::ICStub,
        CommonAPI::Version
    > getICInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v0::commonapi::ICStub,
        std::tuple< std::string>,
        std::tuple< int32_t>,
        std::tuple< CommonAPI::SomeIP::StringDeployment>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<int32_t>>
    > setGearStubDispatcher;
    
    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v0::commonapi::ICStub,
        std::tuple< >,
        std::tuple< int32_t, int32_t>,
        std::tuple< >,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<int32_t>, CommonAPI::SomeIP::IntegerDeployment<int32_t>>
    > getBatteryStubDispatcher;
    
    ICSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        ICSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< ICStub>(_stub)),
        getICInterfaceVersionStubDispatcher(&ICStub::lockInterfaceVersionAttribute, &ICStub::getInterfaceVersion, false, true),
        setGearStubDispatcher(
            &ICStub::setGear,
            false,
            _stub->hasElement(0),
            std::make_tuple(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr)))
        
        ,
        getBatteryStubDispatcher(
            &ICStub::getBattery,
            false,
            _stub->hasElement(1),
            std::make_tuple(),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr), static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr)))
        
    {
        ICSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7530) }, &setGearStubDispatcher );
        ICSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7531) }, &getBatteryStubDispatcher );
        // Provided events/fields
    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};


template <typename _Stub, typename... _Stubs>
void ICSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {

}

template <typename _Stub, typename... _Stubs>
void ICSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {

}

template <typename _Stub = ::v0::commonapi::ICStub, typename... _Stubs>
class ICSomeIPStubAdapter
    : public ICSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    ICSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          ICSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v0

#endif // V0_COMMONAPI_IC_SOMEIP_STUB_ADAPTER_HPP_