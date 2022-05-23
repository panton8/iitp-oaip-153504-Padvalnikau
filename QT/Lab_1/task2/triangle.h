#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QCursor>
#include <QtMath>

class Triangle: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Triangle(short x1, short y1, short x2, short y2 ,
             short x3 , short y3, QObject *parent = nullptr);
private:
    short x1, y1, x2, y2, x3, y3;
    double size, degree;

    double DefaultSize;
    double AB, BC, AC;

    short r, g, b;

    QRectF boundingRect() const ;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent *event);

    virtual void mousePressEvent (QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    virtual void wheelEvent(QGraphicsSceneWheelEvent *event);
public:
    QString getInfo ();
};

#endif // TRIANGLE_H
