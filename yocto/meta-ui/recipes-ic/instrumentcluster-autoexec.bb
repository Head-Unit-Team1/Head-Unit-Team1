SUMMARY = "auto execute instrumentcluster"
LICENSE = "CLOSED"
SRC_URI = "file://instrumentcluster.service"

inherit systemd

S = "${WORKDIR}"
SYSTEMD_SERVICE:${PN} = "instrumentcluster.service"
SYSTEMD_AUTO_ENABLE:${PN} = "enable"

do_install() {
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 instrumentcluster.service ${D}${systemd_unitdir}/system
}

FILESEXTRAPATHS:prepend := "${THISDIR}/source:"
FILES:${PN} += "${systemd_unitdir}/system/instrumentcluster.service"

