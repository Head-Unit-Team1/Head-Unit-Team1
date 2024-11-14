#!/bin/sh

# Common
if [ -f /usr/bin/set_ip ]; then
    /usr/bin/set_ip &
fi

# Instrument Cluster
if [ -f /usr/bin/gamepad ]; then
    /usr/bin/gamepad &
fi

if [ -f /usr/bin/ic ]; then
    /usr/bin/ic
fi

# Head Unit
if [ -f /usr/bin/hu ]; then
    /usr/bin/hu
fi
