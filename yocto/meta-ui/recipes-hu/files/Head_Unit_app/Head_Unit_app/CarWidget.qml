import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    id: carWidget
    width: 260
    height: 220
    property bool blinking : true

    AppWidget {
        widthData: parent.width
        heightData: parent.height
        Image {
            id: carImage
            source: "./porsche-91.png"

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
        }

        Image {
            id: leftSignOrigin
            source:"./left_origin.png"

            anchors.top: carImage.bottom
            //anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 40
        }

        Image {
            id: rightSignOrigin
            source: "./right_origin.png"

            anchors.verticalCenter: leftSign.verticalCenter
            anchors.left: leftSign.right
            anchors.leftMargin: 10
        }
        Image {
            id: leftSign
            source: "./left_green.png"
            visible:  (carInfoController.blinkDirection === "left" || carInfoController.blinkDirection === "emergency") && blinking

            anchors.top: carImage.bottom
            anchors.left: parent.left
            anchors.leftMargin: 40
        }

        Image {
            id: rightSign
            source: "./right_green.png"
            visible:  (carInfoController.blinkDirection === "right" || carInfoController.blinkDirection === "emergency" ) && blinking
            anchors.verticalCenter: leftSign.verticalCenter
            anchors.left: leftSign.right
            anchors.leftMargin: 10
        }
        Timer{
            id: blinkTimer
            interval : 500
            repeat: true
            running: true
            onTriggered: {
                blinking = !blinking
            }
        }

        Image {
            id: batteryBar
            source: "./Battery.png"

            anchors.verticalCenter: rightSign.verticalCenter
            anchors.left: rightSign.right
            anchors.leftMargin: 40
        }

        Rectangle {
            id: batteryGauge
            width: (batteryBar.width - 16) * (carInfoController.batteryValue / 100.0)
            height: batteryBar.height - 10
            color: "light green"
            radius: 1

            anchors.left: batteryBar.left
            anchors.leftMargin: 4
            anchors.verticalCenter: batteryBar.verticalCenter
        }

        Text {
            id: batteryNum
            text: carInfoController.batteryValue || "No Data"//carInfoController.batteryLevel + " %"
            anchors.centerIn: batteryBar
            color: "white"
        }
    }

}
