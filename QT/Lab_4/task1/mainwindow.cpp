#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <utility>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::pair<int, int> pr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

