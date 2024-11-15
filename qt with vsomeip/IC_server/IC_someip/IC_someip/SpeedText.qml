import QtQuick 2.0

Item {
    id: speedTextComponent
    property int currentSpeed: 0
    property int targetSpeed: 0

    Text{
        id: speedText
        text: Receiver.speedKmh.toFixed(0)
        font.pixelSize: 35
        color: "white"
        anchors.bottom: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        //anchors.centerIn: parent
        font.bold: true

        NumberAnimation{
            id: speedAnimation
            target: speedTextComponent
            property: "currentSpeed"
            to: targetSpeed
            duration: 800
            easing.type: Easing.InOutQuad
        }
    }

    Connections{
        target: Receiver
        onSpeedChanged: {
            speedTextComponent.targetSpeed = Receiver.speedKmh
            speedAnimation.start()
        }
    }

    Text{
        id: speed_scale
        text: "cm/s"
        font.pixelSize: 25
        color: "white"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: speedText.bottom
        anchors.topMargin: 10
    }

}
