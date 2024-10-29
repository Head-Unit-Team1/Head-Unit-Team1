import QtQuick 2.12
import QtQuick.Controls 1.4
import QtMultimedia 5.12

ApplicationWindow {
    visible: true
    width: 800
    height: 400
    title: "MP3 Player"

    Column {
        anchors.centerIn: parent
        spacing: 20

        // mp3 file list
        ListView {
            id: mp3ListView
            width: 300
            height: 200
            model: ListModel {}

            delegate: Button {
                width: mp3ListView.width
                height: 50

                Row {
                    spacing: 10
                    Image {
                        width: 50
                        height: 50
                        source: model.coverImagePath !== "" ? model.coverImagePath : "qrc:/default_cover.png"
                    }
                    Text {
                        text: model.filePath.split("/").pop()  // 파일 이름만 출력
                    }
                }

                onClicked: {
                    if (model.filePath && model.filePath !== "undefined") {  // 파일 경로가 유효할 때만 실행
                        console.log("Selected MP3 file: " + model.filePath)
                        mp3Player.loadMP3File(model.filePath)
                        audioPlayer.source = "file://" + model.filePath;
                        audioPlayer.play()
                    } else {
                        console.log("Error: MP3 file path is undefined.");
                    }
                }
            }

        }



        // cover image
        Image {
            id: coverImage
            width: 200
            height: 200
            cache: false
            fillMode: Image.PreserveAspectFit
            source: mp3Player.coverImagePath !== "" ? mp3Player.coverImagePath : "qrc:/x.png"
            visible: mp3Player.coverImagePath !== ""
        }


        // audio play control
        Audio {
            id: audioPlayer
            autoPlay: false
            source: ""

            onStatusChanged: {
                if (status === Audio.EndOfMedia) {
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

        // play and control
        Row {
            spacing: 10
            Button {
                text: "Play"
                onClicked: {
                    if (mp3Player.coverImagePath !== "") {
                        audioPlayer.play()
                    } else {
                        console.log("Error: MP3 file path is undefined.")
                    }
                }
            }

            Button {
                text: "Pause"
                onClicked: audioPlayer.pause()
            }
            Button {
                text: "Stop"
                onClicked: audioPlayer.stop()
            }
        }
    }

    // update mp3 list from usb
    Connections {
        target: usbScanner
        onMp3FilesFound: {
            mp3ListView.model.clear()
            for (var i = 0; i < files.length; i++) {
                var file = files[i].split("|");
                if (file[0] !== "" && file[1] !== "") {  // 파일 경로와 커버 이미지 경로가 유효한지 확인
                    mp3ListView.model.append({"filePath": file[0], "coverImagePath": file[1]});
                } else {
                    console.log("Invalid MP3 or Cover path: " + file[0] + " | " + file[1]);
                }
            }
        }
    }

}
