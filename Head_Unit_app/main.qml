import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

ApplicationWindow {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Head Unit")

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
                anchors.left: parent.left
                anchors.leftMargin: 20
            }

            CarWidget {
                id: car_widget
                anchors.top: info_widget.bottom
                anchors.topMargin: 20
                anchors.left: parent.left
                anchors.leftMargin: 20
            }

            GearWidget {
                id: gear_widget
                anchors.verticalCenter: car_widget.verticalCenter
                anchors.left: car_widget.right
                anchors.leftMargin: 20
            }

            AppWidget {
                id: map_widget
                widthData: 460
                heightData: 460
                anchors.top: parent.top
                anchors.topMargin: 20
                anchors.right: parent.right
                anchors.rightMargin: 20
            }

            Text {
                id: seame
                text: "S\nE\nA\n\nM\nE"
                font.pixelSize: 40
                color: "#A2F2D9"
                lineHeight: 1.5
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.right: map_widget.left
                anchors.rightMargin: 40
                anchors.verticalCenter: map_widget.verticalCenter
            }

            Rectangle {
                id: bottom_bar
                width: 984
                height: 80
                radius: 5
                color: "black"

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20

                layer.enabled: true
                layer.effect: DropShadow {
                    color: "#A2F2D9"
                    radius: 10
                    samples: 16
                    spread: 0.2
                    x: 0
                    y: 1
                    //transparentBorder: true
                }

                Image {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.horizontalCenterOffset: -25
                    anchors.verticalCenter: parent.verticalCenter
                    source: "./icon_menu.png"
                }

                Text{
                    id: timeDisplay
                    text: Clock.currentTime
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 20
                    font.pixelSize: 40
                    color: "#00b890"
                }

                Connections{
                    target: Clock
                    onTimeChanged: timeDisplay.text = Clock.currentTime
                }
            }

/*
            MenuButton {
                menuName: "test"
                anchors.centerIn: parent
            }//*/
        }
    }
}
