#!/bin/sh -e
chmod 666 /dev/fb0
cvlc --vout fb --no-osd --fullscreen --play-and-exit /home/root/videos/splashvideo_02.mp4
exit 0
