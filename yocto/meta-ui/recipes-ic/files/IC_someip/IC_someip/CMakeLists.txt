cmake_minimum_required(VERSION 3.5)
project(IC_someip LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# RPATH 설정
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(PRJ_NAME IC_someip)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()


find_package(Qt5 COMPONENTS Core Quick Widgets Svg REQUIRED)
#find_package(CommonAPI-SomeIP 3.2.0 REQUIRED)
#find_package(CommonAPI-SomeIP 3.2.0 REQUIRED)

set(PRJ_SRC_GEN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../src-gen)
set(PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH ${PRJ_SRC_GEN_PATH}/someip/v0/commonapi)

set(PRJ_SRC_GEN_PATH_inter ${CMAKE_CURRENT_SOURCE_DIR}/../src-gen-inter)
set(PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH_inter ${PRJ_SRC_GEN_PATH_inter}/someip/v0/commonapi)
FILE(GLOB PRJ_SOMEIP_LIB_SRCS
    ${PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH}/*cpp
    ${PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH_inter}/*cpp
    )

if(ANDROID)
    add_library(IC_someip SHARED
      main.cpp
      qml.qrc
    )
    
else()
    add_executable(IC_someip
      main.cpp
      qml.qrc
      ICStubImpl.cpp
      gear.cpp
      speed.cpp
      battery.cpp
      batteryupdate.cpp
      battery_gauge.cpp
      Clock.h
      receiver.cpp
      get_battery.cpp
      lrsign.cpp
      mode.cpp
      ic_interstubimpl.cpp
    )
endif()

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../src-gen/
    ${CMAKE_CURRENT_SOURCE_DIR}/../src-gen-inter/
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++/3.1.12-r0/sysroot-destdir/usr/include/CommonAPI-3.2
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++-someip/3.1.12-r0/sysroot-destdir/usr/include/CommonAPI-3.2/
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++/3.1.12-r0/sysroot-destdir/usr/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++-someip/3.1.12-r0/sysroot-destdir/usr/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../vsomeip/2.7.0-r0/sysroot-destdir/usr/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++/3.1.12-r0/sysroot-destdir/usr/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++-someip/3.1.12-r0/sysroot-destdir/usr/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../vsomeip/2.7.0-r0/sysroot-destdir/usr/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../src-gen/core
    ${CMAKE_CURRENT_SOURCE_DIR}/../src-gen/someip
    ${CMAKE_CURRENT_SOURCE_DIR}/../src-gen-inter/core
    ${CMAKE_CURRENT_SOURCE_DIR}/../src-gen-inter/someip
)


target_compile_definitions(IC_someip
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
  

# CommonAPI 라이브러리 찾기
find_library(COMMONAPI_LIB CommonAPI PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++/3.1.12-r0/sysroot-destdir/usr/lib)
find_library(COMMONAPI_SOMEIP_LIB CommonAPI-SomeIP PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++-someip/3.1.12-r0/sysroot-destdir/usr/lib)
find_library(VSOMEIP_LIB vsomeip3 PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../vsomeip/2.7.0-r0/sysroot-destdir/usr/lib)

# 라이브러리 연결
target_link_libraries(IC_someip
    PRIVATE Qt5::Core Qt5::Quick
    ${COMMONAPI_LIB}
    ${COMMONAPI_SOMEIP_LIB}
    ${VSOMEIP_LIB}
)


add_library(${PRJ_NAME}-someip SHARED ${PRJ_SOMEIP_LIB_SRCS})
target_link_libraries(${PRJ_NAME}-someip CommonAPI-SomeIP)
