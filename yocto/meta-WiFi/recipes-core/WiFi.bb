DESCRIPTION = "Wi-Fi & network configuration"
LICENSE = "CLOSED"

SRC_URI = "file://wpa_supplicant.conf \
	   file://interfaces \
	  "

do_install() {
    install -d ${D}/etc/wpa_supplicant
    install -m 0644 ${WORKDIR}/wpa_supplicant.conf ${D}/etc/wpa_supplicant/wpa_supplicant.conf
    
    install -d ${D}/etc/network
    install -m 0644 ${WORKDIR}/interfaces ${D}/etc/network/interfaces
}

FILES_${PN} += "/etc/wpa_supplicant/wpa_supplicant.conf \
		/etc/network/interfaces \	
		"

