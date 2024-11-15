#ifndef MYWORKER_H
#define MYWORKER_H
#include <QObject>
#include <QTimer>
#include <battery.h>

class MyWorker : public QObject
{
    Q_OBJECT
public:
    explicit MyWorker(Battery *battery, QObject *parent = nullptr);
public slots:
    void doWork();
private:
    QTimer *time;
    Battery *battery;
};

#endif // MYWORKER_H
