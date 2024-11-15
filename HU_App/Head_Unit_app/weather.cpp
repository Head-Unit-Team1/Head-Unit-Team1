#include "weather.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QUrl>
#include <QNetworkRequest>

Weather::Weather(QObject *parent) : QObject(parent), networkManager(new QNetworkAccessManager(this)), weatherReply(nullptr), forecastReply(nullptr) {
    connect(networkManager, &QNetworkAccessManager::finished, this, &Weather::onNetworkReply);
    //connect(networkManager, &QNetworkAccessManager::finished, this, &Weather::onWeatherReply);
    //connect(networkManager, &QNetworkAccessManager::finished, this, &Weather::onForecastWeatherReply);
}

void Weather::fetchWeatherData(const QString &city) {
    QString apiKey = "{YOUR API KEY}";
    QString url = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric")
            .arg(city, apiKey);

    QNetworkRequest request;
    request.setUrl(QUrl(url));

    if (weatherReply) {
            weatherReply->deleteLater();
            //weatherReply = nullptr;
        }

        weatherReply = networkManager->get(request);
        //connect(weatherReply, &QNetworkReply::finished, this, &Weather::onWeatherReply);
}

void Weather::fetch5daysWeather(const QString &city) {
    QString apiKey = "{YOUR API KEY}";
    QString url = QString("https://api.openweathermap.org/data/2.5/forecast?q=%1&appid=%2&units=metric")
            .arg(city, apiKey);

    QNetworkRequest request;
    request.setUrl(QUrl(url));

    if (forecastReply) {
            forecastReply->deleteLater();
            //forecastReply = nullptr;
        }

        forecastReply = networkManager->get(request);
        //connect(forecastReply, &QNetworkReply::finished, this, &Weather::onForecastWeatherReply);
}

void Weather::onNetworkReply(QNetworkReply *reply) {
    if (reply == weatherReply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
            QJsonObject jsonObj = jsonDoc.object();

            QString cityName = jsonObj["name"].toString();
            double temperature = jsonObj["main"].toObject()["temp"].toDouble();
            QString weatherDescription = jsonObj["weather"].toArray()[0].toObject()["description"].toString();
            QString iconCode = jsonObj["weather"].toArray()[0].toObject()["icon"].toString();

            QMap<QString, QString> weatherIconMap = {
                {"01", "./weather_image/sunny.png"},
                {"02", "./weather_image/cloud_sun.png"},
                {"03", "./weather_image/cloud.png"},
                {"04", "./weather_image/cloud_meatball.png"},
                {"09", "./weather_image/cloud_sun_rain.png"},
                {"10", "./weather_image/rain_heavy.png"},
                {"11", "./weather_image/storm.png"},
                {"13", "./weather_image/snow.png"},
                {"50", "./weather_image/smog.png"}
            };

            QString iconPath = weatherIconMap.value(iconCode.left(2), "./weather_image/sunny.png");

            emit weatherDataReceived(cityName, temperature, weatherDescription, iconPath);
        } else {
            emit errorOccurred(reply->errorString());
        }
        weatherReply->deleteLater();
        weatherReply = nullptr;
    } else if (reply == forecastReply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            qDebug() << "Forecast JSON Response:" << response;

            QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
            QJsonObject jsonObj = jsonDoc.object();

            QString cityName = jsonObj["city"].toObject()["name"].toString();
            QJsonArray forecastList = jsonObj["list"].toArray();

            //QList<QMap<QString, QVariant>> forecastData;
            QVariantList forecastVariantList;

            for (const QJsonValue &value : forecastList) {
                QJsonObject forecastObj = value.toObject();
                QString dateTime = forecastObj["dt_txt"].toString();

                if (dateTime.endsWith("12:00:00")) {
                    QString dateOnly = QDateTime::fromString(dateTime, "yyyy-MM-dd HH:mm:ss").toString("yyyy-MM-dd");
                    QJsonObject mainObject = forecastObj["main"].toObject();
                    double temperature = mainObject["temp"].toDouble();

                    QString weatherDescription = forecastObj["weather"].toArray()[0].toObject()["description"].toString();
                    QString iconCode = forecastObj["weather"].toArray()[0].toObject()["icon"].toString();

                    QMap<QString, QString> weatherIconMap = {
                        {"01", "./weather_image/sunny.png"},
                        {"02", "./weather_image/cloud_sun.png"},
                        {"03", "./weather_image/cloud.png"},
                        {"04", "./weather_image/cloud_meatball.png"},
                        {"09", "./weather_image/cloud_sun_rain.png"},
                        {"10", "./weather_image/rain_heavy.png"},
                        {"11", "./weather_image/storm.png"},
                        {"13", "./weather_image/snow.png"},
                        {"50", "./weather_image/smog.png"}
                    };

                    QString iconPath = weatherIconMap.value(iconCode.left(2), "./weather_image/sunny.png");

                    QMap<QString, QVariant> forecastItem;
                    forecastItem["dateTime"] = dateOnly;
                    forecastItem["temperature"] = temperature;
                    forecastItem["description"] = weatherDescription;
                    forecastItem["iconPath"] = iconPath;

                    //forecastData.append(forecastItem);
                    forecastVariantList.append(forecastItem);

                }

            }

            emit forecastDataReceived(cityName, forecastVariantList);
        } else {
            emit errorOccurred(reply->errorString());
        }
        forecastReply->deleteLater();
        forecastReply = nullptr;
    }
    reply->deleteLater();
}
