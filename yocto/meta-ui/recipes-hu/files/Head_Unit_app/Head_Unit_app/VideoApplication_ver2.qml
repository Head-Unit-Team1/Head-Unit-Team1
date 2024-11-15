import QtQuick 2.15
import QtQuick.Controls 2.15
import QtWebEngine 1.0

Item {
    id: videoSlider
    width: 700
    height: 400

    property var videoUrls: []  // 각 동영상의 URL을 담는 배열
    property int currentIndex: 0  // 현재 보여지는 동영상의 인덱스

    signal loadVideo(int index)  // 동영상 로드 신호

    Component.onCompleted: {
        // 초기화: 10개의 인기 동영상 URL을 가져옵니다.
        for (var i = 1; i <= 10; i++) {
            videoUrls.push("data:text/html;charset=utf-8," + encodeURIComponent(youtubeController.getYoutubeHtmlForRank(i)))
        }
        loadVideo(currentIndex)
    }

    Flickable {
        id: flickable
        width: parent.width
        height: parent.height
        contentWidth: width * videoUrls.length
        boundsBehavior: Flickable.StopAtBounds
        interactive: true

        // 현재 슬라이드 변경 시 이벤트 처리
        onContentXChanged: {
            if (flickable.isMoving || flickable.isDragging) {
                return; // 드래그 중에는 아무 작업도 하지 않습니다.
            }

            // 현재 슬라이드 인덱스를 계산하여 중앙에 위치하도록 조정
            let slideIndex = Math.round(contentX / width)
            if (slideIndex !== currentIndex) {
                currentIndex = slideIndex
                loadVideo(currentIndex)
            }
        }

        // 드래그 후 애니메이션을 적용하여 슬라이드 넘기기
        onMovementEnded: {
            let slideIndex = Math.round(contentX / width)
            if (slideIndex !== currentIndex) {
                currentIndex = (slideIndex + videoUrls.length) % videoUrls.length
                loadVideo(currentIndex)
            }
            // 중앙으로 위치 조정
            flickable.contentX = width * currentIndex
        }

        // 메인 동영상
        Repeater {
            model: videoUrls.length

            WebEngineView {
                width: flickable.width
                height: flickable.height
                url: videoUrls[index]
                anchors.centerIn: parent
            }
        }
    }

    // 동영상을 로드하는 함수
    onLoadVideo: {
        // 현재 슬라이드 위치로 이동
        flickable.contentX = flickable.width * currentIndex
    }
}
