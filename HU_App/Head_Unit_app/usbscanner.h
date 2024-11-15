#ifndef USBSCANNER_H
#define USBSCANNER_H

#include <QObject>
#include <QStringList>
#include <QTimer>
#include <QDebug>
#include <QCoreApplication>


class USBScanner : public QObject
{
    Q_OBJECT

public:
    explicit USBScanner(QObject *parent = nullptr);

    void startAutoScan();
    QStringList findMP3Files(const QString &path, int depth = 2);

signals:
    void mp3FilesFound(const QStringList &files);

private slots:
    void scanForUSBDevices();

private:
    QTimer *scanTimer;
    QString recentUSBPath;
    QStringList lastUsbDrives;  // 이전 USB 드라이브 목록 저장

    QStringList scanUSBDrives();
};

#endif // USBSCANNER_H
