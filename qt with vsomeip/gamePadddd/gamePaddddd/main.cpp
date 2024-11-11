#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/IC_interProxy.hpp>
#include <qqml.h>
#include <QObject>
#include <QQmlContext>
#include <gear.h>
#include <lrsign.h>
int main(int argc, char *argv[])
{
    qRegisterMetaType<int32_t>("int32_t");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    CommonAPI::Runtime::setProperty("LogContext", "E01C");
    CommonAPI::Runtime::setProperty("LogApplication", "E01C");
    CommonAPI::Runtime::setProperty("LibraryBase", "gamepaddddd");


    QGuiApplication app(argc, argv);
    Gear gearObject;
    LRsign lrsignObject;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("gearObject", &gearObject);
    engine.rootContext()->setContextProperty("lrsignObject", &lrsignObject);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
