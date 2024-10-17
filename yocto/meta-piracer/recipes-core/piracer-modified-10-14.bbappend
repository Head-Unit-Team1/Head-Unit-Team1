DESCRIPTION = "Run Python script inside a virtual environment at boot"
LICENSE = "CLOSED"
PR = "r0"

SRC_URI = "file://run-script.sh \
           file://my-python-script.service"

# 시스템 서비스로 등록
SYSTEMD_SERVICE_${PN} = "my-python-script.service"

do_install() {
    # 스크립트를 설치할 디렉토리를 만듭니다
    install -d ${D}${bindir}/scripts
    install -m 0755 ${WORKDIR}/run-script.sh ${D}${bindir}/scripts/

    # systemd 서비스 파일을 설치
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${WORKDIR}/my-python-script.service ${D}${systemd_system_unitdir}/
}

# 시스템 서비스 자동 시작 설정
inherit systemd
SYSTEMD_AUTO_ENABLE = "enable"


