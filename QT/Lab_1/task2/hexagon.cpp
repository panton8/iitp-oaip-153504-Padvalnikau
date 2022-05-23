#include "hexagon.h"

Hexagon::Hexagon(QObject *parent) : QObject (parent),
    degree(0), size(1), r(rand()%255), g(rand()%255), b(rand()%255) {}

Hexagon::~Hexagon() {}

QRectF Hexagon::boundingRect() const {
    return QRectF(-DefaultSize*2, -DefaultSize*2, DefaultSize*4, DefaultSize*4);
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

        painter->rotate(degree);
        degree += 1;

        painter->setPen(Qt::black);

        QPolygon poly;
        poly<<QPoint(100, 0)<<QPoint(300, 0)<<QPoint(400, 100) << QPoint(300, 200)
           << QPoint(100, 200) << QPoint(0, 100) << QPoint(100, 0);

        if (size < 1) {
            painter->scale(size, size);
            //prepareGeometryChange();
        }

        painter->drawPoint(boundingRect().center());

        painter->drawPolygon(poly);

        QTimer::singleShot(0, this, SLOT(update()));

        Q_UNUSED(option); Q_UNUSED(widget);
    }

void Hexagon::mouseMoveEvent (QGraphicsSceneMouseEvent *event) {
    this->setPos(mapToScene(event->pos()));
}


void Hexagon::mousePressEvent (QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ClosedHandCursor));

    Q_UNUSED(event);
}

void Hexagon::mouseReleaseEvent (QGraphicsSceneMouseEvent *event) {

    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void Hexagon::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    delete this;
    Q_UNUSED(event);
}

    void Hexagon::wheelEvent(QGraphicsSceneWheelEvent *event) {
        if(event->delta() > 0){
               ++size;
            }else{
                --size;
            }

}

QString Hexagon::getInfo (){
        QString Parametrs = "Total Area: ";
        int S_value = 34100;
        Parametrs += QString::number(S_value);
        QString P = " Perimeter: ";
        int P_value = 682;
        P += QString::number(P_value);
        Parametrs += P;
        QString CentrMass = ", Center of mass coordinates: (";
        CentrMass += "100.0";
        CentrMass += ", ";
        CentrMass += QString::number(double(200*sin(M_PI/3)));
        CentrMass += ")";
        Parametrs += CentrMass;
        return Parametrs;
       }
