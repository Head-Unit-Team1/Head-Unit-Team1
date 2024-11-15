# <div align="center">Documentation</div>

<details open>
<summary>Install</summary>

```bash
git clone https://github.com/Head-Unit-Team1/Head-Unit-Team1.git
```

</details>

<details open>
<summary>Usage</summary>

## Common

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

## Head Unit

### How to bitbake
```bash
cd Head-Unit-Team1/yocto/
source poky/oe-init-build-env
bitbake head-unit-image
```

## Instrument Cluster

### Edit Some File
Edit sleep command in `weston.service`:  
Before:
```plaintext
[Service]
Type=idle
EnvironmentFile=/etc/default/weston
ExecStartPre=/bin/sleep 16.1
ExecStart=-/usr/bin/weston --continue-without-input --modules=systemd-notify.so --shell=kiosk-shell.so
```

After:
```plaintext
[Service]
Type=idle
EnvironmentFile=/etc/default/weston
# ExecStartPre=/bin/sleep 16.1
ExecStart=-/usr/bin/weston --continue-without-input --modules=systemd-notify.so --shell=kiosk-shell.so
```
`weston.service` is in 'Head-Unit-Team1/yocto/poky/meta/recipes-graphics/wayland/weston-init/'

### How to bitbake
```bash
cd Head-Unit-Team1/yocto/
source poky/oe-init-build-env
bitbake instrument-cluster-image
```

</details>

# <div align="center">Developers</div>
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