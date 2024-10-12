# meta-team1/recipes-bsp/rpi-boot-config/rpi-boot-config.bb

DESCRIPTION = "Raspberry Pi boot configuration files"
LICENSE = "CLOSED"

SRC_URI = "file://config.txt \
           file://cmdline.txt"

S = "${WORKDIR}"

do_install() {
    install -d ${D}/boot

    if [ -e ${D}/boot/config.txt ]; then
        cat ${WORKDIR}/config.txt >> ${D}/boot/config.txt
    else
        install -m 0644 ${WORKDIR}/config.txt ${D}/boot/config.txt
    fi

    if [ -e ${D}/boot/cmdline.txt ]; then
        cat ${WORKDIR}/cmdline.txt >> ${D}/boot/cmdline.txt
    else
        install -m 0644 ${WORKDIR}/cmdline.txt ${D}/boot/cmdline.txt
    fi
}

FILES_${PN} += " \
  /boot/config.txt \
  /boot/cmdline.txt \
  /boot \
"

