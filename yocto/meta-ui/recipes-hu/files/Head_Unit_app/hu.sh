#!/bin/sh

LD_LIBRARY_PATH=/usr/lib/:/opt/Head_Unit_app/build/
COMMONAPI_CONFIG=/opt/Head_Unit_app/commonapi4someip.ini
VSOMEIP_CONFIGURATION=/opt/Head_Unit_app/json/HU.json
VSOMEIP_APPLICATION_NAME=Head_Unit_app

export LD_LIBRARY_PATH
export COMMONAPI_CONFIG
export VSOMEIP_CONFIGURATION
export VSOMEIP_APPLICATION_NAME

/opt/Head_Unit_app/build/Head_Unit_app --no-sandbox
