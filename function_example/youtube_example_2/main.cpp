#include "mainwindow.h"

#include <QApplication>
#include <QQuickView>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    //view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return a.exec();
}
