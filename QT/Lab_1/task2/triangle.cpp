#include "triangle.h"

Triangle::Triangle(short x1, short y1, short x2, short y2, short x3, short y3, QObject *parent) : QObject (parent) {

          this->x1 = x1; this->y1 = y1;
          this->x2 = x2; this->y2 = y2;
          this->x3 = x3; this->y3 = y3;

           size = 1; degree = 0;

           r = rand()%255;
           g = rand()%255;
           b = rand()%255;

           AB = sqrt(pow((x1 - x2), 2)+pow((y1 - y2), 2));
           BC = sqrt(pow((x2 - x3), 2)+pow((y2 - y3), 2));
           AC = sqrt(pow((x1 - x3), 2)+pow((y1 - y3), 2));

           DefaultSize = AB > BC ? AB : BC;
           DefaultSize = DefaultSize > AC? DefaultSize : AC;
}


QRectF Triangle::boundingRect() const {
    return QRectF(-DefaultSize*2, -DefaultSize*2, DefaultSize*4, DefaultSize*4);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->rotate(degree);
    degree += 1;

    painter->setPen(Qt::black);

    QPolygon poly;
    poly<<QPoint(x1,y1)<<QPoint(x2,y2)<<QPoint(x3,y3);

    if (size < 1) {
        painter->scale(size, size);
    }

    painter->drawPoint(boundingRect().center());

    painter->drawPolygon(poly);

    QTimer::singleShot(0, this, SLOT(update()));

    Q_UNUSED(option); Q_UNUSED(widget);
}


    void Triangle::mouseMoveEvent (QGraphicsSceneMouseEvent *event) {
    this->setPos(mapToScene(event->pos()));
}


    void Triangle::mousePressEvent (QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ClosedHandCursor));

    Q_UNUSED(event);
}

    void Triangle::mouseReleaseEvent (QGraphicsSceneMouseEvent *event) {

    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

    void Triangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    delete this;
    Q_UNUSED(event);
}

    void Triangle::wheelEvent(QGraphicsSceneWheelEvent *event) {
        if(event->delta() > 0){
               ++size;
            }else{
                --size;
            }

}

    QString Triangle::getInfo(){
        QString Parametrs = "Total Area: ";

        int p = (AB + BC + AC)/2;

        int S_value = sqrt(p*(p - AB)*(p-AC)*(p-AC));
        Parametrs += QString::number(S_value);
        QString P = ",Perimeter: ";
        int P_value = AB + BC + AC;
        P += QString::number(P_value);
        Parametrs += P;
        QString CentrMass = ",Center of mass coordinates: (";
        CentrMass += QString::number(double(x1 + x2 + x3/3));
        CentrMass += ", ";
        CentrMass += QString::number(double(y1 + y2 + 3/3));
        CentrMass += ")";
        Parametrs += CentrMass;
        return Parametrs;
       }
