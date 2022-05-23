#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pos = 0;
    ui->lineEdit->setInputMask("999");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::outStack()
{
    ui->plainTextEdit->clear();

    for (int i = 0; i < dl->getLength(); i++) {
        ui->plainTextEdit->appendPlainText(QString::number(dl->getData(i)));
    }


}

void MainWindow::on_pushButton_clicked()
{
    if ((ui->lineEdit->text()) == "\0") {
        QMessageBox::critical(this, "Error!", "Nothing to add");
        return;
    }
    int val = (ui->lineEdit->text()).toInt();
    dl->add(val);
    outStack();
}


void MainWindow::on_pushButton_2_clicked()
{
    if (dl->getLength() == 0) {
        QMessageBox::critical(this, "Error!", "Nothing to delete");
        return;
    }
    dl->popback();
    outStack();
}
