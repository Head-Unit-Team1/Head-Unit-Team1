import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: logo_image
    width: 1024
    height: 600

    color: "black"
    visible: !gearController.serverOKValue

    property string currentState: "Ready"

    Image {
        id: huScreen1
        source: "./HU_screen.png"
        anchors.centerIn: parent

        opacity: logo_image.currentState === "Ready" ? 1 : 0
        Behavior on opacity {
            NumberAnimation { duration: 1000 }
        }
    }

    Image {
        id: huScreen2
        source: "./HU_screen2.png"
        anchors.centerIn: parent

        opacity: logo_image.currentState === "Start" ? 1 : 0
        Behavior on opacity {
            NumberAnimation { duration: 1000 }
        }
    }

    Timer {
        interval: 1000
        repeat: false
        running: true

        onTriggered: {
            logo_image.currentState = "Start"
        }
    }



    MouseArea {
        anchors.fill: parent
        onClicked: {
            gearController.setSelectedButton("Start")
            logo_image.visible = false
        }
    }
}
