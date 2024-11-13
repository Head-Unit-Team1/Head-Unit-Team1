Piracer_package = "pigpio \
		   v4l-utils \
		   i2c-tools \
		   piracer-vsomeip \
		   can0up-autoexec \
                  "

Splash_package = "vlc \
		  playvideo \
		  systemd \
		  systemd-compat-units \
		  "

Qt_package = "qtdeclarative \
	      qtdeclarative-tools \
	      qt5-config \
	      qtbase \
	      qtbase-tools \
	      qtbase-plugins \
	      qtquickcontrols2 \
	      qtquickcontrols2-mkspecs \
	      ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtgraphicaleffects-qmlplugins', '', d)} \
	      qtwayland \
	      "
	            
Gstreamer_package = "gstreamer1.0 \
		     gstreamer1.0-plugins-base \
		     gstreamer1.0-plugins-good \
		     "
		     
Wayland_package = "wayland \
		   weston \
		   "

Someip_package = "vsomeip \ 
		  common-api-c++ \ 
		  common-api-c++-someip \
		  "

UI_package = "instrumentcluster \
              "

Wifi_package = "wpa-supplicant \
               wifi-connect-autoexec \
               "
               
# ${Qt_package}

IMAGE_INSTALL:append = " ${Splash_package} \
			${Gstreamer_package} \
			${Piracer_package} \
			${Someip_package} \
			${UI_package} \
			${Qt_package} \
			${Wifi_package} \
			${Wayland_package} \
			"
      
