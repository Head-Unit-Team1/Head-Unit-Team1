import QtQuick 2.0

Item {
    width: 1024
    height: 40
    Rectangle {
        anchors.fill: parent
        color: "#000000"
    }

    Item {
        width: 200
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 20

        Text {
            id: timeText
            text: Clock.currentTime_short
            font.pixelSize: 20
            color: "#FFFFFF"

            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }

        Connections {
            target: Clock
            onTimeChanged: timeText.text = Clock.currentTime_short
        }

        Item {
            width: 60
            height: parent.height
            anchors.left: timeText.right
            anchors.verticalCenter: parent.verticalCenter

            Rectangle {
                id: battery
                width: 45 * (carInfoController.batteryLevel / 100.0)
                height: 15
                color: "light green"
                radius: 1

                anchors.centerIn: parent
            }

            Text {
                id: batteryText
                text: carInfoController.batteryLevel + "%"
                color: "#FFFFFF"

                anchors.centerIn: battery
            }
        }
    }

}
