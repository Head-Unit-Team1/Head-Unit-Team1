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
    Q_INVOKABLE void fetch5daysWeather(const QString &city);

signals:
    void weatherDataReceived(const QString &cityName, double temperature, const QString &weatherDescription, const QString &iconCode);
    void forecastDataReceived(const QString &cityName, const QVariantList &forecastData);
    void errorOccurred(const QString &errorString);

private slots:
    void onNetworkReply(QNetworkReply *reply);
/*    void onWeatherReply(QNetworkReply *reply);
    void onForecastWeatherReply(QNetworkReply *reply);//*/

private:
    QNetworkAccessManager *networkManager;
    QNetworkReply *weatherReply;
    QNetworkReply *forecastReply;
};

#endif // WEATHER_H
