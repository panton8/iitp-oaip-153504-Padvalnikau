#ifndef HEXAGON_H
#define HEXAGON_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QCursor>
#include <QtMath>

class Hexagon : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Hexagon(QObject *parent = nullptr);
  ~Hexagon();
      QString getInfo();
private:
    double degree, size;
    short r, g, b;
    double DefaultSize = 350;

    QRectF boundingRect() const ;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent *event);


    virtual void mousePressEvent (QGraphicsSceneMouseEvent *event) ;

    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) ;

    virtual void wheelEvent(QGraphicsSceneWheelEvent *event);



};


#endif // HEXAGON_H
