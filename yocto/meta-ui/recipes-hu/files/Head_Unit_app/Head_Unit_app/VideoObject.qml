import QtQuick 2.0
import QtWebEngine 1.0

Item {
    property int rank: 1
    width: 640
    height: 360

    WebEngineView {
        id: youtubeObject
        width: 640
        height: 360

        url: "data:text/html;charset=utf-8," + encodeURIComponent(youtubeController.getYoutubeHtmlForRank(parent.rank))

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
}
