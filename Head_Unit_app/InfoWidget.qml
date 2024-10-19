import QtQuick 2.0

Item {
    id: infoWidget
    width: 400
    height: 220

    AppWidget {
        widthData: parent.width
        heightData: parent.height
        /*
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20//*/

        Text{
            id: time_info
            text: Clock.currentTime_short
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.pixelSize: 40
            color: "#00b890"
        }

        Connections{
            target: Clock
            onTimeChanged: time_info.text = Clock.currentTime_short
        }

        Text{
            id: date_info
            text: Clock.today_date
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.pixelSize: 25
            color: "#00b890"
        }

        Connections{
            target: Clock
            onTimeChanged: date_info.text = Clock.today_date
        }

        Item {
            width: 120
            height: 180

            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 10

            Text {
                id: region
                text: "Wolfsburg"
                font.pixelSize: 25
                color: "white"

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 10

                Component.onCompleted: {
                        weather.fetchWeatherData(region.text)
                    }
            }
            Image {
                id: weatherImage
                width: 100
                height: 100
                visible: false
                fillMode: Image.PreserveAspectFit

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: region.bottom
                anchors.topMargin: 20
            }

            Text {
                id: tempInfo

                font.pixelSize: 25
                color: "white"

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
            }

            Connections {
                target: weather

                function onWeatherDataReceived(cityName, temperature, weatherDescription, iconPath) {
                    weatherImage.source = iconPath
                    weatherImage.visible = true
                    tempInfo.text = temperature + " °C"
                }
/*
                onWeatherDataReceived: {
                    var imagePath = "file://" + Qt.resolvedUrl(iconPath)
                    weatherImage.source = imagePath
                    weatherImage.visible = true
                    tempInfo.text = temperature
                }//*/
            }
        }
    }
}
