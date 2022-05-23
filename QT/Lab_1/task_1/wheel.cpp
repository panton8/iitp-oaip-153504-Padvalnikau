#include "wheel.h"
#include <mainwindow.h>

Wheel::Wheel() : SlidingCircle()
{
    x = 0;
    y = 0;
    radius = 80;
    rotate = false;
}

void Wheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(rotate){
    painter->setPen(QPen(Qt::black,radius/8));
    painter->drawEllipse(x, y, radius, radius);
    painter->setPen(QPen(Qt::black,radius/8));
    painter->drawEllipse(x + 35, y + 35, 10, 10);
    painter->setPen(QPen(Qt::black,radius/15));
    painter->drawLine(x + 25, y + 10, x + 55, y + 75);
    painter->drawLine(x + 75, y + 20, x + 5, y + 60);
    painter->drawLine(x + 55, y + 5, x + 25, y + 75);
    painter->drawLine(x + 5, y + 25, x + 75, y + 55);
    }
    else{
        painter->setPen(QPen(Qt::black,radius/8));
        painter->drawEllipse(x, y, radius, radius);
        painter->setPen(QPen(Qt::black,radius/8));
        painter->drawEllipse(x + 35, y + 35, 10, 10);
        painter->setPen(QPen(Qt::black,radius/15));
        painter->drawLine(x + 15, y + 15, x + 65, y + 65);
        painter->drawLine(x + 65, y + 15, x + 15, y + 65);
        painter->drawLine(x + 40, y + 5, x + 40, y + 75);
        painter->drawLine(x + 5, y + 40, x + 75, y + 40);
    }
    update();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Wheel::boundingRect() const
{
    return QRectF ( x-50,y-50,500,200);
 }

void Wheel::toRotate()
{
    update();
}
