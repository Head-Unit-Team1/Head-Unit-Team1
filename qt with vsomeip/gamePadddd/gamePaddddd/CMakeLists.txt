cmake_minimum_required(VERSION 3.5)

project(gamePaddddd LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(PRJ_NAME gamepaddddd)

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

find_package(Qt5 COMPONENTS Core Quick REQUIRED)
find_package (CommonAPI-SomeIP 3.2.0 REQUIRED)
find_package (vsomeip3 3.1.0 REQUIRED)

set(PRJ_SRC_GEN_PATH ../src-gen-inter)
set(PRJ_SRC_GEN_COMMONAPI_PATH ${PRJ_SRC_GEN_PATH}/core/v0/commonapi)
set(PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH ${PRJ_SRC_GEN_PATH}/someip/v0/commonapi)
FILE(GLOB PRJ_SOMEIP_LIB_SRCS
    ${PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH}/*cpp
    )


if(ANDROID)
    add_library(gamePaddddd SHARED
      main.cpp
      qml.qrc
    )
else()
    add_executable(gamePaddddd
      main.cpp
      qml.qrc
      gear.cpp
      lrsign.cpp
    )
endif()

include_directories(
    ../src-gen-inter
    ../../install_folder/include/CommonAPI-3.2
    ../../install_folder/include
    ../../install_folder/lib
    ../src-gen-inter/core
    ../src-gen-inter/someip
)

link_directories(
    ../../install_folder/lib)

target_compile_definitions(gamePaddddd
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

find_library(COMMONAPI_LIB CommonAPI PATHS ../../install_folder/lib)
find_library(COMMONAPI_SOMEIP_LIB CommonAPI-SomeIP PATHS ../../install_folder/lib)
find_library(VSOMEIP_LIB vsomeip3 PATHS ../../install_folder/lib)

target_link_libraries(gamePaddddd
    PRIVATE Qt5::Core Qt5::Quick
    ${COMMONAPI_LIB}
    ${COMMONAPI_SOMEIP_LIB}
    ${VSOMEIP_LIB}
)
add_library(${PRJ_NAME}-someip SHARED ${PRJ_SOMEIP_LIB_SRCS})
message("PRJ_SOMEIP_LIB_SRCS = ${PRJ_SOMEIP_LIB_SRCS}")
target_link_libraries(${PRJ_NAME}-someip CommonAPI-SomeIP)
