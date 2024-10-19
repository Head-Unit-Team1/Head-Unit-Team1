SUMMARY = "Clone piracer-cpp repository"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=33a2ac025994ad1ea98eb2e01c1c8df3"


#SRCREV = "${AUTOREV}"

SRC_URI = "file://piracer-cpp"
S = "${WORKDIR}/piracer-cpp"

DEPENDS += "cmake pigpio"

inherit cmake

B = "${WORKDIR}/build"

do_configure() {
    mkdir -p ${B}  # 빌드 디렉토리 생성
    cd ${B}
    cmake ${S} \
        -DCMAKE_INSTALL_PREFIX=${D}/opt/piracer-cpp  # 설치 경로 설정
}

do_compile() {
    cd ${B}
    oe_runmake  # 빌드 수행
}

do_install() {
    cd ${B}
    oe_runmake install  # 설치 수행
}


RDEPENDS:${PN} = "cmake pigpio"
FILES:${PN} = "/opt/piracer-cpp/"

