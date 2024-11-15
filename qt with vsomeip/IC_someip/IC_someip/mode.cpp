#include "mode.h"
#include <QDebug>
Mode::Mode(QObject *parent) : QObject(parent), qt_mode("#A2F2D9"){

}
void Mode::receiveMode(int32_t signal){
    if(signal == 0){
        qt_mode = "#A2F2D9";
        qDebug() << "Cpp value: " << qt_mode;
        emit modeValueChanged();
    }else if(signal == 1){
        qt_mode = "#411414";
        qDebug() << "Cpp value: " << qt_mode;
        emit modeValueChanged();
    }else if(signal == 2){
        qt_mode = "#120102";
        qDebug() << "Cpp value: " << qt_mode;
        emit modeValueChanged();
    }else
    qDebug()<<"MODE"<<qt_mode;
}
