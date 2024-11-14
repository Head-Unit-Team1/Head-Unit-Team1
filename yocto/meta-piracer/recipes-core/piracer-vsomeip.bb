SUMMARY = "Clone piracer-cpp repository And Build"

LICENSE = "CLOSED"
#LIC_FILES_CHKSUM = "file://LICENSE;md5=33a2ac025994ad1ea98eb2e01c1c8df3"

SRC_URI = "file://piracer_vsomeip"

S = "${WORKDIR}/piracer_vsomeip/piracer_vsomeip"

B = "${WORKDIR}/build"

DEPENDS += "cmake pigpio packagegroup-core-buildessential vsomeip common-api-c++ common-api-c++-someip"

inherit cmake

do_install() {
    # 소스와 빌드 폴더를 최종 이미지에 포함
    install -d ${D}/opt/piracer_vsomeip/build
    install -d ${D}/opt/piracer_vsomeip/json
    install -d ${D}${bindir}
    
    install -m 0755 ${B}/gamepad_control ${D}/opt/piracer_vsomeip/build/gamepad_control
    install -m 0755 ${B}/libgamepad_control-someip.so ${D}/opt/piracer_vsomeip/build/libgamepad_control-someip.so
    install -m 0755 ${S}/../commonapi4someip.ini ${D}/opt/piracer_vsomeip/commonapi4someip.ini
    install -m 0755 ${S}/../gamepad.sh ${D}${bindir}/gamepad
    install -m 0755 ${S}/../json/IC.json ${D}/opt/piracer_vsomeip/json/IC.json
}

RDEPENDS:${PN} = " pigpio"
FILES:${PN} += "/opt/piracer_vsomeip/"
FILES:${PN} += "/usr/bin/"

