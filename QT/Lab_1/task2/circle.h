#ifndef CIRCLE_H
#define CIRCLE_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QCursor>
#include <QtMath>


class Circle: public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Circle(short  R, QObject *parent = nullptr);

private:
    short r, g, b;
    double R;
    double size;

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;

    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent *event);

    virtual void mousePressEvent (QGraphicsSceneMouseEvent *event);

    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    virtual void wheelEvent(QGraphicsSceneWheelEvent *event);
public:
    QString getInfo ();
};

#endif // CIRCLE_H
