import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0
import QtMultimedia 5.12

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
        height: 360

        spacing: 20

        ListView {
            id: musicList
            width: parent.width
            height: parent.height
            model: ListModel {}

            delegate: Rectangle {
                width: musicList.width
                height: musicList.height / 4
                color: "#99232121"
                radius: 10

                Row {
                    anchors.fill: parent
                    spacing: 10
                    Image {
                        id: musicImg
                        width: 60
                        height:60
                        anchors.left: parent.left
                        anchors.leftMargin: 40
                        anchors.verticalCenter: parent.verticalCenter

                        source: model.coverImagePath !== "" ? model.coverImagePath : "./icon_home.png"
                    }

                    Text {
                        text: model.filePath.split("/").pop()
                        color: "white"
                        font.pixelSize: 25
                        font.bold: true

                        anchors.left: musicImg.right
                        anchors.leftMargin: 20
                        anchors.top: parent.top
                        anchors.topMargin: 15
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        coverImg.source = musicImg.source

                        if (model.filePath && model.filePath !== "undefined") {
                            mp3Player.loadMP3File(model.filePath)
                            audioPlayer.source = "file://" + model.filePath;
                            musicPlayBar.playClicked = true;
                            audioPlayer.play()
                        } else {
                            console.log("Error: MP3 file path is undefined.");
                        }
                    }
                }
            }
        }
    }

    Audio {
        id: audioPlayer
        autoPlay: false
        source: ""

        onStatusChanged: {
            if(status === Audio.EndOfMedia) {
                audioPlayer.stop();
            }
        }
    }

    Connections {
        target: audioPlayer
        onSourceChanged: {
            console.log("Audio source changed to: " + audioPlayer.source)
        }
    }

    Connections {
        target: usbScanner
        onMp3FilesFound: {
            musicList.model.clear()
            console.log("MP3 files: " + files);
            for (var i = 0; i < files.length; i++) {
                var file = files[i].split("|");
                if (file[0] !== "" && file[1] !== "") {
                    musicList.model.append({"filePath": file[0], "coverImagePath": file[1]});
                    console.log("Music List: " + musicList.model);
                } else {
                    console.log("Invalid MP3 or Cover path: " + file[0] + "|" + file[1]);
                }
            }
        }
    }

    Rectangle {
        id: musicPlayBar
        width: parent.width
        height: 80

        anchors.bottom: parent.bottom
        color: "#232121"

        property bool playClicked: false

        layer.enabled: true
        layer.effect: DropShadow {
            color: carInfoController.modeColor//"#A2F2D9"
            radius: 10
            samples: 16
            spread: 0.2
            x: 0
            y: 1
        }

        Image {
            id: playButton
            width: 60
            height: width
            anchors.centerIn: parent

            source: musicPlayBar.playClicked === false ? "./Play.png" : "./Pause.png"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    musicPlayBar.playClicked === false ? audioPlayer.play() : audioPlayer.pause()
                    musicPlayBar.playClicked === false ? musicPlayBar.playClicked = true : musicPlayBar.playClicked = false
                }
            }
        }
    }

    HomeWidget {
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
    }

}
