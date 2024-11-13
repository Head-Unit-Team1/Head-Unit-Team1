import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    width: 60
    height: 60

    Rectangle {
        anchors.fill: parent
        radius: 40
        color: "#232121"

        layer.enabled: true
        layer.effect: DropShadow {
            color: carInfoController.modeColor//"#A2F2D9"
            radius: 10
            samples: 16
            spread: 0.2
            x: 0
            y: 1
            //transparentBorder: true
        }

        Image {
            source: "./icon_home.png"
            width: 40
            height: 40
            anchors. horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: -5
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            stackView.pop()
        }
    }

}
