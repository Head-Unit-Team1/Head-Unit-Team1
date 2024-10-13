SUMMARY = "Play a splash video on boot"
LICENSE = "CLOSED"

SRC_URI = "file://playvideo.sh \
           file://playvideo.service \
           file://splashvideo.mp4"

inherit systemd

SYSTEMD_SERVICE:${PN} = "playvideo.service"

do_install() {
    install -d ${D}/etc/init.d/
    install -m 0755 ${WORKDIR}/playvideo.sh ${D}/etc/init.d/

    install -d ${D}/home/root/videos/
    install -m 0644 ${WORKDIR}/splashvideo.mp4 ${D}/home/root/videos/

    install -d ${D}/etc/systemd/system/
    install -m 0644 ${WORKDIR}/playvideo.service ${D}/etc/systemd/system/
}

ROOTFS_POSTPROCESS_COMMAND += "systemctl enable playvideo.service; "

FILES:${PN} += "/home/root/videos/"
