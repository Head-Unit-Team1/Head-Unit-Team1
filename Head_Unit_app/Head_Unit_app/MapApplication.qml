import QtQuick 2.0
import QtWebEngine 1.0

Item {
    id: mapApplication
    width: 1024
    height: 600

    TopBar {
        id: topBar
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    WebEngineView {
        id: mapObject
        width: 1024
        height: 600
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 40

        url: "data:text/html;charset=utf-8," + encodeURIComponent(mapController.getGoogleMapHtml_app())

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

    HomeWidget {
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }
}
