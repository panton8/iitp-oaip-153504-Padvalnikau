#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     table =  new QTableWidget();
     t = new Tree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool click = false;
bool click2 = false;

void MainWindow::on_pushButton_clicked()
{
    click = true;

   short row = QInputDialog::getText(this,"Enter number of people:","Num of people(1-22):",QLineEdit::Normal).toShort();

    while(row < 1 || row > 22){
        QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
        row = QInputDialog::getText(this,"Enter number of people:","Num of people(1-22):",QLineEdit::Normal).toShort();
    }

    table->setRowCount(row + 1);
    table->setColumnCount(4);
     table->resize(750,750);

     QTableWidgetItem *itm1 = new QTableWidgetItem("Surname");
     table->setItem(0, 0, itm1);


     QTableWidgetItem *itm2 = new QTableWidgetItem("Name");
     table->setItem(0, 1, itm2);


     QTableWidgetItem *itm3 = new QTableWidgetItem("Patronymic");
     table->setItem(0, 2, itm3);


     QTableWidgetItem *itm4 = new QTableWidgetItem("Passport ID");
     table->setItem(0, 3, itm4);

     QFile file("C:\\people.txt");
     if(!file.open(QIODevice::ReadOnly))
         qWarning("Can't open file for reading");
     file.open(QFile::ReadOnly);
     QTextStream in(&file);

     for(int i = 0; i < row; i++)
{
         QString Surname = file.readLine();
         QString Name = file.readLine();
         QString Patronymic = file.readLine();
         QString PassportID = file.readLine();

         Surname = Surname.replace(Surname.length() - 2,2,"");
         Name = Name.replace(Name.length() - 2,2,"");
         Patronymic = Patronymic.replace(Patronymic.length() - 2,2,"");
         PassportID = PassportID.replace(PassportID.length() - 2,2,"");


         QTableWidgetItem *itm0 = new QTableWidgetItem(Surname);
         QTableWidgetItem *itm1 = new QTableWidgetItem(Name);
         QTableWidgetItem *itm2 = new QTableWidgetItem(Patronymic);
         QTableWidgetItem *itm3 = new QTableWidgetItem(PassportID);

         table->setItem(i + 1, 0, itm0);
         table->setItem(i + 1, 1, itm1);
         table->setItem(i + 1, 2, itm2);
         table->setItem(i + 1, 3, itm3);
}
}


void MainWindow::on_pushButton_2_clicked()
{
    t->removeAll();
    click2 = true;
    int row = table->rowCount() - 1;
    if(click){ 
     for(int i = 0; i < row; i++){
        QString Surname = table->item(i + 1, 0)->text();
        QString Name = table->item(i + 1, 1)->text();
        QString Patronymic = table->item(i +1, 2)->text();
        QString PassportID = table->item(i+ 1, 3)->text();

        t->insert(Surname,Name,Patronymic,PassportID);
}
   }
    else
         QMessageBox::warning(ui->centralwidget, "Error", "Full the table");

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    QString surname= QInputDialog::getText(this,"Enter surname:","Surname:",QLineEdit::Normal);

         while(surname.toInt() || surname.isEmpty()){
             QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
              surname= QInputDialog::getText(this,"Enter surname:","Surname:",QLineEdit::Normal);
         }

    QString answer =  t->search(surname);

    ui->listWidget->addItem(answer);
}

void MainWindow::on_pushButton_4_clicked()
{
    static int count = 0;
    if(!click2)
        QMessageBox::warning(ui->centralwidget, "Error", "Your tree is empty");
    else{
        for(int i = 1; i <= t->totalLevel() + 1;i++){
        short dif = t->task(i);
        short temp = 0;
        if(count > 0)
            temp = t->task(i) - dif;
        else
            temp = t->task(i);
        QString level = "Level " + QString::number(i) + " :";
        QString ans = QString::number(temp) + " leaves";
        ui->listWidget->addItem(level);
        ui->listWidget->addItem(ans);
        count++;
    }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString surname= QInputDialog::getText(this,"Enter surname:","Surname:",QLineEdit::Normal);

         while(surname.toInt() || surname.isEmpty()){
             QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
              surname= QInputDialog::getText(this,"Enter surname:","Surname:",QLineEdit::Normal);
         }

     QString name= QInputDialog::getText(this,"Enter name:","Name:",QLineEdit::Normal);

              while(name.toInt() || name.isEmpty()){
                  QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
                   name= QInputDialog::getText(this,"Enter Name:","Name:",QLineEdit::Normal);
              }

    QString patronymic = QInputDialog::getText(this,"Enter patronymic:","Patronymic:",QLineEdit::Normal);

              while(patronymic.toInt() || patronymic.isEmpty()){
                  QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
                  patronymic = QInputDialog::getText(this,"Enter patronymic:","Patronymic:",QLineEdit::Normal);
              }

    QString passportID = QInputDialog::getText(this,"Enter passportID:","passportID:",QLineEdit::Normal);

              while(passportID.toInt() || passportID.isEmpty()){
                  QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
                  passportID = QInputDialog::getText(this,"Enter passportID:","passportID:",QLineEdit::Normal);
              }

              t->insert(surname, name, patronymic, passportID);
}

void MainWindow::on_pushButton_6_clicked()
{

    QString output;

    t->preorderPrint(output);

    ui->listWidget->clear();

    ui->listWidget->addItem(output);

}

void MainWindow::on_pushButton_7_clicked()
{

    QString output;

    t->inorderPrint(output);

    ui->listWidget->clear();

    ui->listWidget->addItem(output);

}

void MainWindow::on_pushButton_8_clicked()
{
    QString output;

    t->postorderPrint(output);

    ui->listWidget->clear();

    ui->listWidget->addItem(output);


}

void MainWindow::on_pushButton_9_clicked()
{
    table->show();
}

void MainWindow::on_pushButton_10_clicked()
{
    QString vizual;
    t->disp(t->totalLevel(),vizual);
    ui->listWidget->clear();
    ui->listWidget->addItem(vizual);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->listWidget->clear();
}

void MainWindow::on_pushButton_12_clicked()
{
    QString surname= QInputDialog::getText(this,"Enter surname:","Surname:",QLineEdit::Normal);

         while(surname.toInt() || surname.isEmpty()){
             QMessageBox::warning(ui->centralwidget, "Input error", "Check your input");
              surname= QInputDialog::getText(this,"Enter surname:","Surname:",QLineEdit::Normal);
         }

    t->removeNode(surname);
}
