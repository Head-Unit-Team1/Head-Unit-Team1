import QtQuick 2.0

Item {
    id: drivingModeApplication
    width: 1024
    height: 600

    TopBar {
        id: topBar
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Row {
        spacing: 30
        anchors.centerIn: parent

        AppWidget {
            id: normalMode
            widthData: 250
            heightData: 250

            Image {
                source: "./normal_mode.jpg"
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
            }

            Text {
                text: "NORMAL"
                anchors.centerIn: parent
                font.pixelSize: 50
                font.bold: true
                color: "white"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    carInfoController.setModeColor("#A2F2D9")
                }
            }
        }

        AppWidget {
            id: sportsMode
            widthData: 250
            heightData: 250

            Image {
                source: "./sports_mode.jpg"
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
            }

            Text {
                text: "SPORTS"
                anchors.centerIn: parent
                font.pixelSize: 50
                font.bold: true
                color: "white"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    carInfoController.setModeColor("red")
                }
            }
        }

        AppWidget {
            id: simpleMode
            widthData: 250
            heightData: 250

            Image {
                source: "./simple_mode.jpg"
                anchors.fill: parent
                fillMode: Image.PreserveAspectCrop
            }

            Text {
                text: "SIMPLE"
                anchors.centerIn: parent
                font.pixelSize: 50
                font.bold: true
                color: "white"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    carInfoController.setModeColor("white")
                }
            }
        }
    }

    HomeWidget {
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }
}
