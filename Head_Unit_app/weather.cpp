#include "weather.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QUrl>
#include <QNetworkRequest>

Weather::Weather(QObject *parent) : QObject(parent), networkManager(new QNetworkAccessManager(this)) {
    connect(networkManager, &QNetworkAccessManager::finished, this, &Weather::onWeatherReply);
}

void Weather::fetchWeatherData(const QString &city) {
    QString apiKey = "{YOUR API KEY}";
    QString url = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric")
            .arg(city, apiKey);

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    networkManager->get(request);
}

void Weather::onWeatherReply(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError){
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();

        QString cityName = jsonObj["name"].toString();
        double temperature = jsonObj["main"].toObject()["temp"].toDouble();
        QString weatherDescription = jsonObj["weather"].toArray()[0].toObject()["description"].toString();
        QString iconCode = jsonObj["weather"].toArray()[0].toObject()["icon"].toString();

        if (iconCode.isEmpty()) {
            qDebug() << "Icon code is empty.";
            //QMessageBox::warning(this, "Error", "Icon code is not available.");
            return; // 아이콘 코드가 없으면 함수 종료
        }

        QMap<QString, QString> weatherIconMap = {
            {"01", "./weather_image/sunny.png"}, //"fas fa-sun"},
            {"02", "./weather_image/cloud_sun.png"}, //"fas fa-cloud-sun"},
            {"03", "./weather_image/cloud.png"}, //"fas fa-cloud"},
            {"04", "./weather_image/cloud_meatball.png"}, //"fas fa-cloud-meatball"},
            {"09", "./weather_image/cloud_sun_rain.png"}, //"fas fa-cloud-sun-rain"},
            {"10", "./weather_image/rain_heavy.png"}, //"fas fa-cloud-showers-heavy"},
            {"11", "./weather_image/strom.png"}, //"fas fa-poo-storm"},
            {"13", "./weather_image/snow.png"}, //"far fa-snowflake"},
            {"50", "./weather_image/smog.png"}, //"fas fa-smog"}
        };

        QString iconPath = weatherIconMap.value(iconCode.left(2), "/home/seame/Head_Unit_app/weather_image/sunny.png");

        emit weatherDataReceived(cityName, temperature, weatherDescription, iconPath);
    }
    else {
        emit errorOccurred(reply->errorString());
    }

    reply->deleteLater();
}
