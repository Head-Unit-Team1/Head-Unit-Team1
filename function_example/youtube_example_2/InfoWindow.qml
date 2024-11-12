import QtQuick 2.5
import QtQuick.Controls 1.2

Rectangle {
    width: 400
    height: 300
    color: "lightblue"

    Text {
        text: "This is second screen"
        anchors.centerIn: parent
        font.pointSize: 24
    }

    Button {
        text: "Back to Main"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            stackView.pop()
        }
    }

}
