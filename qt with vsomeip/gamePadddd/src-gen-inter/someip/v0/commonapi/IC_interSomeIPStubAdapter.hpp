/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.14.v202310241606.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V0_COMMONAPI_IC_INTER_SOMEIP_STUB_ADAPTER_HPP_
#define V0_COMMONAPI_IC_INTER_SOMEIP_STUB_ADAPTER_HPP_

#include <v0/commonapi/IC_interStub.hpp>

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

template <typename _Stub = ::v0::commonapi::IC_interStub, typename... _Stubs>
class IC_interSomeIPStubAdapterInternal
    : public virtual IC_interStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< IC_interSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> IC_interSomeIPStubAdapterHelper;

    ~IC_interSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        IC_interSomeIPStubAdapterHelper::deinit();
    }

    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v0::commonapi::IC_interStub,
        CommonAPI::Version
    > getIC_interInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v0::commonapi::IC_interStub,
        std::tuple< std::string>,
        std::tuple< int32_t>,
        std::tuple< CommonAPI::SomeIP::StringDeployment>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<int32_t>>
    > setGear_interStubDispatcher;
    
    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v0::commonapi::IC_interStub,
        std::tuple< int32_t>,
        std::tuple< int32_t>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<int32_t>>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<int32_t>>
    > setLrsign_interStubDispatcher;
    
    IC_interSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        IC_interSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< IC_interStub>(_stub)),
        getIC_interInterfaceVersionStubDispatcher(&IC_interStub::lockInterfaceVersionAttribute, &IC_interStub::getInterfaceVersion, false, true),
        setGear_interStubDispatcher(
            &IC_interStub::setGear_inter,
            false,
            _stub->hasElement(0),
            std::make_tuple(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr)))
        
        ,
        setLrsign_interStubDispatcher(
            &IC_interStub::setLrsign_inter,
            false,
            _stub->hasElement(1),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr)))
        
    {
        IC_interSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7918) }, &setGear_interStubDispatcher );
        IC_interSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7919) }, &setLrsign_interStubDispatcher );
        // Provided events/fields
    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};


template <typename _Stub, typename... _Stubs>
void IC_interSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {

}

template <typename _Stub, typename... _Stubs>
void IC_interSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {

}

template <typename _Stub = ::v0::commonapi::IC_interStub, typename... _Stubs>
class IC_interSomeIPStubAdapter
    : public IC_interSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    IC_interSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          IC_interSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v0

#endif // V0_COMMONAPI_IC_inter_SOMEIP_STUB_ADAPTER_HPP_
