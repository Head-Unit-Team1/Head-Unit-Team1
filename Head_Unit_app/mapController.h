#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <QObject>

class MapController : public QObject {
    Q_OBJECT
public:
    explicit MapController(QObject *parent = nullptr);

    Q_INVOKABLE QString getGoogleMapHtml() const;

private:
    QString apiKey;
};


#endif // MAPCONTROLLER_H