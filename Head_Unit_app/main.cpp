#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "current_clock.h"
#include "weather.h"
#include "mapController.h"
#include "gearController.h"
#include "youtubeController.h"
#include "carInfoController.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Clock clock;
    engine.rootContext()->setContextProperty("Clock", &clock);

    Weather weather;
    engine.rootContext()->setContextProperty("weather", &weather);

    MapController mapController;
    engine.rootContext()->setContextProperty("mapController", &mapController);

    GearController gearController;
    engine.rootContext()->setContextProperty("gearController", &gearController);

    YoutubeController youtubeController;
    engine.rootContext()->setContextProperty("youtubeController", &youtubeController);

    CarInfoController carInfoController;
    engine.rootContext()->setContextProperty("carInfoController", &carInfoController);
    //carInfoController.setBatteryLevel(75);



    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}