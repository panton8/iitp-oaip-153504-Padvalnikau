#include "star.h"
Star::Star(QObject *parent) : QObject (parent),
    degree(0), size(1), r(rand()%255), g(rand()%255), b(rand()%255) {}

Star::~Star() {}

QRectF Star::boundingRect() const {
    return QRectF(-WindowSize*2, -WindowSize*2, WindowSize*4, WindowSize*4);
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

        painter->rotate(degree);
        degree += 1;

        painter->setPen(Qt::black);

        QPolygon poly;
        poly<<QPoint(200,50)<<QPoint(250,300)<<QPoint(100, 150) << QPoint(300, 150)
           << QPoint(150, 300)<<QPoint(200, 50);
        if (size < 1) {
            painter->scale(size, size);
            //prepareGeometryChange();
        }

        painter->drawPoint(boundingRect().center());

        painter->drawPolygon(poly);

        QTimer::singleShot(0, this, SLOT(update()));

        Q_UNUSED(option); Q_UNUSED(widget);
    }

void Star::mouseMoveEvent (QGraphicsSceneMouseEvent *event) {
    this->setPos(mapToScene(event->pos()));
}


void Star::mousePressEvent (QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ClosedHandCursor));

    Q_UNUSED(event);
}

void Star::mouseReleaseEvent (QGraphicsSceneMouseEvent *event) {

    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void Star::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    delete this;
    Q_UNUSED(event);
}

    void Star::wheelEvent(QGraphicsSceneWheelEvent *event) {
        if(event->delta() > 0){
               ++size;
            }else{
                --size;
            }

}

QString Star::getInfo (){
        QString Parametrs = "Total Area: ";
        int S_value = 17500;
        Parametrs += QString::number(S_value);
        QString P = " Perimeter: ";
        int P_value = 1165;
        P += QString::number(P_value);
        Parametrs += P;
        QString CentrMass = ", Center of mass coordinates: (";
        CentrMass += "200.0";
        CentrMass += ", ";
        CentrMass += "100.0";
        CentrMass += ")";
        Parametrs += CentrMass;
        return Parametrs;
       }
