SUMMARY = "PiRacer Python Script"
LICENSE = "CLOSED"

#LICENSE = "MIT"
#LIC_FILES_CHKSUM = "file://LICENSE;md5=<hash>"

SRC_URI = "file://main.py"
SRC_URI = "git://github.com/SEA-ME/piracer_py.git;protocol=https"
SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git" 

DEPENDS = "python3 python3-venv python3-setuptools opencv"

do_install() {
    install -d ${D}${bindir}/piracer_venv
    python3 -m venv ${D}${bindir}/piracer_venv
    
    . ${D}${bindir}/piracer_venv/bin/activate
    pip install piracer-py

    install -d ${D}${bindir}/piracer
    cp -r ${S}/*.py ${D}${bindir}/piracer/
}

IMAGE_INSTALL += "python3 python3-pip"

RDEPENDS_${PN} = "python3 python3-venv python3-setuptools"
