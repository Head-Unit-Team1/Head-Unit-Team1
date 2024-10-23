Piracer_package = "pigpio \
		    piracer-cpp \
                   v4l-utils \
                   i2c-tools \
                   piracer-cpp-autoexec \
                   "

Splash_package = "vlc \
		  playvideo \
		  systemd \
		  systemd-compat-units \
		  "

Qt_package = "qtdeclarative \
	      qtdeclarative-tools \
	      qtwebkit \
	      qt5-config \
	      qtbase \
	      qtbase-tools \
	      qtwayland \
	      qtwayland-tools \
	      "
	      
Gstreamer_package = "gstreamer1.0 \
		     gstreamer1.0-plugins-base \
		     gstreamer1.0-plugins-good \
		     "
		     
Wayland_package = "wayland \
		   weston \
		   "


IMAGE_INSTALL:append = " ${Splash_package} \
			${Gstreamer_package} \
			${Wayland_package} \
			${Qt_package} \
			${Piracer_package} \
			"
      
