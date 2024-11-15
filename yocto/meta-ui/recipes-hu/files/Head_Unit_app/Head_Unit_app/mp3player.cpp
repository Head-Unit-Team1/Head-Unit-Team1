#include "mp3player.h"
#include <QImage>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QCoreApplication>


MP3Player::MP3Player(QObject *parent) : QObject(parent) {}
QString MP3Player::coverImagePath() const {
    return m_coverImagePath;
}
void MP3Player::loadMP3File(const QString &filePath) {
    extractCoverArt(filePath);  // MP3 파일에서 커버 이미지 추출
}

void MP3Player::extractCoverArt(const QString &filePath) {
    QString coverFolderPath = QCoreApplication::applicationDirPath() + "/covers";
    QDir coverDir(coverFolderPath);
    if (!coverDir.exists()) {
        coverDir.mkpath(".");  // covers 폴더가 없으면 생성
    }

    QString imagePath = coverFolderPath + "/" + QFileInfo(filePath).baseName() + ".jpg";
    qDebug() << "Image Path: " << imagePath;

    // 파이썬 스크립트를 실행하여 커버 이미지를 추출
    QProcess process;
    QString scriptPath = QCoreApplication::applicationDirPath() + "/extract_cover.py";
    process.start("python3", QStringList() << scriptPath << filePath << imagePath);
    process.waitForFinished();

    // Python script execution result
    QString output = process.readAllStandardOutput();
    QString errorOutput = process.readAllStandardError();

    if (!output.isEmpty()) {
        qDebug() << "Python Output:" << output;
    }

    if (!errorOutput.isEmpty()) {
        qDebug() << "Python Error:" << errorOutput;
    }

    // 커버 이미지가 있으면 경로를 저장
    if (QFile::exists(imagePath)) {
        m_coverImagePath = "file://" + imagePath;
    } else {
        qDebug() << "No image related";
        m_coverImagePath = "qrc:/x.png";  // 기본 이미지 경로 사용
    }

    emit coverImagePathChanged();  // QML에서 이미지 경로를 갱신
}
