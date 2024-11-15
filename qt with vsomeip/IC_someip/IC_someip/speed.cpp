#include "speed.h"

Speed::Speed(QObject *parent) : QObject(parent), m_speed(0) {
//    // 타이머 설정 (1초마다 updateSpeed 함수 호출)
//    connect(&m_timer, &QTimer::timeout, this, &Speed::updateSpeed);
//    m_timer.start(1000); // 1초(1000ms) 간격으로 타이머 시작
}

int Speed::speed() const {
    return m_speed;
}

void Speed::updateSpeed() {
    m_speed = (m_speed + 5) % 105; // 0부터 100까지 순환
    emit speedChanged(m_speed); // 속도가 변경될 때마다 시그널 발행
}
