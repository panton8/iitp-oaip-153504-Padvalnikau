#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QRegularExpression>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include <QGraphicsScene>
#include "square.h"
#include "rectangle.h"
#include "triangle.h"
#include "star.h"
#include "circle.h"
#include "rhombus.h"
#include "graphicspainter.h"
#include "hexagon.h"
#include "trapezoid.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddRect_clicked();
    void CreateRect();

    void on_AddSquare_clicked();
    void CreateSquare();

    void on_AddRhombus_clicked();
    void CreateRhombus();

    void on_AddTriangle_clicked();
    void CreateTriangle();

    void on_AddCircle_clicked();
    void CreateCircle();

    void on_AddStar_clicked();
    void CreateStar();
    void SetVerticles_5();

    void on_AddHexagon_clicked();

    void on_pushButton_clicked();

    void on_AddTrapezoid_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    QPushButton *Enter;

    //rectangle parametrs:
    QDialog *RectWnd;
    QLabel *InputWidth, *InputHeight;
    QLineEdit *LE_Width, *LE_Height;

    short width, heigh;

    //square and rhombus parametrs:
    QDialog *SquareWnd;
    QLabel *InputSquareWidth;
    QLineEdit *LE_SquareWidth;

    //triangle parametrs:
    QDialog *TriangleWnd;
    QLabel *InputX1, *InputX2, *InputX3, *InputY1, *InputY2, *InputY3;
    QLineEdit *LE_X1, *LE_X2, *LE_X3, *LE_Y1, *LE_Y2, *LE_Y3;

    short x1, y1, x2, y2, x3, y3;

    //star parametrs;
    QDialog *StarWnd;
    QRadioButton *Verticles_5;

    short verticles = 0;

    //circle parametrs:
    QDialog *CircleWnd;
    QLabel *InputR;
    QLineEdit *LE_R;

};
#endif // MAINWINDOW_H
