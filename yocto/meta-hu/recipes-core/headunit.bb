SUMMARY = "Compile HeadUnit qt"

LICENSE = "CLOSED"

SRC_URI = "file://Head_Unit_app"

S = "${WORKDIR}/Head_Unit_app"

B = "${WORKDIR}/Head_Unit_app/build"

DEPENDS += "cmake packagegroup-core-buildessential qtbase qtdeclarative qtwebengine"

inherit cmake_qt5 cmake

# do_install에서 소스 및 빌드 폴더 복사
do_install() {
    # 소스와 빌드 폴더를 최종 이미지에 포함
    install -d ${D}/opt/Head_Unit_app/build
    
    install -m 0755 ${B}/Head_Unit_app ${D}/opt/Head_Unit_app/build/Head_Unit_app

}

FILES:${PN} = "/opt/Head_Unit_app/"

RDEPENDS:${PN} += ""


