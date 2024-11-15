import QtQuick 2.12
import QtQuick.Controls 2.12

import QtQuick.Window 2.12

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

        Button{
            text: "<-"
            onClicked: lrsignObject.changeLRsign(2)
        }
        Button{
            text: "X"
            onClicked: lrsignObject.changeLRsign(1)
        }
        Button{
            text: "->"
            onClicked: lrsignObject.changeLRsign(3)
        }

    }
}
