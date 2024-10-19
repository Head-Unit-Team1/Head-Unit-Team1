#ifndef CARINFOCONTROLLER_H
#define CARINFOCONTROLLER_H

#include <QObject>

class CarInfoController : public QObject {
    Q_OBJECT
    Q_PROPERTY(int batteryLevel READ batteryLevel WRITE setBatteryLevel NOTIFY batteryLevelChanged)
    Q_PROPERTY(QString modeColor READ modeColor WRITE setModeColor NOTIFY modeColorChanged)
    Q_PROPERTY(QString blinkDirection READ blinkDirection WRITE setDirection NOTIFY directionChanged)

    public:
        explicit CarInfoController(QObject *parent = nullptr) : QObject(parent), m_batteryLevel(80), m_modeColor("#A2F2D9"), m_direction("left") {}

        int batteryLevel() const {
            return m_batteryLevel;
        }

        Q_INVOKABLE void setBatteryLevel(int level) {
            if (m_batteryLevel != level) {
                m_batteryLevel = level;
                emit batteryLevelChanged();
            }
        }

        QString modeColor() const {
            return m_modeColor;
        }

        Q_INVOKABLE void setModeColor(const QString& color) {
            if (m_modeColor != color) {
                m_modeColor = color;
                emit modeColorChanged();
            }
        }

        QString blinkDirection() const {
            return m_direction;
        }

        Q_INVOKABLE void setDirection(const QString& direction) {
            if(m_direction != direction) {
                m_direction = direction;
                emit directionChanged();
            }
        }

    signals:
        void batteryLevelChanged();
        void modeColorChanged();
        void directionChanged();

    private:
        int m_batteryLevel;
        QString m_modeColor;
        QString m_direction;
};

#endif // CARINFOCONTROLLER_H
