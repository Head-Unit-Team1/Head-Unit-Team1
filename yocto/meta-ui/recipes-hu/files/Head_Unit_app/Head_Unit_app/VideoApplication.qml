import QtQuick 2.0
import QtWebEngine 1.0

Item {
    id: videoApplication
    width: 1024
    height: 600

    TopBar {
        id: topBar
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: head_text
        text: "Youtube Trending Video Top 10"
        font.pixelSize: 40
        font.bold: true
        color: "#FFFFFF"

        anchors.top: topBar.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 30
    }

    Flickable {
        id: videoSlide
        width: 820
        height: 400
        contentWidth: contentItem.width
        contentHeight: contentItem.height
        clip: true

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Rectangle {
            id:contentItem
            width: menuButtons.width
            height: parent.height
            color: "transparent"

            Row {
                id: menuButtons
                spacing: 30
                anchors.verticalCenter: parent.verticalCenter

                VideoObject {
                    id: video1
                    rank: 1
                }

                VideoObject {
                    id: video2
                    rank: 2
                }

                VideoObject {
                    id: video3
                    rank: 3
                }

                VideoObject {
                    id: video4
                    rank: 4
                }

                VideoObject {
                    id: video5
                    rank: 5
                }
            }
        }
    }

    HomeWidget {
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }
}
