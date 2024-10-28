#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QMap>
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //ui->setupUi(this);

    view = new QWebEngineView(this);
    QString html = R"(
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

    // QWebEngineView에 HTML 설정
    view->setHtml(html);

    // 레이아웃 설정
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *inputLayout = new QHBoxLayout;

    mainLayout->addWidget(view, 3);

    // 입력창과 버튼을 수평으로 배치

    // 입력 폼과 레이블을 추가
    mainLayout->addLayout(inputLayout);

    // 중앙 위젯 설정
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // 네트워크 요청 처리 연결
}

MainWindow::~MainWindow()
{
    //delete ui;
}
