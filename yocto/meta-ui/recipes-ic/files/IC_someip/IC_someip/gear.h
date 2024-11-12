#ifndef BUTTONSRECEIVER_H
#define BUTTONSRECEIVER_H

#include <QObject>
#include <QString>
#include <string.h>
class ICStubImpl;

class Gear : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString gearValue READ gearValue NOTIFY gearValueChanged)

public:
    explicit Gear(QObject *parent = nullptr);
    QString gearValue() const { return qt_gear; }
    void setICStubImpl(ICStubImpl* icStubImpl);
    Q_INVOKABLE void sendGearRandom(QString changedGear);

signals:
    void gearValueChanged();

public slots:
    void receiveGear(std::string signal);

private:
    QString qt_gear = "P";
    ICStubImpl* icStubImpl_;
};

#endif // BUTTONSRECEIVER_H
