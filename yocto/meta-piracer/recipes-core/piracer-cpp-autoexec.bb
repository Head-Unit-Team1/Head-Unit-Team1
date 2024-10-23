SUMMARY = "Build piracer-cpp repository"
LICENSE = "CLOSED"
SRC_URI = "file://piracercpp.service"

inherit systemd

S = "${WORKDIR}"
SYSTEMD_SERVICE:${PN} = "piracercpp.service"
SYSTEMD_AUTO_ENABLE:${PN} = "enable"

do_install() {
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 piracercpp.service ${D}${systemd_unitdir}/system
}

FILESEXTRAPATHS:prepend := "${THISDIR}/source:"
FILES:${PN} += "${systemd_unitdir}/system/piracercpp.service"

