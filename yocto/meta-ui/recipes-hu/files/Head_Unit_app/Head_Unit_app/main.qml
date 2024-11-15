import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

ApplicationWindow {
    id: mainWindow
    width: 1024
    height: 600
    visible: true
    title: qsTr("Head Unit")

    property bool showGearBox: false
    property bool showMenu: false

    Image {
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        source: "./dark-blue-product-background.jpg"
    }


    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: Item {
            InfoWidget {
                id: info_widget
                anchors.top: parent.top
                anchors.topMargin: 20
                anchors.left: map_widget.right
                anchors.leftMargin: 20
            }

            CarWidget {
                id: car_widget
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                anchors.left: map_widget.right
                anchors.leftMargin: 20
            }

            GearWidget {
                id: gear_widget
                anchors.verticalCenter: car_widget.verticalCenter
                anchors.left: car_widget.right
                anchors.leftMargin: 20

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mainWindow.showGearBox = true;
                    }
                }
            }

            MapWidget {
                id: map_widget
                anchors.left: side_bar.right
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        stackView.push("qrc:/MapApplication.qml")
                    }
                }
            }

            Text {
                id: seame
                text: "S     E     A     M     E"
                font.pixelSize: 30
                color: carInfoController.modeColor
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.top: info_widget.bottom
                anchors.topMargin: 40
                anchors.horizontalCenter: info_widget.horizontalCenter
            }

            Rectangle {
                id: side_bar
                width: 80
                height: 560
                radius: 5
                color: "black"

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 20

                layer.enabled: true
                layer.effect: DropShadow {
                    color: carInfoController.modeColor
                    radius: 10
                    samples: 16
                    spread: 0.2
                    x: 0
                    y: 1
                }

                Image {
                    id: icon_music
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 40
                    source: "./icon_music.png"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            stackView.push("qrc:/MusicApplication.qml")
                        }
                    }
                }

                Image {
                    id: icon_youtube
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: icon_music.bottom
                    anchors.topMargin: 40
                    source: "./icon_youtube.png"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            stackView.push("qrc:/VideoApplication.qml")
                        }
                    }
                }

                Image {
                    id: icon_mode
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: icon_youtube.bottom
                    anchors.topMargin: 40
                    source: "./icon_mode.png"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            stackView.push("qrc:/DrivingModeApplication.qml")
                        }
                    }
                }

                Image {
                    width: parent.width * 0.5
                    height: width
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 20
                    source: "./icon_menu.png"
                    opacity: carInfoController.modeColor === "#A2F2D9" ? 1 : 0

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            mainWindow.showMenu = true;
                        }
                    }
                }

                Image {
                    width: parent.width * 0.5
                    height: width
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 20
                    source: "./icon_menu2.png"
                    opacity: carInfoController.modeColor === "red" ? 1 : 0

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            mainWindow.showMenu = true;
                        }
                    }
                }

                Image {
                    width: parent.width * 0.5
                    height: width
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 20
                    source: "./icon_menu3.png"
                    opacity: carInfoController.modeColor === "white" ? 1 : 0

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            mainWindow.showMenu = true;
                        }
                    }
                }
            }
        }
    }

    GearBoxWindow {
        visible: showGearBox
    }

    MenuWindow {
        visible: showMenu
    }

    StartScreen {
        id: startScreen
        anchors.centerIn: parent
    }
}
