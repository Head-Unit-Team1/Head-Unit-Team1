import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: musicApplication
    width: 1024
    height: 600

    TopBar {
        id: topBar
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: appTitle
        text: "Music"
        color: "white"
        font.pixelSize: 40
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: topBar.bottom
        anchors.topMargin: 20
    }

    ListModel {
        id: musicObj
        ListElement { fileName: "Title1"; coverImagePath: "./icon_music.png"}
        ListElement { fileName: "Title2"; coverImagePath: "./icon_youtube.png"}
        ListElement { fileName: "Title3"; coverImagePath: "./icon_mode.png"}
    }

    Rectangle {
        id: coverArea
        width: musicApplication.width
        height: musicApplication.height
        z: -1

        color: "#99000000"

        anchors.left: parent.left
        anchors.bottom: parent.bottom

        Image {
            id: coverImg
            anchors.fill: parent
            source: ""
        }

        Rectangle {
            anchors.fill: parent
            color: "#99000000"
        }
    }

    Column {
        anchors.top: appTitle.bottom
        anchors.topMargin: 30
        width: 1024
        height: 320

        spacing: 20

        ListView {
            id: musicList
            width: parent.width
            height: parent.height
            model: musicObj

            delegate: Rectangle {
                width: musicList.width
                height: musicList.height / 4
                color: "#99D9D9D9"

                Row {
                    anchors.fill: parent
                    spacing: 10
                    Image {
                        id: musicImg
                        width: 50
                        height:50
                        source: model.coverImagePath !== "" ? model.coverImagePath : "./icon_home.png"
                    }

                    Text {
                        text: model.fileName !== "" ? model.fileName : "Title"
                        color: "white"
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        coverImg.source = musicImg.source
                    }
                }
            }
        }
    }

    Rectangle {
        id: musicPlayBar
        width: parent.width
        height: 80

        anchors.bottom: parent.bottom
        color: "#D9D9D9"

        property bool playClicked: false

        Image {
            id: playButton
            width: 60
            height: width
            anchors.centerIn: parent

            source: musicPlayBar.playClicked === false ? "./Play.png" : "./Pause.png"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    musicPlayBar.playClicked === false ? musicPlayBar.playClicked = true : musicPlayBar.playClicked = false
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
