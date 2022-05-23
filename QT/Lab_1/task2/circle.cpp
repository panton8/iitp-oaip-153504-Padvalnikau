#include "circle.h"

Circle::Circle(short R, QObject *parent) : QObject (parent){

    size = 1;
    this->R = static_cast<double>(R);
    r = rand()%255; g = rand()%255; b = rand()%255;
}

QRectF Circle:: boundingRect() const {
    return QRectF(-R, -R, R*1.5, R*1.5);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->setPen(Qt::black);

    if (size < 1)
        painter->scale(size, size);

    painter->drawPoint(boundingRect().center());

    painter->drawEllipse(boundingRect());

    QTimer::singleShot(0, this, SLOT(update()));

    Q_UNUSED(option); Q_UNUSED(widget);
}

    void Circle:: mouseMoveEvent (QGraphicsSceneMouseEvent *event) {
    this->setPos(mapToScene(event->pos()));
}

    void Circle::mousePressEvent (QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ClosedHandCursor));

    Q_UNUSED(event);
}

    void Circle:: mouseReleaseEvent (QGraphicsSceneMouseEvent *event) {
        this->setCursor(QCursor(Qt::ArrowCursor));
        Q_UNUSED(event);
    }

    void Circle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
        delete this;
        Q_UNUSED(event);
    }

    void Circle::wheelEvent(QGraphicsSceneWheelEvent *event) {
        if(event->delta() > 0){
               ++size;
            }else{
                --size;
            }

    }

    QString Circle::getInfo (){
        QString Parametrs = "Total Area:";

        int S_value = M_PI * R * R;
        Parametrs += QString::number(S_value);
        QString P = ", Perimeter: ";
        int P_value = 2 * M_PI * R;
        P += QString::number(P_value);
        Parametrs += P;
        QString CentrMass = ",Center of mass coordinates: (";
        CentrMass += QString::number(double(R/2));
        CentrMass += ", ";
        CentrMass += QString::number(double(R/2));
        CentrMass += ")";
        Parametrs += CentrMass;
        return Parametrs;
       }
