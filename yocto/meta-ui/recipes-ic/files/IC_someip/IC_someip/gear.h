#ifndef BUTTONSRECEIVER_H
#define BUTTONSRECEIVER_H

#include <QObject>
#include <QString>
#include <string.h>

class Gear : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString gearValue READ gearValue NOTIFY gearValueChanged)

public:
    explicit Gear(QObject *parent = nullptr);
    QString gearValue() const { return qt_gear; }

signals:
    void gearValueChanged();

public slots:
    void receiveGear(std::string signal);

private:
    QString qt_gear = "P";
};

#endif // BUTTONSRECEIVER_H
