#include "mainwindow.h"

#include <QApplication>
#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QFile>

QString loadHtmlFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Could not open HTML file.");
        return QString();
    }

    QString html = QString::fromUtf8(file.readAll());
    return html;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWebEngineView view;
    view.settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);

    QString html = loadHtmlFile("/home/seame/Google_map_example/map.html");

    if (!html.isEmpty()) {
        view.setHtml(html);
        view.setWindowTitle("Google Map Example");
        view.resize(800, 600);
        view.show();
    }

    return a.exec();
}
