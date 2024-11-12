#include "lrsign.h"

LRSign::LRSign(QObject* parent) : QObject(parent)
{

}


void LRSign::sendLrsignRandom(int32_t changedDirection){
    if (qt_direction == changedDirection)
        changedDirection = 0;
    qt_direction = changedDirection;
    emit directionValueChanged();
    emit broadcastDirection(qt_direction);
}
