import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Column{
        anchors.centerIn: parent
        Button{
            text: "Park"
            onClicked: gearObject.changeGear("P")
        }
        Button{
            text: "Neutral"
            onClicked: gearObject.changeGear("N")
        }
        Button{
            text: "Drive"
            onClicked: gearObject.changeGear("D")
        }
        Text{
            text: "current gear: " + gearObject.gearValue
            font.pointSize: 20
        }
    }
    Button{
        text: "batteryGet"
        onClicked: batteryObject.getBattery()
    }
    Text{
        font.pointSize: 40
        text: "battery: " + batteryObject.batteryValue
    }
}
