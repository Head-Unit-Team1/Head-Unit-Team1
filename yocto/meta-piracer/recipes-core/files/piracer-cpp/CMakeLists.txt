cmake_minimum_required(VERSION 3.15)
project(PiRacer-cpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SKIP_RPATH TRUE)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--hash-style=gnu")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--hash-style=gnu")


find_package(pigpio REQUIRED)

include_directories(
	./Adafruit_INA219
	./Adafruit_PCA9685
	./Gamepad
	./PiRacer
	${pigpio_INCLUDE_DIRS}
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
)
target_link_libraries(gamepad_control ${pigpio_LIBRARY})

add_executable(read_battery
	./examples/read_battery.cpp
	${PIRACER_SRC}
)
target_link_libraries(read_battery ${pigpio_LIBRARY})


install(TARGETS forward_backward_left_right gamepad_control read_battery
        DESTINATION ${CMAKE_INSTALL_PREFIX})

