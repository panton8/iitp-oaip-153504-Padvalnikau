#include "trapezoid.h"




Trapezoid::Trapezoid(QObject *parent) : QObject (parent),
    degree(0), size(1), r(rand()%255), g(rand()%255), b(rand()%255) {}

Trapezoid::~Trapezoid() {}

QRectF Trapezoid::boundingRect() const {
    return QRectF(-WindowSize*2, -WindowSize*2, WindowSize*4, WindowSize*4);
}

void Trapezoid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

        painter->rotate(degree);
        degree += 1;

        painter->setPen(Qt::black);

        QPolygon poly;
        poly<<QPoint(80, 0)<<QPoint(220, 0)<<QPoint(300, 250) << QPoint(0, 250)
           << QPoint(80, 0);

        if (size < 1) {
            painter->scale(size, size);
            //prepareGeometryChange();
        }

        painter->drawPoint(boundingRect().center());

        painter->drawPolygon(poly);

        QTimer::singleShot(0, this, SLOT(update()));

        Q_UNUSED(option); Q_UNUSED(widget);
    }

void Trapezoid::mouseMoveEvent (QGraphicsSceneMouseEvent *event) {
    this->setPos(mapToScene(event->pos()));
}


void Trapezoid::mousePressEvent (QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ClosedHandCursor));

    Q_UNUSED(event);
}

void Trapezoid::mouseReleaseEvent (QGraphicsSceneMouseEvent *event) {

    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void Trapezoid::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    delete this;
    Q_UNUSED(event);
}

    void Trapezoid::wheelEvent(QGraphicsSceneWheelEvent *event) {
        if(event->delta() > 0){
               ++size;
            }else{
                --size;
            }

}

QString Trapezoid::getInfo (){
        QString Parametrs = "Total Area: ";
        int S_value = 55000;
        Parametrs += QString::number(S_value);
        QString P = " Perimeter: ";
        int P_value = 965;
        P += QString::number(P_value);
        Parametrs += P;
        QString CentrMass = ", Center of mass coordinates: (";
        CentrMass += "150.0";
        CentrMass += ", ";
        CentrMass += "125";
        CentrMass += ")";
        Parametrs += CentrMass;
        return Parametrs;
       }
