SUMMARY = "Play a splash video on boot"
LICENSE = "CLOSED"

SRC_URI = "file://playvideo.sh \
           file://splashvideo_02.mp4 \
           file://getty@tty1.service \
           file://videoplay.service \
           "

inherit systemd
S = "${WORKDIR}"

SYSTEMD_SERVICE:${PN} = "videoplay.service \
			 "
SYSTEMD_AUTO_ENABLE:${PN} = "enable"

do_install() {
    install -d ${D}/home/root/
    install -m 0755 ${WORKDIR}/playvideo.sh ${D}/home/root/

    install -d ${D}/home/root/videos/
    install -m 0644 ${WORKDIR}/splashvideo_02.mp4 ${D}/home/root/videos/

    install -d ${D}/etc/systemd/system/
    install -m 0644 ${WORKDIR}/getty@tty1.service ${D}/etc/systemd/system/
    install -m 0644 ${WORKDIR}/videoplay.service ${D}/etc/systemd/system/
}

FILES:${PN} += "/home/root/videos/ \
                /etc/systemd/system/ \
                /home/root/ \
               "
               
