cmake_minimum_required(VERSION 3.5)
project(IC_someip LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
#set(CMAKE_INSTALL_RPATH "/home/jwoon/Desktop/commonapi_vsomeip/install_folder/lib")
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

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)

if(ANDROID)
    add_library(IC_someip SHARED
      main.cpp
      qml.qrc
    )
else()
    add_executable(IC_someip
      main.cpp
      qml.qrc
      ../src-gen/someip/v0/commonapi/ICSomeIPDeployment.cpp
      ../src-gen/someip/v0/commonapi/ICSomeIPProxy.cpp
      ../src-gen/someip/v0/commonapi/ICSomeIPStubAdapter.cpp
      ICStubImpl.cpp
      gear.cpp
      speed.cpp
      battery.cpp
      batteryupdate.cpp
      battery_gauge.cpp
      Clock.h
      receiver.cpp
      get_battery.cpp
    )
endif()

# Include directories
target_include_directories(IC_someip PRIVATE
    ../src-gen/
    ../../install_folder/include/CommonAPI-3.2
    ../../install_folder/include
    ../../install_folder/lib
    ../src-gen/core
    ../src-gen/someip
)

target_compile_definitions(IC_someip
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
link_directories(
    ../../install_folder/lib)
# CommonAPI 라이브러리 찾기
find_library(COMMONAPI_LIB CommonAPI PATHS ../../install_folder/lib)
find_library(COMMONAPI_SOMEIP_LIB CommonAPI-SomeIP PATHS ../../install_folder/lib)
find_library(VSOMEIP_LIB vsomeip3 PATHS ../../install_folder/lib)

# 라이브러리 연결
target_link_libraries(IC_someip
    PRIVATE Qt5::Core Qt5::Quick
    ${COMMONAPI_LIB}
    ${COMMONAPI_SOMEIP_LIB}
    ${VSOMEIP_LIB}
)
add_library(${PRJ_NAME}-someip SHARED ${PRJ_SOMEIP_LIB_SRCS})
target_link_libraries(${PRJ_NAME}-someip CommonAPI-SomeIP)
