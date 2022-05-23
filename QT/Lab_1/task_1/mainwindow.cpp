#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    slidingCircle = new SlidingCircle;
    timer = new QTimer;
    wheel = new  Wheel;
    ui->graphicsView->setScene(scene);
    scene->addItem( wheel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    connect(timer,SIGNAL(timeout()), wheel,SLOT(slide_left()));
    timer->start(25);
}


void MainWindow::on_pushButton_2_clicked()
{
    connect(timer,SIGNAL(timeout()), wheel,SLOT(slide_right()));
    timer->start(25);

}


void MainWindow::on_pushButton_3_clicked()
{
    if( wheel->rotate == true)
         wheel->rotate = false;
    else
         wheel->rotate = true;
}


