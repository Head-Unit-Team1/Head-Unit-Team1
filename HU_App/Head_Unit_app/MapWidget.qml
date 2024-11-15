import QtQuick 2.0
import QtWebEngine 1.0

Item {
    id: mapWidget
    width: 460
    height: 560

    AppWidget {
        id: map_widget
        widthData: parent.width
        heightData: parent.height

        WebEngineView {
            id: googleMap
            width: parent.width - 10
            height: parent.height -10
            anchors.centerIn: parent

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
    }

}
