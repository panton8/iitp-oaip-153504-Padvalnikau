#include "rectangle.h"


QRectF Rectangle::boundingRect() const {
    return QRectF(-DefaultSize-20, -DefaultSize-20, DefaultSize*2+20, DefaultSize*2+20);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->rotate(degree);
    degree += 1;

    painter->setPen(Qt::black);

    if (size < 1) {
        painter->scale(size, size);
    }
    painter->drawRect(-30, -30, width, height);

    painter->drawPoint(QRectF(-30, -30, width, height).center());

    QTimer::singleShot(0, this, SLOT(update()));

    Q_UNUSED(option); Q_UNUSED(widget);
}

void Rectangle:: mouseMoveEvent (QGraphicsSceneMouseEvent *event) {
    this->setPos(mapToScene(event->pos()));
}

void Rectangle::mousePressEvent (QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ClosedHandCursor));

    Q_UNUSED(event);
}

void Rectangle::mouseReleaseEvent (QGraphicsSceneMouseEvent *event) {

    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void Rectangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    delete this;
    Q_UNUSED(event);
}

void Rectangle::wheelEvent(QGraphicsSceneWheelEvent *event) {
    if(event->delta() > 0){
           ++size;
        }else{
            --size;
        }

}

QString Rectangle::getInfo (){
    QString Parametrs = "Total Area: ";
    int S_value = height * width;
    Parametrs += QString::number(S_value);
    QString P = ", Perimeter: ";
    int P_value = 2*(height + width);
    P += QString::number(P_value);
    Parametrs += P;
    QString CentrMass = ", Center of mass coordinates:: (";
    CentrMass += QString::number(double(height/2));
    CentrMass += ", ";
    CentrMass += QString::number(double(width/2));
    CentrMass += ")";
    Parametrs += CentrMass;
    return Parametrs;
   }
