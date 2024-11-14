#!/bin/sh

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
