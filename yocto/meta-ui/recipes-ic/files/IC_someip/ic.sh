#!/bin/sh

LD_LIBRARY_PATH=/usr/lib/:/opt/IC_someip/build/
COMMONAPI_CONFIG=/opt/IC_someip/commonapi4someip.ini
VSOMEIP_CONFIGURATION=/opt/IC_someip/json/IC.json
VSOMEIP_APPLICATION_NAME=IC-service

export LD_LIBRARY_PATH
export COMMONAPI_CONFIG
export VSOMEIP_CONFIGURATION
export VSOMEIP_APPLICATION_NAME

/opt/IC_someip/build/IC_someip
