#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

 Deque<int> testDeque;

void MainWindow::on_pushButton_clicked()
{
    int input = QInputDialog::getText(this,"Enter the value:","Value:",QLineEdit::Normal).toInt();
    while(!input){
        QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
        input = QInputDialog::getText(this,"Enter the value:","Value:",QLineEdit::Normal).toInt();
    }
    testDeque.PushBack(input);
    ui->listWidget->clear();
    for(int i = 0; i < testDeque.Size(); i++)
        ui->listWidget->addItem(QString::number((testDeque.FromFront(i))->Data()));
}


void MainWindow::on_pushButton_2_clicked()
{
    int input = QInputDialog::getText(this,"Enter the value:","Value:",QLineEdit::Normal).toInt();
    while(!input){
        QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
        input = QInputDialog::getText(this,"Enter the value:","Value:",QLineEdit::Normal).toInt();
    }
    testDeque.PushFront(input);
    ui->listWidget->clear();
    for(int i = 0; i < testDeque.Size(); i++)
        ui->listWidget->addItem(QString::number((testDeque.FromFront(i))->Data()));
}


void MainWindow::on_pushButton_3_clicked()
{    if(testDeque.IsEmpty())
        QMessageBox::warning(ui->centralwidget, "Error", "Deque is empty\nNothing to delete");
    else{
    testDeque.PopBack();
    ui->listWidget->clear();
    for(int i = 0; i < testDeque.Size(); i++)
        ui->listWidget->addItem(QString::number((testDeque.FromFront(i))->Data()));
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(testDeque.IsEmpty())
        QMessageBox::warning(ui->centralwidget, "Error", "Deque is empty\nNothing to delete");
    else{
    testDeque.PopFront();
    ui->listWidget->clear();
    for(int i = 0; i < testDeque.Size(); i++)
        ui->listWidget->addItem(QString::number((testDeque.FromFront(i))->Data()));
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    if(testDeque.IsEmpty())
        QMessageBox::warning(ui->centralwidget, "Error", "Deque is empty\nNothing to delete");
    else{
        testDeque.Clear();
        ui->listWidget->clear();
        for(int i = 0; i < testDeque.Size(); i++)
            ui->listWidget->addItem(QString::number((testDeque.FromFront(i))->Data()));
        }
}

