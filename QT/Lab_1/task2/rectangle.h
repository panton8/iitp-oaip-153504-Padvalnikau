#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QCursor>
#include <QKeyEvent>


class Rectangle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Rectangle(short width = 0, short height = 0,
                           double RotationAngle = 0,
                           short r = rand()%255, short g = rand()%255, short b = rand()%255,
                           QObject *parent = nullptr) : QObject (parent) {
            size = 1;

            this->width = width; this->height = height;
            degree = RotationAngle;

            this->r = r; this->g = g; this->b = b;

            DefaultSize = width > height ? width : height;
        }
    ~Rectangle() {}

private:

    short width, height;
    double size;
    double DefaultSize;

    double degree;

    short r, g, b;

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent *event);


    virtual void mousePressEvent (QGraphicsSceneMouseEvent *event);

    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    virtual void wheelEvent(QGraphicsSceneWheelEvent *event);

public:
    QString getInfo();
};


#endif // RECTANGLE_H

