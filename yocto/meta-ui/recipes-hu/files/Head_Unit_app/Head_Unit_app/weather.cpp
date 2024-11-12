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
        // 날씨 데이터를 처리하는 부분
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
        // 5일 날씨 예보 데이터를 처리하는 부분
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
/*
void Weather::onWeatherReply(QNetworkReply *reply) {
    if (sender() != weatherReply) return;


    if (reply->error() == QNetworkReply::NoError){
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();

        QString cityName = jsonObj["name"].toString();
        double temperature = jsonObj["main"].toObject()["temp"].toDouble();
        QString weatherDescription = jsonObj["weather"].toArray()[0].toObject()["description"].toString();
        QString iconCode = jsonObj["weather"].toArray()[0].toObject()["icon"].toString();

        if (iconCode.isEmpty()) {
            qDebug() << "Icon code is empty. JSON Response.";
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
    weatherReply = nullptr;
}

void Weather::onForecastWeatherReply(QNetworkReply *reply) {
    if (sender() != forecastReply) return;

    if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
            QJsonObject jsonObj = jsonDoc.object();

            QString cityName = jsonObj["city"].toObject()["name"].toString();
            QJsonArray forecastList = jsonObj["list"].toArray();

            QList<QMap<QString, QVariant>> forecastData;

            for (const QJsonValue &value : forecastList) {
                QJsonObject forecastObj = value.toObject();

                // 날짜 및 시간
                QString dateTime = forecastObj["dt_txt"].toString();

                // 온도
                double temperature = forecastObj["main"].toObject()["temp"].toDouble();

                // 날씨 설명
                QString weatherDescription = forecastObj["weather"].toArray()[0].toObject()["description"].toString();

                // 아이콘 코드
                QString iconCode = forecastObj["weather"].toArray()[0].toObject()["icon"].toString();

                if (iconCode.isEmpty()) {
                    qDebug() << "Icon code is empty. 5 days JSON Response.";
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

                QString iconPath = weatherIconMap.value(iconCode.left(2), "./weather_image/sunny.png");

                // 데이터를 QMap에 저장
                QMap<QString, QVariant> forecastItem;
                forecastItem["dateTime"] = dateTime;
                forecastItem["temperature"] = temperature;
                forecastItem["description"] = weatherDescription;
                forecastItem["iconPath"] = iconPath;

                forecastData.append(forecastItem);
            }

            // 데이터를 시그널로 전달
            emit forecastDataReceived(cityName, forecastData);
        } else {
            emit errorOccurred(reply->errorString());
        }

        reply->deleteLater();
        forecastReply = nullptr;
}//*/
