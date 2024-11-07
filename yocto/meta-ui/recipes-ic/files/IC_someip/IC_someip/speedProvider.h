#ifndef SPEEDPROVIDER_H
#define SPEEDPROVIDER_H

#include <QObject>
#include <QTimer>
#include <cstdlib>
#include <ctime>

class SpeedProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int speedValue READ speedValue NOTIFY speedChanged)

public:
    explicit SpeedProvider(QObject *parent = nullptr)
        : QObject(parent), m_speedValue(0)
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));  // 시드 설정

        // 1초마다 랜덤 값을 생성하기 위한 타이머 설정
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &SpeedProvider::generateSpeed);
        timer->start(1000); // 1초마다 랜덤 값 생성
    }

    int speedValue() const
    {
        return m_speedValue;
    }

    int minSpeed() const
    {
        return m_minSpeed;
    }

    int maxSpeed() const
    {
        return m_maxSpeed;
    }

    void setMinSpeed(int minSpeed)
    {
        if(minSpeed != m_minSpeed){
            m_minSpeed = minSpeed;
            emit minSpeedChanged();
        }
    }

    void setMaxSpeed(int maxSpeed)
    {
        if(maxSpeed != m_maxSpeed){
            m_maxSpeed = maxSpeed;
            emit maxSpeedChanged();
        }
    }

signals:
    void speedChanged();
    void minSpeedChanged();
    void maxSpeedChanged();

private slots:
    void generateSpeed()
    {
        if(m_minSpeed < m_maxSpeed){
            m_speedValue = m_minSpeed + std::rand() % (m_maxSpeed - m_minSpeed + 1);
        }
        emit speedChanged();  // QML에 값이 변경되었음을 알림
    }

private:
    int m_speedValue;  // 현재 속도 값
    int m_minSpeed;
    int m_maxSpeed;
};

#endif // SPEEDPROVIDER_H
