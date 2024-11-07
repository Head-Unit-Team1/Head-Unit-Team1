SUMMARY = "Clone piracer-cpp repository And Build"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=33a2ac025994ad1ea98eb2e01c1c8df3"

SRC_URI = "file://piracer-cpp"

S = "${WORKDIR}/piracer-cpp"

B = "${WORKDIR}/piracer-cpp/build"

DEPENDS += "cmake pigpio packagegroup-core-buildessential"

inherit cmake

do_configure() {
    mkdir -p ${B}  # build deriectory
    cd ${B}
    cmake ${S} \
        -DCMAKE_INSTALL_PREFIX=${D}/opt/piracer-cpp  # cmake and install dir
}

do_compile() {
    cd ${B}
    oe_runmake  # build make
}

do_install() {
    cd ${B}
    oe_runmake install  # install
}

RDEPENDS:${PN} = " pigpio"
FILES:${PN} = "/opt/piracer-cpp/"


