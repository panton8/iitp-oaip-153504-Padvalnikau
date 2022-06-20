#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table =  new QTableWidget();
}

Set<int> test1;
map<int,int> test2;
un_map<int,int>test3;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){

    int repeat = QInputDialog::getText(this,"Enter the num of inputs:","Amount:",QLineEdit::Normal).toInt();
    while(repeat < 0){
        QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         repeat = QInputDialog::getText(this,"Enter the num of inputs:","Amount:",QLineEdit::Normal).toInt();
    }

    table->setRowCount(repeat + 1);
    table->setColumnCount(1);
    table->resize(750,750);

     QTableWidgetItem *itm1 = new QTableWidgetItem("Keys");
     table->setItem(0, 0, itm1);

    while(repeat){
    int key = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();

         while(!key){
             QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
              key = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();
         }
         test1.insert(key);
         repeat--;
    }
}

void MainWindow::on_pushButton_2_clicked(){
    Set<int>::iterator it = test1.begin();
    int row = 1;
    while(it != test1.end()){
        QString key = QString::number(*it);
        QTableWidgetItem *itm1 = new QTableWidgetItem(key);
        table->setItem(row, 0, itm1);
        ++it;
        row++;
    }
    table->show();

}

void MainWindow::on_pushButton_4_clicked(){
    int repeat = QInputDialog::getText(this,"Enter the num of inputs:","Amount:",QLineEdit::Normal).toInt();
    while(repeat < 0){
        QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         repeat = QInputDialog::getText(this,"Enter the num of inputs:","Amount:",QLineEdit::Normal).toInt();
    }

    table->setRowCount(repeat + 1);
    table->setColumnCount(2);
    table->resize(750,750);

     QTableWidgetItem *itm1 = new QTableWidgetItem("Keys");
     table->setItem(0, 0, itm1);
     QTableWidgetItem *itm2 = new QTableWidgetItem("Values");
     table->setItem(0, 1, itm2);

    while(repeat){
    int key = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();

         while(!key){
             QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
              key = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();
         }

     int value = QInputDialog::getText(this,"Enter the value:","Value:",QLineEdit::Normal).toInt();

              while(!value){
                  QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
                   value = QInputDialog::getText(this,"Enter the value:","Value:",QLineEdit::Normal).toInt();
              }
         test2.insert(std::pair<int, int >(key,value));
         repeat--;
    }

}

void MainWindow::on_pushButton_3_clicked(){
    map<int, int>::iterator it = test2.begin();
    int row = 1;
    while(it != test2.end()){
        QString key = QString::number(it->first);
        QTableWidgetItem *itm1 = new QTableWidgetItem(key);
        QString value = QString::number(it->second);
        QTableWidgetItem *itm2 = new QTableWidgetItem(value);

        table->setItem(row, 0, itm1);
        table->setItem(row, 1, itm2);
        ++it;
        row++;
    }
    table->show();
   }

void MainWindow::on_pushButton_5_clicked(){
    int repeat = QInputDialog::getText(this,"Enter the num of inputs:","Amount:",QLineEdit::Normal).toInt();
    while(repeat < 0){
        QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
         repeat = QInputDialog::getText(this,"Enter the num of inputs:","Amount:",QLineEdit::Normal).toInt();
    }

    table->setRowCount(repeat + 1);
    table->setColumnCount(2);
    table->resize(750,750);

     QTableWidgetItem *itm1 = new QTableWidgetItem("Keys");
     table->setItem(0, 0, itm1);
     QTableWidgetItem *itm2 = new QTableWidgetItem("Values");
     table->setItem(0, 1, itm2);

    while(repeat){
    int key = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();

         while(!key){
             QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
              key = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();
         }

     int value = QInputDialog::getText(this,"Enter the value:","Value:",QLineEdit::Normal).toInt();

              while(!value){
                  QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
                   value = QInputDialog::getText(this,"Enter the value:","Value:",QLineEdit::Normal).toInt();
              }
         test3.insert(key,value);
         repeat--;
    }
}


void MainWindow::on_pushButton_6_clicked(){
        int row = 1;
        for(int i = 0; i < test3.GetSize();i++)
        {
            std::forward_list<std::pair<int,int>> tmp = test3.ReturnList(i);
            for(const std::pair<int,int> &t : tmp)
            {
                QTableWidgetItem *itm1 = new QTableWidgetItem(QString::number(t.first));
                QTableWidgetItem *itm2 = new QTableWidgetItem(QString::number(t.second));
                table->setItem(row,0,itm1);
                table->setItem(row,1,itm2);
                row++;
            }
        }

    table->show();
}


void MainWindow::on_pushButton_7_clicked(){
    int keyS = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();

         while(!keyS){
             QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
              keyS = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();
         }

    Set<int>::iterator it = test1.begin();
    Set<int>::iterator search = test1.find(keyS);
    int row = 1;
    while(it != test1.end()){
        QString key = QString::number(*it);
        QTableWidgetItem *itm1 = new QTableWidgetItem(key);
        table->setItem(row, 0, itm1);
         if(it == search)
             table->item(row, 0)->setBackground(Qt::red);
        ++it;
        row++;
    }
    table->show();
}

void MainWindow::on_pushButton_8_clicked(){
    int keyS = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();

         while(!keyS){
             QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
              keyS = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();
         }

         map<int, int>::iterator it = test2.begin();
         map<int,int>::iterator search = test2.find(keyS);
         int row = 1;
         while(it != test2.end()){
             QString key = QString::number(it->first);
             QTableWidgetItem *itm1 = new QTableWidgetItem(key);
             QString value = QString::number(it->second);
             QTableWidgetItem *itm2 = new QTableWidgetItem(value);

             table->setItem(row, 0, itm1);
             table->setItem(row, 1, itm2);
             if(it == search){
                 table->item(row, 0)->setBackground(Qt::red);
                 table->item(row, 1)->setBackground(Qt::red);
             }
             ++it;
             row++;
         }

    table->show();
}

void MainWindow::on_pushButton_9_clicked(){
    int keyS = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();

         while(!keyS){
             QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
              keyS = QInputDialog::getText(this,"Enter the key:","Key:",QLineEdit::Normal).toInt();
         }

    int row = 1;
    for(int i = 0; i < test3.GetSize();i++)
    {
        std::forward_list<std::pair<int,int>> tmp = test3.ReturnList(i);
        for(const std::pair<int,int> &t : tmp)
        {
            QTableWidgetItem *itm1 = new QTableWidgetItem(QString::number(t.first));
            QTableWidgetItem *itm2 = new QTableWidgetItem(QString::number(t.second));
            table->setItem(row,0,itm1);
            table->setItem(row,1,itm2);
             if(keyS == t.first){
                 table->item(row, 0)->setBackground(Qt::red);
                 table->item(row, 1)->setBackground(Qt::red);
             }
            row++;
        }
    }

table->show();
}
