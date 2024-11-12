#!/bin/sh -e
chmod 666 /dev/fb0
cvlc --vout fb --no-osd --fullscreen --aspect-ratio=16:9 --video-align=center --video-filter=rotate --rotate-angle=90 --play-and-exit /home/root/videos/splashvideo_02.mp4
exit 0

