#ifndef WHEEL_H
#define WHEEL_H
#include "slidingcircle.h"
#include <QPainter>

class Wheel : public SlidingCircle
{
public:
    Wheel();
    bool rotate;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
public slots:
    void toRotate();
};

#endif // WHEEL_H
