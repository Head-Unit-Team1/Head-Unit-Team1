SUMMARY = "PiRacer Python Script"
LICENSE = "CLOSED"

#LICENSE = "MIT"
#LIC_FILES_CHKSUM = "file://LICENSE;md5=<hash>"

SRC_URI = "file://main.py"

DEPENDS = "python3 python3-pip"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/main.py ${D}${bindir}/piracer.py
}

IMAGE_INSTALL += "python3 python3-pip"

RDEPENDS_${PN} = "python3"
