import QtQuick 2.0

Item {
    id: carWidget
    width: 260
    height: 220

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
            id: leftSign
            source: "./left_origin.png"

            anchors.top: carImage.bottom
            //anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 40
        }

        Image {
            id: rightSign
            source: "./right_green.png"

            anchors.verticalCenter: leftSign.verticalCenter
            anchors.left: leftSign.right
            anchors.leftMargin: 10
        }

        Image {
            id: batteryBar
            source: "./Battery.png"

            anchors.verticalCenter: rightSign.verticalCenter
            anchors.left: rightSign.right
            anchors.leftMargin: 40
        }

    }

}
