#ifndef LRSIGN_H
#define LRSIGN_H

#include <QObject>

class LRSign: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int32_t directionValue READ directionValue NOTIFY directionValueChanged)
public:
    explicit LRSign(QObject *parent = nullptr);
    int32_t directionValue() const {return qt_direction;}
    Q_INVOKABLE void sendLrsignRandom(int32_t changedDirection);
signals:
    void directionValueChanged();
    void broadcastDirection(int32_t signValue);
private:
    int32_t qt_direction = 0;
};

#endif // LRSIGN_H
