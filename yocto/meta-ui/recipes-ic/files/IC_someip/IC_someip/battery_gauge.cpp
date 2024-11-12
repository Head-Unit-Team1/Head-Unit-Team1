#include "battery_gauge.h"

#include <QPainter>

battery_gauge::battery_gauge(QQuickItem *parent)
    :QQuickPaintedItem(parent),
      m_SpeedometerSize(320), // touch screen is 800 x 480 : 380
      m_StartAngle(50), // 50
      m_AlignAngle(260), // 260
      // it should be 360 - m_StartAngle*3 for good looking
      m_LowestRange(0),
      m_HighestRange(100), // 4000
      m_Battery(50), // 1230
      m_ArcWidth(30),
      m_OuterColor(QColor("#00b890")), // QColor(12,16,247) 00b890
      m_InnerColor(QColor("#a2f2d9")), // QColor(51,88,255,80) a2f2d9
      m_TextColor(QColor("#ffffff")), // QColor(255,255,255)
      m_BackgroundColor(Qt::transparent)
{

}

void battery_gauge::paint(QPainter *painter){
    QRectF rect = this->boundingRect();
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen = painter->pen();
    pen.setCapStyle(Qt::FlatCap);

    double startAngle;
    double spanAngle;

    startAngle = m_StartAngle - 20;
    spanAngle = -40 - m_AlignAngle;

    // outer pie
    painter->save();
    pen.setWidth(m_ArcWidth);
    pen.setColor(m_InnerColor);
    painter->setPen(pen);
//    painter->drawRect(rect);
    painter->drawArc(rect.adjusted(m_ArcWidth, m_ArcWidth, -m_ArcWidth, -m_ArcWidth), startAngle * 16, spanAngle * 16);
    painter->restore();

    // inner pie
//    int pieSize = m_SpeedometerSize/5;
//    painter->save();
//    pen.setColor(m_OuterColor);
//    painter->setBrush(m_InnerColor);
//    painter->drawPie(rect.adjusted(pieSize, pieSize, -pieSize, -pieSize), startAngle * 16, spanAngle * 16);
//    painter->restore();

    // text that shows the value
//    painter->save();
//    QFont font("Halvetica", 52, QFont::Bold);
//    painter->setFont(font);
//    pen.setColor(m_TextColor);
//    painter->setPen(pen);
////    painter->drawText(rect.adjusted(m_SpeedometerSize/30, m_SpeedometerSize/30, -m_SpeedometerSize/30, -m_SpeedometerSize/5),
////                      Qt::AlignCenter, QString::number((m_Speed/40), 'f', 1));
//    painter->drawText(rect.adjusted(m_SpeedometerSize/30, m_SpeedometerSize/2, -m_SpeedometerSize/30, -m_SpeedometerSize/5),
//                      Qt::AlignCenter, QString::number((m_Speed/40), 'f', 1));
//    painter->restore();

    // current progress
    painter->save();
    pen.setWidth(m_ArcWidth);
    pen.setColor(m_OuterColor);
    qreal valueToAngle = ((m_Battery - m_LowestRange)/(m_HighestRange - m_LowestRange)) * spanAngle;
    painter->setPen(pen);
    painter->drawArc(rect.adjusted(m_ArcWidth, m_ArcWidth, -m_ArcWidth, -m_ArcWidth), startAngle * 16, valueToAngle * 16);
    painter->restore();
}

qreal battery_gauge::getspeedometerSize()
{
    return m_SpeedometerSize;
}

qreal battery_gauge::getStartAngle()
{
    return m_StartAngle;
}


qreal battery_gauge::getAlignAngle()
{
    return m_AlignAngle;
}


qreal battery_gauge::getLowestRange()
{
    return m_LowestRange;
}

qreal battery_gauge::getHighestRange()
{
    return m_HighestRange;
}

qreal battery_gauge::getBattery()
{
    return m_Battery;
}

int battery_gauge::getArcWidth()
{
    return m_ArcWidth;
}

QColor battery_gauge::getOuterColor()
{
    return m_OuterColor;
}

QColor battery_gauge::getInnerColor()
{
    return m_InnerColor;
}

QColor battery_gauge::getTextColor()
{
    return m_TextColor;
}

QColor battery_gauge::getBackgroundColor()
{
    return m_BackgroundColor;
}



void battery_gauge::setSpeedometerSize(qreal size)
{
    if(m_SpeedometerSize == size)
        return;
    m_SpeedometerSize = size;

    emit speedometerSizeChanged();
}

void battery_gauge::setStartAngle(qreal startAngle)
{
    if(m_StartAngle == startAngle)
        return;

    m_StartAngle = startAngle;

    emit startAngleChanged();
}

void battery_gauge::setAlignAngle(qreal angle)
{
    if(m_StartAngle == angle)
        return;

    m_StartAngle = angle;

    emit alignAngleChanged();
}

void battery_gauge::setLowestRange(qreal lowestRange)
{
    if(m_LowestRange == lowestRange)
        return;

    m_LowestRange = lowestRange;

    emit lowestRangeChanged();
}

void battery_gauge::setHighestRange(qreal highestRange)
{
    if(m_HighestRange == highestRange)
        return;

    m_HighestRange = highestRange;

    emit highestRangeChanged();
}

void battery_gauge::setBattery(qreal battery)
{
    if(m_Battery == battery)
        return;

    m_Battery = battery;
    update();
    emit batteryChanged();
}

void battery_gauge::setArcWidth(int arcWidth)
{
    if(m_ArcWidth == arcWidth)
        return;

    m_ArcWidth = arcWidth;

    emit arcWidthChanged();
}

void battery_gauge::setOuterColor(QColor outerColor)
{
    if(m_OuterColor == outerColor)
        return;

    m_OuterColor = outerColor;

    emit outerColorChanged();
}

void battery_gauge::setInnerColor(QColor innerColor)
{
    if(m_InnerColor == innerColor)
        return;

    m_InnerColor = innerColor;

    emit innerColorChanged();
}

void battery_gauge::setTextColor(QColor textColor)
{
    if(m_TextColor == textColor)
        return;

    m_TextColor = textColor;

    emit textColorChanged();
}

void battery_gauge::setBackgroundColor(QColor backgroundColor)
{
    if(m_BackgroundColor == backgroundColor)
        return;

    m_BackgroundColor = backgroundColor;

    emit backgroundColorChanged();
}
