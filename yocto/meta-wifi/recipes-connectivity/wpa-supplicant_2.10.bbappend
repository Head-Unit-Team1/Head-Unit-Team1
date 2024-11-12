FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

do_install:append() {
    install -Dm 0644 ${WORKDIR}/wpa_supplicant.conf ${D}${sysconfdir}/wpa_supplicant.conf
}

