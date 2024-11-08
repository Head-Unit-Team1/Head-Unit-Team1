SUMMARY = "The implementation of SOME/IP"
SECTION = "base"
LICENSE = "MPLv2"
LIC_FILES_CHKSUM = "file://LICENSE;md5=9741c346eef56131163e13b9db1241b3"

DEPENDS = "boost dlt-daemon"

SRCREV = "fdf86239b4a6867e0a961a307649a6d5eb3a2f93"
SRC_URI = "file://vsomeip"
S = "${WORKDIR}/vsomeip"

inherit cmake lib_package gitpkgv


PACKAGES:remove = "${PN}-bin"


FILES:${PN}: += "${bindir}/vsomeipd ${sysconfdir}/${BPN}"
FILES:${PN}-dev += "${libdir}/cmake"

BBCLASSEXTEND = "nativesdk"

do_install:append() {
    mv ${D}/usr/etc ${D}
}

