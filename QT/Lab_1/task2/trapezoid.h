#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QCursor>


class Trapezoid : public QObject, public QGraphicsItem
{
public:   
    Q_OBJECT
public:
  Trapezoid(QObject *parent = nullptr);
  ~Trapezoid();
      QString getInfo();
private:
    double degree, size;
    short r, g, b;
    double WindowSize = 400;

    QRectF boundingRect() const ;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent *event);


    virtual void mousePressEvent (QGraphicsSceneMouseEvent *event) ;

    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) ;

    virtual void wheelEvent(QGraphicsSceneWheelEvent *event);

};

#endif // TRAPEZOID_H
