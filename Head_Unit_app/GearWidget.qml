import QtQuick 2.0

Item {
    id: gearWidget
    width: 120
    height: 220

    AppWidget {
        widthData: parent.width
        heightData: parent.height
        anchors.verticalCenter: car_info_widget.verticalCenter
        anchors.left: car_info_widget.right
        anchors.leftMargin: 20

        Text {
            text: "Gear"
            font.pixelSize: 25
            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 30
        }
    }

}
