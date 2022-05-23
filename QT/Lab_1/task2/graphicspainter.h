#ifndef GRAPHICSPAINTER_H
#define GRAPHICSPAINTER_H

#include <QWidget>

class GraphicsPainter : public QWidget
{
    Q_OBJECT
public:
    explicit GraphicsPainter(QWidget *parent = nullptr);

    void SetDraw(bool bDraw);

signals:
    void singalDrawOver();

public slots:

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *event);

    bool bDraw;             //drawing state(on/off)
    bool bLeftClick;       //left mouse click(on/off),start to draw
    bool bMove;             // mouse in drawing state(on/off)

    QVector<QPointF> pointList;
    QPointF movePoint;
};

#endif // GRAPHICSPAINTER_H
