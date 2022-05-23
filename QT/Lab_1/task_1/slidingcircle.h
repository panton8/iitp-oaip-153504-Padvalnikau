#ifndef SLIDINGCIRCLE_H
#define SLIDINGCIRCLE_H
#include <QPainter>
#include <QGraphicsObject>
#include <QGraphicsItemGroup>

class SlidingCircle : public QGraphicsObject
{
    Q_OBJECT
public:
    SlidingCircle();
    double x;
    double y;
    double radius;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
public slots:
    void slide_left();
    void slide_right();
};
#endif // SLIDINGCIRCLE_H
