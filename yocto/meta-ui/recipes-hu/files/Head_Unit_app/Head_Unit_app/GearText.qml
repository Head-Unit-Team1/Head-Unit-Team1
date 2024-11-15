import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.15

Item {
    id: gearButton

    property string gearLevel: ""
    property real buttonSize: 0.0

    width: buttonSize
    height: width

    Rectangle {
        id: buttonContainer
        width: parent.width
        height: width
        anchors.fill: parent
        color: "transparent"
        radius: width / 2

        RadialGradient {
            anchors.fill: parent
            gradient: Gradient {
                GradientStop { position: 0.0; color: gearController.selectedButton === gearButton.gearLevel ? "red" : "transparent"}
                GradientStop { position: 0.5; color: "transparent" }
            }
        }

        Text {
            text: gearButton.gearLevel
            font.pixelSize: 50
            color: "white"
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                gearController.setSelectedButton(gearButton.gearLevel) // 상위 컴포넌트의 selectedButton에 접근
        }
        }
    }

}
