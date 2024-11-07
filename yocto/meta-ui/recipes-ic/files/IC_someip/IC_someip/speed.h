#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject {
    Q_OBJECT
    Q_PROPERTY(int speed READ speed NOTIFY speedChanged)

public:
    explicit Speed(QObject *parent = nullptr);

    int speed() const;

signals:
    void speedChanged(int newSpeed);

public slots:
    void updateSpeed(); // 타이머에 의해 호출될 함수

private:
    int m_speed;
};

#endif // SPEED_H
