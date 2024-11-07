DESCRIPTION = "Set Qt5 Configuration"

SRC_URI += "file://qt-qpa-platform.service"
LICENSE = "CLOSED"

inherit systemd

S = "${WORKDIR}"
SYSTEMD_SERVICE:${PN} = "qt-qpa-platform.service"
SYSTEMD_AUTO_ENABLE:${PN} = "enable"

do_install() {
  install -d ${D}${systemd_unitdir}/system
  install -m 0644 qt-qpa-platform.service ${D}${systemd_unitdir}/system
}

FILESEXTRAPATHS:prepend := "${THISDIR}/source:"

FILES:${PN} += "${systemd_unitdir}/system/qt-qpa-platform.service"
