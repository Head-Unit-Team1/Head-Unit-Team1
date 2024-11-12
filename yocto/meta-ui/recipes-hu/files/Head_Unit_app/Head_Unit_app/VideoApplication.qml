import QtQuick 2.0
import QtWebEngine 1.0

Item {
    id: videoApplication
    width: 1024
    height: 600

    WebEngineView {
        id: youtubeObject
        width: 750
        height: 420
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 60

        url: "data:text/html;charset=utf-8," + encodeURIComponent(youtubeController.getYoutubeHtml())

        onLoadingChanged: {
                    if (loadRequest.status === WebEngineLoadRequest.LoadFailedStatus) {
                        console.error("Failed to load Youtube:", loadRequest.errorString)
                    }
                }

        Component.onCompleted: {
            if (mapController === null) {
                console.error("youtubeController is null");
            } else {
                console.log("youtubeController is available");
            }
        }
    }

    Image {
        source: "./icon_menu.png"
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
