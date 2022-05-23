#ifndef STAR_H
#define STAR_H
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>

class Star : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Star(QObject *parent = nullptr);
  ~Star();
      QString getInfo();
private:
    double degree, size;
    short r, g, b;
    double WindowSize = 500;

    QRectF boundingRect() const ;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent *event);


    virtual void mousePressEvent (QGraphicsSceneMouseEvent *event) ;

    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) ;

    virtual void wheelEvent(QGraphicsSceneWheelEvent *event);



};



#endif // STAR_H
