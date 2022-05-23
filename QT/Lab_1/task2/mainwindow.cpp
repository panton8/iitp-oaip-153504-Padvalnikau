#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0, 0, 600, 700, this);
    ui->graphicsView->setScene(scene);

    //dialog windows to get parametrs:
    RectWnd = new QDialog(this);
    SquareWnd = new QDialog(this);
    TriangleWnd = new QDialog(this);
    StarWnd = new QDialog(this);
    CircleWnd = new QDialog(this);

    InputWidth = new QLabel("Width:", RectWnd); InputWidth->adjustSize();
    InputHeight = new QLabel("Length:", RectWnd); InputHeight->adjustSize();
    InputSquareWidth = new QLabel("Width:", SquareWnd); InputSquareWidth->adjustSize();
    InputR = new QLabel("Radius:", CircleWnd); InputR->adjustSize();
    InputX1 = new QLabel("Х1:", TriangleWnd); InputX1->adjustSize();
    InputX2 = new QLabel("Х2:", TriangleWnd); InputX2->adjustSize();
    InputX3 = new QLabel("Х3:", TriangleWnd); InputX3->adjustSize();
    InputY1 = new QLabel("У1:", TriangleWnd); InputY1->adjustSize();
    InputY2 = new QLabel("У2:", TriangleWnd); InputY2->adjustSize();
    InputY3 = new QLabel("У3:", TriangleWnd); InputY3->adjustSize();

    //to input parametrs:
    LE_Height = new QLineEdit(RectWnd);
    LE_Width = new QLineEdit(RectWnd);
    LE_SquareWidth = new QLineEdit(SquareWnd);
    LE_R = new QLineEdit(CircleWnd);
    LE_X1 = new QLineEdit(TriangleWnd);
    LE_X2 = new QLineEdit(TriangleWnd);
    LE_X3 = new QLineEdit(TriangleWnd);
    LE_Y1 = new QLineEdit(TriangleWnd);
    LE_Y2 = new QLineEdit(TriangleWnd);
    LE_Y3 = new QLineEdit(TriangleWnd);

    Verticles_5 = new QRadioButton(StarWnd);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_AddRect_clicked()
{
    RectWnd->setModal(true);

    RectWnd->resize(300, 300);

    InputWidth->move(100, 100); InputHeight->move(100, 150);
    LE_Width->resize(30, 30); LE_Height->resize(30, 30);
    LE_Width->move(170, 100); LE_Height->move(170, 140);

    Enter = new QPushButton("Create", RectWnd); Enter->adjustSize();
    Enter->move(200, 200);
    connect(Enter, SIGNAL(clicked()), this, SLOT(CreateRect()));

    RectWnd->show();
}

void MainWindow::CreateRect()
{
    QString strHeight = LE_Height->text();
    QString strWidth = LE_Width->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchHeight = reg.match(strHeight);
    QRegularExpressionMatch matchWidth = reg.match(strWidth);

    if (!matchHeight.hasMatch() || !matchWidth.hasMatch())
        QMessageBox::critical(RectWnd, "Input error", "Incorrect input");
    else {
        RectWnd->close();
        short width = strWidth.toShort();
        short height = strHeight.toShort();

        Rectangle *rect = new Rectangle(height, width, 0,1,1,0);

        rect->setPos(rand()%700, rand()%800);

        scene->addItem(rect);

        ui->statusbar->showMessage(rect->getInfo());
    }

}


void MainWindow::on_AddSquare_clicked()
{
    SquareWnd->setModal(true);

    SquareWnd->resize(300, 300);

    InputSquareWidth->move(100, 100);
    LE_SquareWidth->resize(30, 30);
    LE_SquareWidth->move(170, 100);

    Enter = new QPushButton("Create", SquareWnd); Enter->adjustSize();
    Enter->move(200, 200);
    connect(Enter, SIGNAL(clicked()), this, SLOT(CreateSquare()));

    SquareWnd->show();
}

void MainWindow::CreateSquare()
{
    QString strWidth = LE_SquareWidth->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchWidth = reg.match(strWidth);

    if (!matchWidth.hasMatch())
        QMessageBox::critical(RectWnd, "Input error", "Incorrect input");
    else {
        SquareWnd->close();
        short width = strWidth.toShort();

        Square *square = new Square(width);

        square->setPos(rand()%600, rand()%700);

        scene->addItem(square);

        ui->statusbar->showMessage(square->getInfo());
    }
}


void MainWindow::on_AddRhombus_clicked()
{
    SquareWnd->setModal(true);

    SquareWnd->resize(300, 300);

    InputSquareWidth->move(100, 100);
    LE_SquareWidth->resize(30, 30);
    LE_SquareWidth->move(170, 100);

    Enter = new QPushButton("Create", SquareWnd); Enter->adjustSize();
    Enter->move(200, 200);
    connect(Enter, SIGNAL(clicked()), this, SLOT(CreateRhombus()));

    SquareWnd->show();
}

void MainWindow::CreateRhombus()
{
    QString strWidth = LE_SquareWidth->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchWidth = reg.match(strWidth);

    if (!matchWidth.hasMatch())
        QMessageBox::critical(RectWnd, "Input error", "Incorrect input");
    else {
        SquareWnd->close();
        short width = strWidth.toShort();

        Rhombus *rhombus = new Rhombus(width);

        rhombus->setPos(rand()%600, rand()%700);

        scene->addItem(rhombus);

        ui->statusbar->showMessage(rhombus->getInfo());
    }
}


