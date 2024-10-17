# piracer_py.bb

SUMMARY = "Clone piracer_py repository"
LICENSE = "CLOSED"
# LIC_FILES_CHKSUM = "file://LICENSE;md5=<LICENSE_MD5_CHECKSUM>"

SRC_URI += "git://github.com/twyleg/piracer_py.git;branch=master;protocol=https \
"
SRC_URI += "file://piracer_venv \
"
SRC_URI += "file://venv \
"

SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git"

inherit gitpkgv

# Optionally, specify any dependencies required for this recipe

DEPENDS = "python3 python3-setuptools bash"

do_install() {
    # Install the cloned files to /home/root/
    install -d ${D}/home/root/piracer-git/examples/piracer_venv
    
    cp -r ${S}/* ${D}/home/root/piracer-git
    cp -r ${WORKDIR}/piracer_venv ${D}/home/root/piracer-git/examples
    cp -r ${WORKDIR}/venv ${D}/home/root/piracer-git/examples
    rm -f ${D}/home/root/piracer-git/scripts/make_release.sh
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/cv2/cv2.abi3.so
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/numpy.libs/libgfortran-daac5196-038a5e3c.so.5.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libQt5Core-4244f2c2.so.5.15.13
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libQt5Gui-b44624ac.so.5.15.13
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libQt5Test-61fb7151.so.5.15.13
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libQt5Widgets-707c612e.so.5.15.13
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libQt5XcbQpa-6e8349c2.so.5.15.13
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libX11-xcb-a0297738.so.1.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libXau-21870672.so.6.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libavcodec-941ea07a.so.59.37.100
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libavformat-1279b9be.so.59.27.100
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libavutil-f0a93969.so.57.28.100
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libgfortran-8634ef04.so.3.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libopenblas-r0-8966572e.3.3.so
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libswresample-39e38dfb.so.4.7.100
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libswscale-86dc6859.so.6.7.100
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-icccm-05fb8c7f.so.4.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-image-75825d2e.so.0.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-keysyms-73cd270d.so.1.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-randr-e1606dfc.so.0.1.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-render-76b15fe5.so.0.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-render-util-486ef3ee.so.0.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-shape-e8fe4bc4.so.0.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-shm-cad72500.so.0.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-sync-dc271c48.so.1.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-util-c74d156a.so.1.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-xfixes-f4cf71d4.so.0.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-xinerama-6372573d.so.0.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxcb-xkb-e2f6f9de.so.1.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxkbcommon-e272a37d.so.0.0.0
    rm -f ${D}/home/root/piracer-git/examples/venv/lib/python3.10/site-packages/opencv_python.libs/libxkbcommon-x11-b76c7d31.so.0.0.0
}

#FILES:${PN} += "${D}"
#FILES:${PN} += "${D}/home/root/piracer-git/"
#FILES:${PN} += "${D}${bindir}/python3.10/"

FILES:${PN} = "/home/root/piracer-git/"


RDEPENDS_${PN} += "python3 python3-setuptools"

