#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    connect(ui->fetchButton, &QPushButton::clicked, this, &MainWindow::onFetchWeather);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::onWeatherReply);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onFetchWeather()
{
    QString city = ui->cityLineEdit->text();
    fetchWeatherData(city);
}

void MainWindow::fetchWeatherData(const QString &city)
{
    QString apiKey = "{YOUR API KEY}";
    QString url = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric")
                    .arg(city, apiKey);

    // 네트워크 요청
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    networkManager->get(request);
}

void MainWindow::onWeatherReply(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();

        QString cityName = jsonObj["name"].toString();
        double temperature = jsonObj["main"].toObject()["temp"].toDouble();
        QString weatherDescription = jsonObj["weather"].toArray()[0].toObject()["description"].toString();

        QString result = QString("City: %1\nTemperature: %2°C\nDescription: %3")
                        .arg(cityName)
                        .arg(temperature)
                        .arg(weatherDescription);

        ui->weatherLabel->setText(result);
    } else {
        QMessageBox::warning(this, "Error", "Failed to fetch weather data.");
    }

    reply->deleteLater();
}
