#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QTimer>
#include <QDateTime>

class Clock : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentTime READ currentTime NOTIFY timeChanged)

public:
    explicit Clock(QObject *parent = nullptr)
        : QObject(parent)
    {
        // 타이머를 사용하여 매초 현재 시간을 업데이트
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Clock::updateTime);
        timer->start(1000); // 1초마다 타이머 작동
    }

    QString currentTime() const
    {
        // 현재 시간을 QString 형식으로 반환
        return QDateTime::currentDateTime().toString("hh:mm:ss");
    }

signals:
    void timeChanged();

public slots:
    void updateTime()
    {
        emit timeChanged(); // 시간이 변경되었음을 알림
    }
};

#endif // CLOCK_H
