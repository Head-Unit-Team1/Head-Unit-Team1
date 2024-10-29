#include "youtubeController.h"

YoutubeController::YoutubeController(QObject *parent) : QObject(parent) {
    apiKey = "";
}

QString YoutubeController::getYoutubeHtml() const {
    return R"(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>YouTube 인기 동영상</title>
    <script>
        async function fetchPopularVideos() {
            const apiKey = '{YOUR API KEY}'; // 여기에 API 키를 넣으세요
            const response = await fetch(`https://www.googleapis.com/youtube/v3/videos?part=snippet&chart=mostPopular&maxResults=10&key=${apiKey}&regionCode=KR`);
            const data = await response.json();
            const videos = data.items;

            // 각 비디오에 대해 iframe을 생성하고 본문에 추가합니다.
            const body = document.body;
            videos.forEach(video => {
                const videoId = video.id;
                const iframe = document.createElement('iframe');
                iframe.width = 720;
                iframe.height = 405;
                iframe.src = `https://www.youtube.com/embed/${videoId}`;
                iframe.frameBorder = 0;
                iframe.allowFullscreen = true;
                body.appendChild(iframe);
            });
        }

        // 페이지가 로드될 때 함수 호출
        window.onload = fetchPopularVideos;
    </script>
</head>
<body>
</body>
</html>
        )";
}

QString YoutubeController::getYoutubeHtmlForRank(int rank) const {
    if (rank < 1 || rank > 10) {
        return "<p>Invalid rank. Please choose a rank from 1 to 10.</p>";
    }

    return QString(R"(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>YouTube 인기 동영상</title>
    <style>
        html, body {
            margin: 0;
            padding: 0;
            overflow: hidden;
            width: 100%
            height: 100%
            display: flex;
            align-items: center;
            justify-content: center;
        }
        iframe {
            width: 100vw;
            height: 100vh;
            border: none;
        }
    </style>
    <script>
        async function fetchVideoForRank(rank) {
            const apiKey = 'AIzaSyAqmS_QH00cdDKhv5ZtAevxXBSJSUvGcbc'; // 여기에 API 키를 넣으세요
            const response = await fetch(`https://www.googleapis.com/youtube/v3/videos?part=snippet&chart=mostPopular&maxResults=10&key=${apiKey}&regionCode=KR`);
            const data = await response.json();
            const videos = data.items;

            // 선택한 순위의 비디오만 표시
            const body = document.body;
            if (rank >= 1 && rank <= videos.length) {
                const video = videos[rank - 1];  // 배열은 0부터 시작하므로 rank - 1
                const videoId = video.id;
                const iframe = document.createElement('iframe');
                iframe.width = 640;
                iframe.height = 360;
                iframe.src = `https://www.youtube.com/embed/${videoId}`;
                iframe.frameBorder = 0;
                iframe.allowFullscreen = true;
                body.appendChild(iframe);
            } else {
                body.innerHTML = '<p>해당 순위의 동영상을 찾을 수 없습니다.</p>';
            }
        }

        // 페이지가 로드될 때 함수 호출
        window.onload = () => fetchVideoForRank(%1);
    </script>
</head>
<body>
</body>
</html>
    )").arg(rank);
}
