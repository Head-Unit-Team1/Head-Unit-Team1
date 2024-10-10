SUMMARY = "PiRacer Python Script"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=<hash>"

SRC_URI = "file://main.py"

# 파이썬과 PiRacer 라이브러리 설치
DEPENDS = "python3 python3-pip"

do_install() {
    # main.py를 설치할 위치를 지정
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/main.py ${D}${bindir}/piracer.py
}

# Python이 시스템에서 사용할 수 있도록 이미지에 추가
IMAGE_INSTALL += "python3 python3-pip"

