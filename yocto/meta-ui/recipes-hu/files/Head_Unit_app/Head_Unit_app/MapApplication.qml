import QtQuick 2.0
import QtWebEngine 1.0

Item {
    id: mapApplication
    width: 1024
    height: 600

    WebEngineView {
        id: mapObject
        width: 460
        height: 460
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 40

        url: "data:text/html;charset=utf-8," + encodeURIComponent(mapController.getGoogleMapHtml())

        onLoadingChanged: {
                    if (loadRequest.status === WebEngineLoadRequest.LoadFailedStatus) {
                        console.error("Failed to load Google Map:", loadRequest.errorString)
                    }
                }

        Component.onCompleted: {
            if (mapController === null) {
                console.error("mapController is null");
            } else {
                console.log("mapController is available");
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
