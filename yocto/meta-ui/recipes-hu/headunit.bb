SUMMARY = "Compile HeadUnit qt"
LICENSE = "CLOSED"

SRC_URI = "file://Head_Unit_app"

S = "${WORKDIR}/Head_Unit_app/Head_Unit_app"
B = "${WORKDIR}/build"

DEPENDS += "cmake packagegroup-core-buildessential qtbase qtdeclarative qtwebengine"

inherit cmake_qt5 cmake

do_install() {
    install -d ${D}/opt/Head_Unit_app/build
    install -d ${D}${bindir}
    
    install -m 0755 ${B}/Head_Unit_app ${D}/opt/Head_Unit_app/build/Head_Unit_app
    install -m 0755 ${S}/../hu.sh ${D}${bindir}/hu
}

FILES:${PN} = "/opt/Head_Unit_app/ \
               ${bindir}/hu \
               "

RDEPENDS:${PN} += "qtwebengine"
