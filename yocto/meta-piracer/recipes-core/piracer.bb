SUMMARY = "PiRacer Python Script"
LICENSE = "CLOSED"

#LICENSE = "MIT"
#LIC_FILES_CHKSUM = "file://LICENSE;md5=<hash>"

SRC_URI = "file://basic_example.py \
	   file://rc_example.py \
	   git://github.com/SEA-ME/piracer_py.git;protocol=https \
	   "
SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git" 

DEPENDS = "python3 python3-setuptools"

do_install() {
    install -d ${D}${bindir}/piracer_venv
    python3 -m venv ${D}${bindir}/piracer_venv
    
    . ${D}${bindir}/piracer_venv/bin/activate
    pip3 install piracer-py

    install -d ${D}${bindir}/piracer
    cp -r ${S}/*.py ${D}${bindir}/piracer/
    
    install -m 0755 ${WORKDIR}/basic_example.py ${D}${bindir}/basic_example.py
    install -m 0755 ${WORKDIR}/rc_example.py ${D}${bindir}/rc_example.py
}


IMAGE_INSTALL += "python3 python3-pip"

RDEPENDS_${PN} = "python3 python3-setuptools"
