#include "myworker.h"

MyWorker::MyWorker(Battery *battery, QObject *parent) : QObject(parent), battery(battery)
{
    time = new QTimer(this);
    connect(time, &QTimer::timeout, this, &MyWorker::doWork);
    time->start(100);
}
void MyWorker::doWork(){
    battery->getBattery();
}
