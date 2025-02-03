# Head-Unit-Team1

## Introduction

This project aims to develop a Head Unit Qt application running on a Raspberry Pi (RPi) alongside the previously developed PiRacer Instrument Cluster Qt application. The Head Unit application will provide additional features like ambient lighting, gear selection, and a media app. The project will use Yocto as the build system for the RPi.

## Architecture
![Image](https://github.com/user-attachments/assets/ed6f1850-9fea-42de-a976-c2dce14875a3)

## Custom OS


## Communication


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