#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mp3player.h"
#include "usbscanner.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MP3Player mp3Player;
    USBScanner usbScanner;

    engine.rootContext()->setContextProperty("mp3Player", &mp3Player);
    engine.rootContext()->setContextProperty("usbScanner", &usbScanner);

    // USB 스캔 자동 시작
    usbScanner.startAutoScan();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
