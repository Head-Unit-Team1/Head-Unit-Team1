cmake_minimum_required(VERSION 3.15)
project(PiRacer-cpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SKIP_RPATH TRUE)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--hash-style=gnu")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--hash-style=gnu")

set(PRJ_NAME gamepad_control)

find_library(COMMONAPI_LIB CommonAPI PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++/3.1.12-r0/sysroot-destdir/usr/lib)
find_library(COMMONAPI_SOMEIP_LIB CommonAPI-SomeIP PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++-someip/3.1.12-r0/sysroot-destdir/usr/lib)
find_library(VSOMEIP_LIB vsomeip3 PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../vsomeip/2.7.0-r0/sysroot-destdir/usr/lib)


#for inner communication
set(PRJ_SRC_GEN_PATH-inter ${CMAKE_CURRENT_SOURCE_DIR}/src-gen-inter)
set(PRJ_SRC_GEN_COMMONAPI_PATH-inter ${PRJ_SRC_GEN_PATH-inter}/core/v0/commonapi)
set(PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH-inter ${PRJ_SRC_GEN_PATH-inter}/someip/v0/commonapi)

#file
FILE(GLOB PRJ_SOMEIP_LIB_SRCS
    ${PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH-inter}/*cpp
    )

add_library(${PRJ_NAME}-someip SHARED ${PRJ_SOMEIP_LIB_SRCS})
message("PRJ_SOMEIP_LIB_SRCS = ${PRJ_SOMEIP_LIB_SRCS}")
target_link_libraries(${PRJ_NAME}-someip CommonAPI-SomeIP)

find_package(pigpio REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/Adafruit_INA219
        ${CMAKE_CURRENT_SOURCE_DIR}/Adafruit_PCA9685
        ${CMAKE_CURRENT_SOURCE_DIR}/Gamepad
        ${CMAKE_CURRENT_SOURCE_DIR}/PiRacer
        ${pigpio_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/src-gen-inter
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++/3.1.12-r0/sysroot-destdir/usr/include/CommonAPI-3.2
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++-someip/3.1.12-r0/sysroot-destdir/usr/include/CommonAPI-3.2/
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++/3.1.12-r0/sysroot-destdir/usr/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++-someip/3.1.12-r0/sysroot-destdir/usr/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../vsomeip/2.7.0-r0/sysroot-destdir/usr/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++/3.1.12-r0/sysroot-destdir/usr/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common-api-c++-someip/3.1.12-r0/sysroot-destdir/usr/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../vsomeip/2.7.0-r0/sysroot-destdir/usr/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/src-gen-inter/core
        ${CMAKE_CURRENT_SOURCE_DIR}/src-gen-inter/someip
)

set(PIRACER_SRC
        ./Adafruit_INA219/Adafruit_INA219.cpp
        ./Adafruit_PCA9685/Adafruit_PCA9685.cpp
        ./PiRacer/PiRacer.cpp
)

set(GAMEPAD_SRC
        ./Gamepad/Joystick.cpp
        ./Gamepad/ShanwanGamepad.cpp
)

add_executable(forward_backward_left_right
        ./examples/forward_backward_left_right.cpp
        ${PIRACER_SRC}
)
target_link_libraries(forward_backward_left_right ${pigpio_LIBRARY})

add_executable(gamepad_control
        ./examples/gamepad_control.cpp
        ${PIRACER_SRC}
        ${GAMEPAD_SRC}
        ${COMMONAPI_LIB}
        ${COMMONAPI_SOMEIP_LIB}
        ${VSOMEIP_LIB}
        ./vsomeip.h
)
target_link_libraries(gamepad_control ${pigpio_LIBRARY}
        ${COMMONAPI_LIB}
        ${COMMONAPI_SOMEIP_LIB}
        ${VSOMEIP_LIB})

add_executable(read_battery
        ./examples/read_battery.cpp
        ${PIRACER_SRC}
)
target_link_libraries(read_battery ${pigpio_LIBRARY})


install(TARGETS forward_backward_left_right gamepad_control read_battery
        DESTINATION ${CMAKE_INSTALL_PREFIX})

