#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    // Свойство текущего типа используемой фигуры
    Q_PROPERTY(int typeFigure
               READ typeFigure WRITE setTypeFigure
               NOTIFY typeFigureChanged)

public:
    explicit PaintScene(QObject *parent = nullptr);
    ~PaintScene();

    int typeFigure() const;                 // Возвращение текущего типа
    void setTypeFigure(const int type);     // Установка текущего типа

    // Перечисление типов используемых фигур
    enum FigureTypes {
        RectangleType,
        RombType,
        TriangleType,
        CircleType,
        HexagonType,
        StarType,
        SquareType
    };

signals:
    void typeFigureChanged();               // Сигнал об изменении типа текущей фигуры

private:
    /* Объект для временного хранения рисуемой фигуры
     * Является объектом базового класса для всех трёх типов фигур в примере
     * */
    Figure *tempFigure;
    int m_typeFigure;   // текущий тип фигуры

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE\_H
