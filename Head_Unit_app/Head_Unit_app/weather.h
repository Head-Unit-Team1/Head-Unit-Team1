#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Weather : public QObject {
    Q_OBJECT

public:
    explicit Weather(QObject *parent = nullptr);

    Q_INVOKABLE void fetchWeatherData(const QString &city);

signals:
    void weatherDataReceived(const QString &cityName, double temperature, const QString &weatherDescription, const QString &iconCode);
    void errorOccurred(const QString &errorString);

private slots:
    void onWeatherReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
};

#endif // WEATHER_H
