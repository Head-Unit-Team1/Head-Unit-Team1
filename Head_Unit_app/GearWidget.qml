import QtQuick 2.0

Item {
    id: gearWidget
    width: 120
    height: 220

    AppWidget {
        widthData: parent.width
        heightData: parent.height

        Text {
            id: gear_sub
            text: "Gear"
            font.pixelSize: 25
            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 30
        }

        Text {
            id: gearLevel
            font.pixelSize: 50
            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: gear_sub.bottom
            anchors.topMargin: 40

            text: gearController.selectedButton
        }

        Connections {
            target: gearController
            onSelectedButtonChanged: {
                gearLevel.text = gearController.selectedButton;
            }
        }
    }

}
