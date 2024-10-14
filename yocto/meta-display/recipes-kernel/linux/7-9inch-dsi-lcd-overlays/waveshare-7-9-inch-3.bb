SUMMARY = "Waveshare 7.9 inch DSI LCD Main Script"
LICENSE = "CLOSED"

# Required packages and tools
DEPENDS = "virtual/kernel"

# Clone the repository
SRC_URI = "git://github.com/waveshare/7.9inch-DSI-LCD.git;protocol=https;branch=main"
SRCREV = "${AUTOREV}"

inherit allarch

S = "${WORKDIR}/git"

do_install() {
    # 경로 확인 로그 추가
    echo "Current source directory: ${S}"
    echo "Files in source directory:"
    ls ${S}

    # 설치 디렉토리 생성
    install -d ${D}${bindir}

    # .sh 스크립트 복사 및 설치
    install -m 0755 ${S}/64/5.15.32/pi4/WS_7_9inchDSI400x1280.sh ${D}${bindir}/WS_7_9inchDSI400x1280.sh

}


FILES_${PN} += "${bindir}/WS_7_9inchDSI400x1280.sh"

