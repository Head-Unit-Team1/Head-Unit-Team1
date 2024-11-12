#include "mode.h"
#include <QDebug>
Mode::Mode(QObject *parent) : QObject(parent){

}
void Mode::receiveMode(int32_t signal){
    if(signal == 0){
        qt_mode = "A2F2D9";
    }else if(signal == 1){
        qt_mode = "#411414";
    }else if(signal == 2){
        qt_mode = "#120102";
    }
    qDebug()<<"MODE"<<qt_mode;
    emit modeValueChanged();
}
