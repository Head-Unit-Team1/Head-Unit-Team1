import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0


Item {
    property int widthData: 200
    property int heightData: 120

    width: widthData
    height: heightData

    Rectangle {
        id: widget_comp
        width: parent.width
        height: parent.height
        color: "#232121"
        radius: 5

        layer.enabled: true
        layer.effect: DropShadow {
            color: carInfoController.modeColor//"#A2F2D9"
            radius: 10
            samples: 16
            spread: 0.2
            x: 0
            y: 1
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("Widget clicked!");
            }
        }
    }
}