void MainWindow::on_AddTriangle_clicked()
{
    TriangleWnd->setModal(true);

    TriangleWnd->resize(300, 300);

    LE_X1->resize(40, 30);
    LE_X2->resize(40, 30);
    LE_X3->resize(40, 30);
    LE_Y1->resize(40, 30);
    LE_Y2->resize(40, 30);
    LE_Y3->resize(40, 30);

    InputX1->move(50, 50); InputY1->move(160, 50);
    InputX2->move(50, 80); InputY2->move(160, 80);
    InputX3->move(50, 110); InputY3->move(160, 110);

    LE_X1->move(90, 50); LE_Y1->move(190, 50);
    LE_X2->move(90, 80); LE_Y2->move(190, 80);
    LE_X3->move(90, 110); LE_Y3->move(190, 110);

    Enter = new QPushButton("Create", TriangleWnd); Enter->adjustSize();
    Enter->move(200, 200);
    connect(Enter, SIGNAL(clicked()), this, SLOT(CreateTriangle()));

    TriangleWnd->show();
}

void MainWindow::CreateTriangle()
{
    QString strX1 = LE_X1->text(), strY1 = LE_Y1->text(),
            strX2 = LE_X2->text(), strY2 = LE_Y2->text(),
            strX3 = LE_X3->text(), strY3 = LE_Y3->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");

    QRegularExpressionMatch matchX1 = reg.match(strX1), matchY1 = reg.match(strY1),
            matchX2 = reg.match(strX2), matchY2 = reg.match(strY2),
            matchX3 = reg.match(strX3), matchY3 = reg.match(strY3);

    if (!matchX1.hasMatch() || !matchY1.hasMatch() ||
            !matchX2.hasMatch() || !matchY2.hasMatch() ||
            !matchX3.hasMatch() || !matchY3.hasMatch())
        QMessageBox::critical(TriangleWnd,  "Input error", "Incorrect input");
    else {
        TriangleWnd->close();
        short x1 = strX1.toShort(), y1 = strY1.toShort(),
                x2 = strX2.toShort(), y2 = strY2.toShort(),
                x3 = strX3.toShort(), y3 = strY3.toShort();

       Triangle *trngl = new Triangle(x1, y1, x2, y2, x3, y3);
       trngl->setPos(rand()%500, rand()%500);

       scene->addItem(trngl);

       ui->statusbar->showMessage(trngl->getInfo());
    }
}


void MainWindow::on_AddCircle_clicked()
{
    CircleWnd->setModal(true);

    CircleWnd->resize(300, 300);

    InputR->move(100, 100);
    LE_R->resize(30, 30);
    LE_R->move(170, 100);

    Enter = new QPushButton("Create", CircleWnd); Enter->adjustSize();
    Enter->move(200, 200);
    connect(Enter, SIGNAL(clicked()), this, SLOT(CreateCircle()));

    CircleWnd->show();
}

void MainWindow::CreateCircle()
{
    QString strR = LE_R->text();

    QRegularExpression reg("^\\d+\\d?\\d?$");
    QRegularExpressionMatch matchWidth = reg.match(strR);

    if (!matchWidth.hasMatch())
        QMessageBox::critical(RectWnd,  "Input error", "Incorrect input");
    else {
        CircleWnd->close();

        Circle *crcl = new Circle(strR.toShort());

        crcl->setPos(rand()%600, rand()%700);

        scene->addItem(crcl);

        ui->statusbar->showMessage(crcl->getInfo());
    }
}


void MainWindow::on_AddStar_clicked()
{
    StarWnd->setModal(true);

    StarWnd->resize(300, 300);

    QLabel *Text_5 = new QLabel("5", StarWnd); Text_5->adjustSize();
    Text_5->move(200, 100);

    Verticles_5->move(170, 100);

    connect(Verticles_5, SIGNAL(clicked()), this, SLOT(SetVerticles_5()));

    Enter = new QPushButton("Create", StarWnd); Enter->adjustSize();
    Enter->move(200, 240);

    connect(Enter, SIGNAL(clicked()), this, SLOT(CreateStar()));

    StarWnd->show();
}

void MainWindow::CreateStar()
{
        StarWnd->close();

        Star *star = new Star();

        star->setPos(rand()%600, rand()%700);

        scene->addItem(star);

        ui->statusbar->showMessage(star->getInfo());
    }

void MainWindow::SetVerticles_5()
{
    verticles = 5;
}

void MainWindow::on_AddHexagon_clicked()
{
    Hexagon *hexagon = new Hexagon();

    hexagon->setPos(rand()%150, rand()%300);

    scene->addItem(hexagon);

    ui->statusbar->showMessage(hexagon->getInfo());
}


void MainWindow::on_pushButton_clicked()
{
    QDialog *canvasWnd = new QDialog(this);
    canvasWnd->setModal(true);

    canvasWnd->resize(800, 800);

    GraphicsPainter *canvas = new GraphicsPainter(canvasWnd);
    canvas->resize(600, 600);
    canvas->SetDraw(true);
    canvasWnd->show();
}




void MainWindow::on_AddTrapezoid_clicked()
{
    Trapezoid *trapezoid = new Trapezoid();

    trapezoid->setPos(rand()%150, rand()%300);

    scene->addItem(trapezoid);

    ui->statusbar->showMessage(trapezoid->getInfo());
}

