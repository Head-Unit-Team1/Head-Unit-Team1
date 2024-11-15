#include "usbscanner.h"
#include "mp3player.h"  // MP3Player 클래스에 접근할 수 있도록 추가
#include <QStorageInfo>
#include <QDirIterator>
#include <QDebug>

USBScanner::USBScanner(QObject *parent) : QObject(parent) {
    scanTimer = new QTimer(this);
    connect(scanTimer, &QTimer::timeout, this, &USBScanner::scanForUSBDevices);
}

void USBScanner::startAutoScan() {
    scanTimer->start(2000);  // 2초마다 스캔
}

void USBScanner::scanForUSBDevices() {
    QStringList currentUsbDrives = scanUSBDrives();

    //if (currentUsbDrives != lastUsbDrives) {  // USB 드라이브 목록이 변경되었을 때만 스캔
        lastUsbDrives = currentUsbDrives;
        if (!currentUsbDrives.isEmpty()) {
            recentUSBPath = currentUsbDrives.last();
            QStringList mp3Files = findMP3Files(recentUSBPath, 2);
            //qDebug() << mp3Files ;

            if (!mp3Files.isEmpty()) {
                QStringList mp3AndCoverList;

                MP3Player mp3Player;  // MP3Player 클래스 객체 생성

                for (const QString &mp3File : mp3Files) {
                    mp3Player.loadMP3File(mp3File);  // 커버 이미지 생성
                    QString coverImagePath = mp3Player.coverImagePath();  // 커버 이미지 경로 얻기

                    mp3AndCoverList.append(mp3File + "|" + coverImagePath);
                }

                qDebug() << "MP3 emit" << mp3AndCoverList;

                emit mp3FilesFound(mp3AndCoverList);  // QML에 신호 보내기
                qDebug() << "Emit Finish";
            }
        }
    //}
}


QStringList USBScanner::scanUSBDrives() {
    QStringList usbDrives;
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
        if (storage.isValid() && storage.isReady() && !storage.isReadOnly()) {
            usbDrives << storage.rootPath();
        }
    }
    qDebug() << usbDrives;
    return usbDrives;
}

QStringList USBScanner::findMP3Files(const QString &path, int depth) {
    QStringList mp3Files;
    QDirIterator it(path, QStringList() << "*.mp3", QDir::Files, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        QString filePath = it.next();
        int currentDepth = filePath.count('/') - path.count('/');
        if (currentDepth <= depth) {
            mp3Files << filePath;
        }
    }
    return mp3Files;
}
