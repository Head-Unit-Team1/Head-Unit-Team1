# piracer_py.bb

SUMMARY = "Clone piracer_py repository"
LICENSE = "CLOSED"
# LIC_FILES_CHKSUM = "file://LICENSE;md5=<LICENSE_MD5_CHECKSUM>"

SRC_URI += "git://github.com/twyleg/piracer_py.git;branch=master;protocol=https \
"

#SRC_URI += "file://master.zip \
#"

SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git"

inherit gitpkgv

# Optionally, specify any dependencies required for this recipe

DEPENDS = "python3 python3-setuptools bash"

do_install() {
    # Install the cloned files to /home/root/
    install -d ${D}/home/root/piracer-git/
    
    cp -r ${S}/* ${D}/home/root/piracer-git
    cp -r ${WORKDIR}/master.zip ${D}/home/root/piracer-git
    rm -f ${D}/home/root/piracer-git/scripts/make_release.sh
    
}

FILES:${PN} = "/home/root/piracer-git/"


RDEPENDS_${PN} += "python3 python3-setuptools"

