SUMMARY = "Clone piracer-cpp repository"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=33a2ac025994ad1ea98eb2e01c1c8df3"

SRC_URI = "file://piracer-cpp"
S = "${WORKDIR}/piracer-cpp"

inherit cmake

# Optionally, specify any dependencies required for this recipe

DEPENDS += "cmake pigpio"

do_install() {
    # Install the cloned files to /home/root/
    install -d ${D}/home/root/piracer-git
    
    cp -r ${S}/* ${D}/home/root/piracer-git


}

#FILES:${PN} += "${D}"
#FILES:${PN} += "${D}/home/root/piracer-git/"
#FILES:${PN} += "${D}${bindir}/python3.10/"

FILES:${PN} = "/home/root/piracer-git/"


RDEPENDS_${PN} += "python3 python3-setuptools"

