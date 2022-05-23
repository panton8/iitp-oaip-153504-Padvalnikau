#include "slidingcircle.h"

SlidingCircle::SlidingCircle()
{
    x = 0;
    y = 0;
    radius = 80;
}

void SlidingCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black,radius/10));
    painter->drawEllipse(x, y, radius, radius);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF SlidingCircle::boundingRect() const
{
    return QRectF(x-50,y-50,500,200);
}

void SlidingCircle::slide_left()
{
    if(x <= -300){
        x = 600;
        update();
    }
    else{
        --x;
        update();
    }
}

void SlidingCircle::slide_right()
{
    if(x >= 600){
            x = -200;
            update();
        }
    else{
        ++x;
        update();
    }
}
