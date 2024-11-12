SUMMARY = "CommonAPI"
SECTION = "libs"
LICENSE = "MPLv2"
LIC_FILES_CHKSUM = "file://LICENSE;md5=815ca599c9df247a0c7f619bab123dad"

PROVIDES = "commonapi3"
PR = "r0"

DEPENDS = "dlt-daemon"

inherit cmake lib_package pkgconfig

SRCREV = "008f6c11f5371e93c06b3ed337326008d2031084"
SRC_URI = "file://capicxx-core-runtime \
    "
S = "${WORKDIR}/capicxx-core-runtime"

EXTRA_OECMAKE += "-DCMAKE_INSTALL_PREFIX=/usr \
    -DINSTALL_LIB_DIR:PATH=${baselib} \
    -DINSTALL_CMAKE_DIR:PATH=${baselib}/cmake/CommonAPI \
    "

FILES_${PN}-dev += "${libdir}/cmake"
