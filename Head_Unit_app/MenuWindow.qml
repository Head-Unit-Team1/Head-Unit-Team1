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

    Flickable {
        id: menuSlide
        width: 800
        height: 400
        contentWidth: contentItem.width
        contentHeight: contentItem.height
        clip: true

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset:  -15

        Rectangle {
            id:contentItem
            width: menuButtons.width
            height: parent.height
            color: "transparent"

            Row {
                id: menuButtons
                spacing: 30
                anchors.verticalCenter: parent.verticalCenter

                MenuButton {
                    id: musicB
                    menuName: "Music"
                    imgSource: "./img_music.jpg"
                }

                MenuButton {
                    id: mapB
                    menuName: "Map"
                    imgSource: "./img_map.jpg"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            stackView.push("qrc:/MapApplication.qml")
                            mainWindow.showMenu = false
                        }
                    }
                }

                MenuButton {
                    id: drivingB
                    menuName: "Driving Mode"
                    imgSource: "./img_driving_mode.jpg"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            stackView.push("qrc:/DrivingModeApplication.qml")
                            mainWindow.showMenu = false
                        }
                    }
                }

                MenuButton {
                    id: weatherB
                    menuName: "Weather"
                    imgSource: "./img_weather.jpg"
                }

                MenuButton {
                    id: videoB
                    menuName: "Video"
                    imgSource: "./img_video.jpg"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            stackView.push("qrc:/VideoApplication.qml")
                            mainWindow.showMenu = false
                        }
                    }
                }
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            mainWindow.showMenu = false
        }
        z: -1
    }
}
