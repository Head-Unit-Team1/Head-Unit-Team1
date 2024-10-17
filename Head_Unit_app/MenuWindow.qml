import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    id: menuWindow
    visible: showMenu
    color: "transparent"
    anchors.fill: parent
/*
    Rectangle {
        width: 1024
        height: 550
        //color: "rgba(255, 255, 255, 0.5)"
    }//*/

    MenuButton {
        id: musicB
        menuName: "Music"
        imgSource: "./img_music.jpg"

        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset:  -25
        anchors.left: parent.left
        anchors.leftMargin: 100
    }

    MenuButton {
        id: mapB
        menuName: "Map"
        imgSource: "./img_map.jpg"

        anchors.verticalCenter: musicB.verticalCenter
        anchors.left: musicB.right
        anchors.leftMargin: 30
    }

    MenuButton {
        id: drivingB
        menuName: "Driving Mode"
        imgSource: "./img_driving_mode.jpg"

        anchors.verticalCenter: musicB.verticalCenter
        anchors.left: mapB.right
        anchors.leftMargin: 30
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            mainWindow.showMenu = false
        }
        z: -1
    }

}
