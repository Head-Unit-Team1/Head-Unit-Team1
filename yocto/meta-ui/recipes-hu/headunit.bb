SUMMARY = "Compile HeadUnit qt"
LICENSE = "CLOSED"

SRC_URI = "file://Head_Unit_app"

S = "${WORKDIR}/Head_Unit_app/Head_Unit_app"
B = "${WORKDIR}/build"

DEPENDS += "cmake packagegroup-core-buildessential qtbase qtdeclarative qtwebengine qtmultimedia vsomeip common-api-c++ common-api-c++-someip"

inherit cmake_qt5 cmake

do_install() {
    install -d ${D}/opt/Head_Unit_app/build
    install -d ${D}/opt/Head_Unit_app/json
    install -d ${D}${bindir}

    install -m 0755 ${B}/Head_Unit_app ${D}/opt/Head_Unit_app/build/Head_Unit_app
    install -m 0755 ${B}/libHead_Unit_app-someip.so ${D}/opt/Head_Unit_app/build/libHead_Unit_app-someip.so
    install -m 0755 ${S}/../commonapi4someip.ini ${D}/opt/Head_Unit_app/commonapi4someip.ini
    install -m 0755 ${S}/../hu.sh ${D}${bindir}/hu
    install -m 0755 ${S}/../json/HU.json ${D}/opt/Head_Unit_app/json/HU.json
}

FILES:${PN} = "/opt/Head_Unit_app/ \
               ${bindir}/hu \
               "

RDEPENDS:${PN} += "qtwebengine python3-mutagen"
