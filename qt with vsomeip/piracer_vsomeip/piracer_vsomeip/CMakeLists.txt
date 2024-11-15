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

find_package (CommonAPI-SomeIP 3.2.0 REQUIRED)
find_package (vsomeip3 3.1.0 REQUIRED)

find_library(COMMONAPI_LIB CommonAPI PATHS ../../install_folder/lib)
find_library(COMMONAPI_SOMEIP_LIB CommonAPI-SomeIP PATHS ../../install_folder/lib)
find_library(VSOMEIP_LIB vsomeip3 PATHS ../../install_folder/lib)


#for inner communication
set(PRJ_SRC_GEN_PATH-inter ./src-gen-inter)
set(PRJ_SRC_GEN_COMMONAPI_PATH-inter ${PRJ_SRC_GEN_PATH-inter}/core/v0/commonapi)
set(PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH-inter ${PRJ_SRC_GEN_PATH-inter}/someip/v0/commonapi)
#Boost
find_package( Boost 1.66 COMPONENTS system thread log REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )
#file
FILE(GLOB PRJ_SOMEIP_LIB_SRCS
    ${PRJ_SRC_GEN_COMMONAPI_SOMEIP_PATH-inter}/*cpp
    )





add_library(${PRJ_NAME}-someip SHARED ${PRJ_SOMEIP_LIB_SRCS})
message("PRJ_SOMEIP_LIB_SRCS = ${PRJ_SOMEIP_LIB_SRCS}")
target_link_libraries(${PRJ_NAME}-someip CommonAPI-SomeIP)

find_package(pigpio REQUIRED)

include_directories(
        ./Adafruit_INA219
        ./Adafruit_PCA9685
        ./Gamepad
        ./PiRacer
        ${pigpio_INCLUDE_DIRS}
        ./src-gen-inter
        ../../install_folder/include/CommonAPI-3.2
        ../../install_folder/include
        ../../install_folder/lib
        ./src-gen-inter/core
        ./src-gen-inter/someip
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
        vsomeip.cpp
)
target_link_libraries(gamepad_control ${pigpio_LIBRARY})

add_executable(read_battery
        ./examples/read_battery.cpp
        ${PIRACER_SRC}
)
target_link_libraries(read_battery ${pigpio_LIBRARY})


install(TARGETS forward_backward_left_right gamepad_control read_battery
        DESTINATION ${CMAKE_INSTALL_PREFIX})

