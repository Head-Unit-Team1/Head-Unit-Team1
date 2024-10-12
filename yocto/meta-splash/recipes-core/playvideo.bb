DESCRIPTION = "Play video script for boot"
LICENSE = "CLOSED"
SRC_URI = "file://playvideo.sh \
           file://splashvideo.mp4 \
           file://playvideo.service"

S = "${WORKDIR}"

do_install() {
    install -d ${D}/etc/init.d/
    install -m 0755 ${WORKDIR}/playvideo.sh ${D}/etc/init.d/playvideo.sh
    install -d ${D}/home/root/videos/
    install -m 0644 ${WORKDIR}/splashvideo.mp4 ${D}/home/root/videos/splashvideo.mp4

    install -d ${D}/etc/systemd/system/
    install -m 0644 ${WORKDIR}/playvideo.service ${D}/etc/systemd/system/playvideo.service
}
FILES_${PN} += " \
  ${sysconfdir}/init.d/playvideo.sh \
  ${systemd_unitdir}/system/playvideo.service \
  /home/root/videos/splashvideo.mp4 \
"
