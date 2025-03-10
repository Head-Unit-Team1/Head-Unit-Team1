#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QWebEngineView>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void onFetchWeather();
    //void onWeatherReply(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    QWebEngineView *view;
    //QLineEdit *cityLineEdit;
    //QPushButton *fetchButton;
    //QLabel *weatherLabel;
    //QLabel *iconLabel;
    //QNetworkAccessManager *networkManager;
    //void fetchWeatherData(const QString &city);
};

#endif // MAINWINDOW_H

