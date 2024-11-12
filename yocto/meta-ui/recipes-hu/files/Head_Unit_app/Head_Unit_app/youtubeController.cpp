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
    <title>YouTube popular video</title>
    <script>
        async function fetchPopularVideos() {
            const apiKey = '{YOUR API KEY}'; 
            const response = await fetch(`https://www.googleapis.com/youtube/v3/videos?part=snippet&chart=mostPopular&maxResults=10&key=${apiKey}&regionCode=KR`);
            const data = await response.json();
            const videos = data.items;

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

        window.onload = fetchPopularVideos;
    </script>
</head>
<body>
</body>
</html>
        )";
}
