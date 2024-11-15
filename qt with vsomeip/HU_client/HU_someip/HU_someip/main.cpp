#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <CommonAPI/CommonAPI.hpp>

#include <v0/commonapi/ICProxy.hpp>
#include <QQmlContext>
#include <QObject>
#include <gear.h>
#include <battery.h>
#include <qqml.h>
#include <myworker.h>

int main(int argc, char *argv[])
{
    CommonAPI::Runtime::setProperty("LogContext", "E01C");
    CommonAPI::Runtime::setProperty("LogApplication", "E01C");
    CommonAPI::Runtime::setProperty("LibraryBase", "IC_someip");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Gear gearObject;
    Battery batteryObject;

    engine.rootContext()->setContextProperty("gearObject", &gearObject);
    engine.rootContext()->setContextProperty("batteryObject", &batteryObject);

    MyWorker worker(&batteryObject);

    engine.rootContext()->setContextProperty("workerObject", &worker);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
