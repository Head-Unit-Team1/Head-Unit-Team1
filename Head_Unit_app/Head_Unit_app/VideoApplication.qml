import QtQuick 2.0
import QtWebEngine 1.0

Item {
    id: videoApplication
    width: 1024
    height: 600

    Text {
        id: head_text
        text: "Youtube Trending Video Top 10"
        font.pixelSize: 40
        font.bold: true
        color: "#FFFFFF"

        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 30
    }

    VideoObject {
        rank: 1

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: head_text.bottom
        anchors.topMargin: 30
    }

    Image {
        source: "./icon_home.png"
        width: 60
        height: 60
        anchors. horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30

        MouseArea {
            anchors.fill: parent
            onClicked: {
                stackView.pop()
            }
        }
    }

}
