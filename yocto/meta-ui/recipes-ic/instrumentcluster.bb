SUMMARY = "Compile IC_someip qt"
LICENSE = "CLOSED"

SRC_URI = "file://IC_someip"

S = "${WORKDIR}/IC_someip/IC_someip"
B = "${WORKDIR}/build"


# 의존성 추가
DEPENDS += "cmake packagegroup-core-buildessential qtbase qtdeclarative vsomeip common-api-c++ common-api-c++-someip qtsvg"

# cmake_qt5 클래스 상속
inherit cmake_qt5 cmake

# do_install에서 소스 및 빌드 폴더 복사
do_install() {
    # 소스와 빌드 폴더를 최종 이미지에 포함
    install -d ${D}/opt/IC_someip/build
    install -d ${D}/opt/IC_someip/json
    
    install -m 0755 ${B}/IC_someip ${D}/opt/IC_someip/build/IC_someip
    install -m 0755 ${B}/libIC_someip-someip.so ${D}/opt/IC_someip/build/libIC_someip-someip.so
    install -m 0755 ${S}/../commonapi4someip.ini ${D}/opt/IC_someip/commonapi4someip.ini
    install -m 0755 ${S}/../ic.sh ${D}/opt/IC_someip/ic.sh
    install -m 0755 ${S}/../json/IC.json ${D}/opt/IC_someip/json/IC.json
    install -m 0755 ${S}/../json/change_ip.py ${D}/opt/IC_someip/json/change_ip.py
    install -m 0755 ${S}/../json/set_ip.sh ${D}/opt/IC_someip/json/set_ip.sh
}

FILES:${PN} = "/opt/IC_someip/"

RDEPENDS:${PN} += "qtsvg python3-netifaces can-utils canutils"

