cmake_minimum_required(VERSION 3.14)

project(Head_Unit_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick WebEngine Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick WebEngine Network REQUIRED)

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
        )
    endif()
endif()

target_compile_definitions(Head_Unit_app
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Head_Unit_app
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::WebEngine Qt${QT_VERSION_MAJOR}::Network)

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
