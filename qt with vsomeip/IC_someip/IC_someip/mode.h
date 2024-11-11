#ifndef MODE_H
#define MODE_H

#include <QObject>
#include <QString>
#include <string.h>

class Mode : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString modeValue READ modeValue NOTIFY modeValueChanged)
public:
    explicit Mode(QObject *parent = nullptr);
    QString modeValue() const { return qt_mode; }
signals:
    void modeValueChanged();
public slots:
    void receiveMode(int32_t signal);
private:
    QString qt_mode;
};

#endif // MODE_H
