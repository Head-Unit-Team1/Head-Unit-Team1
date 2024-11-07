SUMMARY = "Headunit Qt application"
DESCRIPTION = "A Qt-based Headunit application"
LICENSE = "CLOSED"

SRC_URI = "file://Head_Unit_app"

inherit cmake_qt5

DEPENDS = "qtbase qtdeclarative qtwebengine qtnetworkauth"

CMAKE_INSTALL_PREFIX = "/usr/local"

do_install() {
    # 빌드 후 CMake에서 지정한 경로로 설치가 이루어집니다.
    # 필요에 따라 설치 디렉토리 구조를 조정할 수 있습니다.
    install -d ${D}${bindir}
    cmake_do_install
}

FILES_${PN} = "${bindir}/Headunit"

EXTRA_OECMAKE = " \
    -DCMAKE_INSTALL_PREFIX=${prefix} \
    -DQT_QPA_PLATFORM=wayland \
"
