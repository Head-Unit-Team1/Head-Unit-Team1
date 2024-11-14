#!/bin/sh

LD_LIBRARY_PATH=/usr/lib/:/opt/piracer_vsomeip/build/
COMMONAPI_CONFIG=/opt/piracer_vsomeip/commonapi4someip.ini
VSOMEIP_CONFIGURATION=/opt/piracer_vsomeip/json/IC.json
VSOMEIP_APPLICATION_NAME=IC-service-inter

export LD_LIBRARY_PATH
export COMMONAPI_CONFIG
export VSOMEIP_CONFIGURATION
export VSOMEIP_APPLICATION_NAME

/opt/piracer_vsomeip/build/gamepad_control
