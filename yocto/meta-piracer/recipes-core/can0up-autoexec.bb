SUMMARY = "Build piracer-cpp repository"
LICENSE = "CLOSED"
SRC_URI = "file://can0up.service"

inherit systemd

S = "${WORKDIR}"
SYSTEMD_SERVICE:${PN} = "can0up.service"
SYSTEMD_AUTO_ENABLE:${PN} = "enable"

do_install() {
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 can0up.service ${D}${systemd_unitdir}/system
}

FILESEXTRAPATHS:prepend := "${THISDIR}/source:"
FILES:${PN} += "${systemd_unitdir}/system/can0up.service"

