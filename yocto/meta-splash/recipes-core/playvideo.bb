SUMMARY = "Play a splash video on boot"
LICENSE = "CLOSED"

SRC_URI = "file://playvideo.sh \
           file://playvideo.service \
           file://splashvideo_02.mp4 \
           "

inherit systemd
S = "${WORKDIR}"
SYSTEMD_SERVICE:${PN} = "playvideo.service"
SYSTEMD_AUTO_ENABLE:${PN} = "enable"

do_install() {
    install -d ${D}/etc/init.d/
    install -m 0755 ${WORKDIR}/playvideo.sh ${D}/etc/init.d/

    install -d ${D}/home/root/videos/
    install -m 0644 ${WORKDIR}/splashvideo_02.mp4 ${D}/home/root/videos/

    install -d ${D}/etc/systemd/system/
    install -m 0644 ${WORKDIR}/playvideo.service ${D}/etc/systemd/system/
}

FILES:${PN} += "/home/root/videos/ \
                /etc/systemd/system/ \
                /etc/init.d/ \
               "
               
