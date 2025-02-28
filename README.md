# Head-Unit-Team1

## Introduction

This project aims to develop a Head Unit Qt application running on a Raspberry Pi (RPi) alongside the previously developed PiRacer Instrument Cluster Qt application. The Head Unit application will provide additional features like ambient lighting, gear selection, and a media app. The project will use Yocto as the build system for the RPi.

## Architecture
![Image](https://github.com/user-attachments/assets/ed6f1850-9fea-42de-a976-c2dce14875a3)

## Custom OS
<details open>
<summary>Install</summary>

```bash
git clone https://github.com/Head-Unit-Team1/Head-Unit-Team1.git
```

</details>

<details open>
<summary>Usage</summary>

### Common

Set your wifi data in `wpa_supplicant.conf-sane`:

```plaintext
...
network={
    ssid="Your Wifi"
    psk="Your password"
    key_mgmt=Your Authentication
}
```

`wpa_supplicant.conf-sane` is in 'Head-Unit-Team1/yocto/poky/meta/recipes-connectivity/wpa-supplicant/wpa-supplicant/'

### Head Unit

* How to bitbake
```bash
cd Head-Unit-Team1/yocto/
source poky/oe-init-build-env
bitbake head-unit-image
```

### Instrument Cluster

* Edit Some File
Edit sleep command in `weston.service`:  
Before:
```plaintext
# After splash video
After=getty@tty1.service
After=videoplay.service

[Service]
Type=idle
EnvironmentFile=/etc/default/weston
ExecStartPre=/bin/sleep 16.1
ExecStart=-/usr/bin/weston --continue-without-input --modules=systemd-notify.so --shell=kiosk-shell.so
```

After:
```plaintext
# After splash video
# After=getty@tty1.service
# After=videoplay.service

[Service]
Type=idle
EnvironmentFile=/etc/default/weston
# ExecStartPre=/bin/sleep 16.1
ExecStart=-/usr/bin/weston --continue-without-input --modules=systemd-notify.so --shell=kiosk-shell.so
```
`weston.service` is in 'Head-Unit-Team1/yocto/poky/meta/recipes-graphics/wayland/weston-init/'

* How to bitbake
```bash
cd Head-Unit-Team1/yocto/
source poky/oe-init-build-env
bitbake instrument-cluster-image
```

</details>

## Communication
### SOME/IP
In order to process today's massive vehicle data, CAN alone is not enough. That's why we're supplementing that part with the Scalable service-Oriented Middleware over IP(SOME/IP). We implemented the communication between the 'IC' and the 'GamePad' application internally, and the communication between the 'IC' and the 'HU' externally. This wireless external communication allowed us to control the vehicle through the Head Unit device, away from the PiRacer.

- Service Discovery
  Service Discovery is a mediator that enables communication with only the necessary method information even if the server and client don't know each other. We can use data from other apllications through simple rules.
 
- CommonAPI
  CommonAPI provides the best environment for implementing SOME/IP. We can get automatically generated code by simply writing files that define services and methods. Thanks to the method through abstraction, it was easy to implement proxies and stubs for communication. We also built a network that solved the problem of delayed response by implementing asynchronous communication.

## Functions
### Music Application
![Image](https://github.com/user-attachments/assets/39442a16-ea7e-4e56-a98a-3b774704ffa4)
This application scans USB storage for MP3 files and displays them in a list. Using the 'mutagen' library, it filters out non-MP3 files. Passengers can listen to their own playlists through this feature.

### Map, Weather, Youtube Application
![Image](https://github.com/user-attachments/assets/13ed9b87-521e-4685-ba66-355eda28611a)
These applications use APIs to provide their functionality.
- Map Application: Uses the Google Maps API to display simple images and information about locations.
- Weather Application: Uses the OpenWeatherMap API to provide real-time weather updates and a five-day forecast for any searched location.
- YouTube Application: Uses the YouTube API to display the top five videos.

To use these features, you need to enter your own API keys in the appropriate configuration files.

### Screen Saver, Gear Selection, Driving Mode
![Image](https://github.com/user-attachments/assets/98ea30e4-5560-4833-a507-0c0578413e8e)
These functions communicate with the Instrument Cluster (IC) application through external SOME/IP. The Head Unit (HU) application is synchronized with the IC application and displays the same data.
- Screen Saver: After activating the HU application, users can access all vehicle functions, including driving. By touching the HU's initial screen, users can interact with the car's system.
- Gear Selection: The gear data is synchronized across the HU, IC, and GamePad applications. Even if users change gears using the HU or GamePad, the system ensures that the same data is displayed on all screens.
- Driving Mode: Passengers can select from three driving modes: Normal, Sport, and Simple. This selection is also applied to the IC application. Additionally, this feature provides ambient lighting effects for passengers.

## Developers
### <div align="center">Application & Network Developers</div>
<table align="center">

  <tr>
    <td align="center">
      <a href="https://github.com/jwoon0906">
        <img src="https://github.com/jwoon0906.png" width="150px;" alt="Jang-Woon Park"/>
        <br />
        <sub><b>Jang-Woon Park</b></sub>
      </a>
      <br />
      <a href="https://github.com/jwoon0906"><img src="https://img.shields.io/badge/GitHub-jwoon0906-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/YEOHANBIN">
        <img src="https://github.com/YEOHANBIN.png" width="150px;" alt="Han-Bin Yeo"/>
        <br />
        <sub><b>Han-Bin Yeo</b></sub>
      </a>
      <br />
      <a href="https://github.com/YEOHANBIN"><img src="https://img.shields.io/badge/GitHub-YEOHANBIN-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    
  </tr>
</table>

### <div align="center">Yocto Developers</div>
<table align="center">

  <tr>
    <td align="center">
      <a href="https://github.com/euiseok-shin">
        <img src="https://github.com/euiseok-shin.png" width="150px;" alt="Eui-Seok Shin"/>
        <br />
        <sub><b>Eui-Seok Shin</b></sub>
      </a>
      <br />
      <a href="https://github.com/euiseok-shin"><img src="https://img.shields.io/badge/GitHub-euiseokshin-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/KunhoPark-Jason">
        <img src="https://github.com/KunhoPark-Jason.png" width="150px;" alt="Kun-Ho Park"/>
        <br />
        <sub><b>Kun-Ho Park</b></sub>
      </a>
      <br />
      <a href="https://github.com/KunhoPark-Jason"><img src="https://img.shields.io/badge/GitHub-KunhoParkJason-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    <td align="center">
      <a href="https://github.com/junspring">
        <img src="https://github.com/junspring.png" width="150px;" alt="Jun-Beom Jung"/>
        <br />
        <sub><b>Jun-Beom Jung</b></sub>
      </a>
      <br />
      <a href="https://github.com/junspring"><img src="https://img.shields.io/badge/GitHub-junspring-blue?logo=github" alt="GitHub Badge" /></a>
      <br />
    </td>
    
  </tr>
</table>
