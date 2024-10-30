#!/bin/sh
/usr/sbin/wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant.conf
/usr/sbin/udhcpc -i wlan0
