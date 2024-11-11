cmake_minimum_required(VERSION 3.14)

project(Head_Unit_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick WebEngine Network Multimedia REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick WebEngine Network Multimedia REQUIRED)
find_package(CommonAPI-SomeIP 3.2.0 REQUIRED)
find_package(vsomeip3 3.1.0 REQUIRED)

set(PRJ_SRC_GEN_PATH ../src-gen)
set(PRJ_SRC_GEN_COMMONAPI_PATH ${PRJ_SR_GEN_PATH}/core/v0/commonapi)
set(PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH ${PRJ_SRC_GEN_PATH}/someip/v0/commonapi)

# Application
FILE(GLOB PRJ_PROXY_GEN_SRCS ${PRJ_SRC_GEN_COMMONAPI_PATH}/*Proxy.cpp)
FILE(GLOB PRJ_STUB_GEN_SRCS ${PRJ_SRC_GEN_COMMONAPI_PATH}/*Stub*.cpp)
FILE(GLOB PRJ_STUB_IMPL_SRCS ${PRJ_SRC_COMMONAPI_PATH}/*Stub*.cpp)
 #Boost
find_package( Boost 1.66 COMPONENTS system thread log REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

FILE(GLOB PRJ_SOMEIP_LIB_SRCS ${PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH}/*cpp)

set(PRJ_NAME IC_someip)
set(RESOURCE_FILES
    resource.qrc
)

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        current_clock.h
        weather.h
        weather.cpp
        mapController.h
        mapController.cpp
        gearController.h
        youtubeController.h
        youtubeController.cpp
        carInfoController.h
        carInfoController.cpp
        battery.cpp
        battery.h
        mp3player.cpp
        mp3player.h
        usbscanner.cpp
        usbscanner.h
        extract_cover.py
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Head_Unit_app
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${RESOURCE_FILES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Head_Unit_app APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Head_Unit_app SHARED
            ${PROJECT_SOURCES}
            ${RESOURCE_FILES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Head_Unit_app
          ${PROJECT_SOURCES}
          ${RESOURCE_FILES}
          ../src-gen/someip/v0/commonapi/ICSomeIPDeployment.cpp
          ../src-gen/someip/v0/commonapi/ICSomeIPProxy.cpp
          ../src-gen/someip/v0/commonapi/ICSomeIPStubAdapter.cpp
        )
    endif()
endif()

include_directories(
    ../src-gen/
    ../../install_folder/include/CommonAPI-3.2
    ../../install_folder/include
    ../../install_folder/lib
    ../src-gen/core
    ../src-gen/someip
)

target_compile_definitions(Head_Unit_app
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

link_directories(
    ../../install_folder/lib)
# CommonAPI 라이브러리 찾기
find_library(COMMONAPI_LIB CommonAPI PATHS ../../install_folder/lib)
find_library(COMMONAPI_SOMEIP_LIB CommonAPI-SomeIP PATHS ../../install_folder/lib)
find_library(VSOMEIP_LIB vsomeip3 PATHS ../../install_folder/lib)

target_link_libraries(Head_Unit_app
  PRIVATE Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::WebEngine
  Qt${QT_VERSION_MAJOR}::Network
  Qt${QT_VERSION_MAJOR}::Multimedia
  ${COMMONAPI_LIB}
  ${COMMONAPI_SOMEIP_LIB}
  ${VSOMEIP_LIB}
  )

add_library(${PRJ_NAME}-someip SHARED ${PRJ_SOMEIP_LIB_SRCS})
target_link_libraries(${PRJ_NAME}-someip CommonAPI-SomeIP)

set_target_properties(Head_Unit_app PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(Head_Unit_app)
    qt_finalize_executable(Head_Unit_app)
endif()
