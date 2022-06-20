#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHeaderView>

bitset a;
bitset b;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table =  new QTableWidget();
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->listWidget->addItem(QString::fromStdString(a.toString()));
    ui->listWidget_2->addItem(QString::fromStdString(b.toString()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    unsigned short pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     }

    a.set(pos);
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(a.toString()));
}

void  MainWindow::on_pushButton_2_clicked(){
    unsigned short pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     }

    b.set(pos);
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem(QString::fromStdString(b.toString()));

}

void  MainWindow::on_pushButton_3_clicked(){
    unsigned short pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     }

    a.reset(pos);
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(a.toString()));
}

void  MainWindow::on_pushButton_4_clicked(){
    a.flip();
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(a.toString()));
}

void  MainWindow::on_pushButton_5_clicked(){
    unsigned short pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     }

    b.reset(pos);
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem(QString::fromStdString(b.toString()));
}

void  MainWindow::on_pushButton_6_clicked(){
    b.flip();
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem(QString::fromStdString(b.toString()));
}

void  MainWindow::on_pushButton_7_clicked(){
    table->setRowCount(3);
    table->setColumnCount(7);
     table->resize(750,750);

     QTableWidgetItem *itm0 = new QTableWidgetItem("Bitset");
     table->setItem(0, 0, itm0);

     QTableWidgetItem *itm1 = new QTableWidgetItem("Count");
     table->setItem(0, 1, itm1);

     QTableWidgetItem *itm2 = new QTableWidgetItem("To_Ulong");
     table->setItem(0, 2, itm2);


     QTableWidgetItem *itm3 = new QTableWidgetItem("To_Ullong");
     table->setItem(0, 3, itm3);


     QTableWidgetItem *itm4 = new QTableWidgetItem("~");
     table->setItem(0, 4, itm4);

     QTableWidgetItem *itm5 = new QTableWidgetItem("|");
     table->setItem(0, 5, itm5);

     QTableWidgetItem *itm6 = new QTableWidgetItem("&");
     table->setItem(0, 6, itm6);


     QString bitset1 = QString::fromStdString(a.toString());
     QString bitset2 =  QString::fromStdString(b.toString());

     QString count1 = QString::number(a.count());
     QString count2 = QString::number(b.count());

     QString ul1 =  QString::number(a.to_ulong());
     QString ul2 = QString::number(b.to_ulong());

     QString ull1 = QString::number(a.to_ullong());
     QString ull2 =  QString::number(b.to_ullong());

     bitset temp1 = ~a;
     bitset temp2 = ~b;

    QString not1 = QString::fromStdString(temp1.toString());
    QString not2 = QString::fromStdString(temp2.toString());

    bitset temp3 = a | b;

     QString or1 = QString::fromStdString(temp3.toString());

     bitset temp4 = a & b;

      QString and1 = QString::fromStdString(temp4.toString());

     QTableWidgetItem *r1 = new QTableWidgetItem(bitset1);
     QTableWidgetItem *r2 = new QTableWidgetItem(bitset2);
     QTableWidgetItem *r3 = new QTableWidgetItem(count1);
     QTableWidgetItem *r4 = new QTableWidgetItem(count2);
     QTableWidgetItem *r5 = new QTableWidgetItem(ul1);
     QTableWidgetItem *r6 = new QTableWidgetItem(ul2);
     QTableWidgetItem *r7 = new QTableWidgetItem(ull1);
     QTableWidgetItem *r8 = new QTableWidgetItem(ull2);
     QTableWidgetItem *r9 = new QTableWidgetItem(not1);
     QTableWidgetItem *r10 = new QTableWidgetItem(not2);
     QTableWidgetItem *r11 = new QTableWidgetItem(or1);
     QTableWidgetItem *r12 = new QTableWidgetItem(and1);

     table->setItem(1, 0, r1);
     table->setItem(2, 0, r2);
     table->setItem(1, 1, r3);
     table->setItem(2, 1, r4);
     table->setItem(1, 2, r5);
     table->setItem(2, 2, r6);
     table->setItem(1, 3, r7);
     table->setItem(2, 3, r8);
     table->setItem(1, 4, r9);
     table->setItem(2, 4, r10);
     table->setItem(1, 5, r11);
     table->setItem(1, 6, r12);


     table->show();
}

void  MainWindow::on_pushButton_8_clicked(){
    unsigned short pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     }

    if(a.test(pos))
        QMessageBox::information(ui->centralwidget, "TestInfo", "True");
    else
        QMessageBox::information(ui->centralwidget, "TestInfo", "False");

}

void  MainWindow::on_pushButton_9_clicked(){
    unsigned short pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     while(pos < 0 || pos > 31){
         QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         pos = QInputDialog::getText(this,"Enter position:","Position:",QLineEdit::Normal).toShort();
     }

    if(b.test(pos))
        QMessageBox::information(ui->centralwidget, "TestInfo", "True");
    else
        QMessageBox::information(ui->centralwidget, "TestInfo", "False");
}
