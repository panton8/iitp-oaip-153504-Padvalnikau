#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    atsList = new ATS*[25];
    Head = -1;
    Tail = -1;
    available = new bool[25];
    for(int i = 0; i < 25; i++)
        available[i] = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getAvailableIndex()
{
    for(int i =0; i < 25; i++){
        if(available[i] == true){
            available[i] = false;
            return i;
        }
    }
}

void MainWindow::addInTail(ATS** atsList, ATS* new_ats)
{
    int index = getAvailableIndex();

        atsList[index] = new_ats;

        if (Tail != -1)
        {
            atsList[Tail]->next = index;
            atsList[index]->prev = (Tail - atsList[0]->prev);
        }
        else
        {
            Head = index;
            atsList[index]->prev = -1;
        }

        Tail = index;
        atsList[index]->next = -1;
}

void MainWindow::numInfo(QString phone)
{ 
    int row = 0;
    for(int i = 0; i < Tail +1; i++){
        if(atsList[i]->num1 == phone || atsList[i]->num2 == phone){
            row++;
        }
   }

    QTableWidget *table = new QTableWidget();
    table->setRowCount(row+1);
    table->setColumnCount(3);
    table->resize(400,400);

    QTableWidgetItem *itm1 = new QTableWidgetItem("Date");
    table->setItem(0, 0, itm1);


    QTableWidgetItem *itm2 = new QTableWidgetItem("TalkTime");
    table->setItem(0, 1, itm2);


    QTableWidgetItem *itm3 = new QTableWidgetItem("Subscriber");
    table->setItem(0, 2, itm3);

    int count = 1;
    bool flag = true;

    for(int i = 0; i < Tail +1; i++){
        if(atsList[i]->num1 == phone || atsList[i]->num2 == phone){
            QTableWidgetItem *search0 = new QTableWidgetItem(atsList[i]->date);
           QTableWidgetItem *search1 = new QTableWidgetItem(QString::number(atsList[i]->talkTime));
           QTableWidgetItem *search2;
            if(atsList[i]->num1 == phone)
                search2 = new QTableWidgetItem(atsList[i]->num2);
            else
                search2 = new QTableWidgetItem(atsList[i]->num1);
            table->setItem(count, 0,search0);
            table->setItem(count, 1, search1);
            table->setItem(count, 2, search2);
            for(int i = 0; i < 3;i++)
                table->item(count, i)->setBackground(Qt::darkGray);
            count++;
        }
        else if(i == Tail && count == 1){
             QMessageBox::critical(ui->centralwidget, "", "Phone number not found");
             flag = false;
        }
    }
    if(flag)
        table->show();
}

void MainWindow::cityInfo(QString city)
{
    int row = 0;
    for(int i = 0; i < Tail +1; i++){
        if(atsList[i]->city == city){
            row++;
        }
   }

    QTableWidget *table = new QTableWidget();
    table->setRowCount(row+1);
    table->setColumnCount(6);
    table->resize(700,400);

    QTableWidgetItem *itm1 = new QTableWidgetItem("Date");
    table->setItem(0, 0, itm1);


    QTableWidgetItem *itm2 = new QTableWidgetItem("Code");
    table->setItem(0, 1, itm2);


    QTableWidgetItem *itm3 = new QTableWidgetItem("Talk time");
    table->setItem(0, 2, itm3);


    QTableWidgetItem *itm4 = new QTableWidgetItem("Tariff");
    table->setItem(0, 3, itm4);


    QTableWidgetItem *itm5 = new QTableWidgetItem("Phone number(1)");
    table->setItem(0, 4, itm5);


    QTableWidgetItem *itm6 = new QTableWidgetItem("Phone number(2)");
    table->setItem(0, 5, itm6);

    int count = 1;
    bool flag = true;

    for(int i = 0; i < Tail +1; i++){
        if(atsList[i]->city == city){
           QTableWidgetItem *search0 = new QTableWidgetItem(atsList[i]->date);
           QTableWidgetItem *search1 = new QTableWidgetItem(QString::number(atsList[i]->code));
           QTableWidgetItem *search2 = new QTableWidgetItem(QString::number(atsList[i]->talkTime));
           QTableWidgetItem *search3 = new QTableWidgetItem(atsList[i]->tariff);
           QTableWidgetItem *search4 = new QTableWidgetItem(atsList[i]->num1);
           QTableWidgetItem *search5 = new QTableWidgetItem(atsList[i]->num2);
            table->setItem(count, 0,search0);
            table->setItem(count, 1, search1);
            table->setItem(count, 2, search2);
            table->setItem(count, 3,search3);
            table->setItem(count, 4, search4);
            table->setItem(count, 5, search5);
            for(int i = 0; i < 6;i++)
                table->item(count, i)->setBackground(Qt::darkGray);
            count++;
        }
        else if(i == Tail && count == 1){
             QMessageBox::critical(ui->centralwidget, "", "Сalls with this number not found");
             flag = false;
        }
    }
    if(flag)
        table->show();
}

void MainWindow::Show()
{
     QTableWidget *table = new QTableWidget();
     table->setRowCount(Tail+2);
     table->setColumnCount(7);

     table->resize(750,600);

    QTableWidgetItem *itm1 = new QTableWidgetItem("Date");
    table->setItem(0, 0, itm1);


    QTableWidgetItem *itm2 = new QTableWidgetItem("Code");
    table->setItem(0, 1, itm2);


    QTableWidgetItem *itm3 = new QTableWidgetItem("City");
    table->setItem(0, 2, itm3);


    QTableWidgetItem *itm4 = new QTableWidgetItem("Talk time");
    table->setItem(0, 3, itm4);


    QTableWidgetItem *itm5 = new QTableWidgetItem("Tariff");
    table->setItem(0, 4, itm5);


    QTableWidgetItem *itm6 = new QTableWidgetItem("Phone number(1)");
    table->setItem(0, 5, itm6);

    QTableWidgetItem *itm7 = new QTableWidgetItem("Phone number(2)");
    table->setItem(0, 6, itm7);

    int pos = 1;

    for(int i = 0; i < Tail+1; i++){      //Пока не встретим пустое значение
        QTableWidgetItem *itm0 = new QTableWidgetItem(atsList[i]->date);
        QTableWidgetItem *itm1 = new QTableWidgetItem(QString::number(atsList[i]->code));
        QTableWidgetItem *itm2 = new QTableWidgetItem(atsList[i]->city);
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(atsList[i]->talkTime));
        QTableWidgetItem *itm4 = new QTableWidgetItem(atsList[i]->tariff );
        QTableWidgetItem *itm5 = new QTableWidgetItem(atsList[i]->num1);
        QTableWidgetItem *itm6 = new QTableWidgetItem(atsList[i]->num2);

        table->setItem(pos, 0, itm0);
        table->setItem(pos, 1, itm1);
        table->setItem(pos, 2, itm2);
        table->setItem(pos, 3, itm3);
        table->setItem(pos, 4, itm4);
        table->setItem(pos, 5, itm5);
        table->setItem(pos, 6, itm6);
        pos++;
         }
    table->show();
}

void MainWindow::fromFile()
{
    bool correct = true;
    QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (*.txt);"));
    if(!file.open(QIODevice::ReadOnly))
        qWarning("Can't open file for reading");
    file.open(QFile::ReadOnly);
    QTextStream in(&file);

        for(int i = 0; !in.atEnd(); i++)
{
            ATS* new_ats = new ATS;
            QString date = file.readLine();
            QRegularExpression form1("[0-9]{2}\\.[0-9]{2}\\.[0-9]{4}$");
            if((date.isNull() || date.isEmpty() || date.toInt() || date.contains(form1)) && correct){
                QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
                correct = false;
                break;
            }
            else if(correct && !date.isEmpty() && !date.toInt()){
                date = date.replace(date.length() - 2,2,"");
                new_ats->date = date;
                }   //Записываем значение в структуру

            QString code = file.readLine();
            QRegularExpression form2("[0-9]{4}$");
            if((code.isNull() || code.isEmpty() || code.contains(form2)) && correct){
                QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
                        correct = false;
                        break;
        }
            else if((!code.isEmpty() && !code.isNull()) && correct)
                new_ats->code = code.toUShort();

           QString city = file.readLine();
           if((city.isEmpty() || city.isNull()) && correct){
               QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
               correct = false;
               break;
           }
           else if(!city.isEmpty() && correct){
               city = city.replace(city.length() - 2, 2 , "");
               new_ats->city = city;
           }

           QString talkTime = file.readLine();
           if((talkTime.isEmpty() || !talkTime.toShort() || talkTime.isNull()) && correct){
               QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
               correct = false;
               break;
           }
           else if(!talkTime.isEmpty() && talkTime.toUShort() && correct)
               new_ats->talkTime = talkTime.toShort();

           QString tariff = file.readLine();
           if((tariff.isEmpty() || tariff.isNull())&& correct){
               QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
               correct = false;
               break;
           }
           else if((!tariff.isEmpty()) && correct)
               new_ats->tariff = tariff.replace(tariff.length()-2, 2, "");

           QString num1 = file.readLine();
           QRegularExpression form3("[0-9]{12}");
           if((num1.isNull() || num1.isEmpty() || !num1.contains(form3))&& correct){
               QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
               correct = false;
               break;
           }
           else if(!num1.isEmpty() && !num1.isNull() && num1.contains(form3) && correct){
               num1 = num1.replace(num1.length() - 2, 2 , "");
               new_ats->num1 = num1;
           }

           QString num2 = file.readLine();
           if((num2.isNull() || num2.isEmpty() || !num2.contains(form3))&& correct){
               QMessageBox::critical(ui->centralwidget, "", "Incorrect file");
               correct = false;
               break;
           }
           else if(!num2.isEmpty() && !num2.isNull() && num2.contains(form3) && correct){
               num2 = num2.replace(num2.length() - 2, 2 , "");
               new_ats->num2 = num2;
           }

           int index = getAvailableIndex();
           atsList[index] = new_ats;

           if(correct){
             if ( Tail != -1)                    //Если список не пуст
                 {
                     atsList[Tail]->next = i;
                     atsList[index]->prev = (Tail - atsList[0]->prev);
                 }
                 else
                 {
                     Head = i;
                     atsList[index]->prev = -1;
                 }

                 Tail = index;
                 atsList[index]->next = -1;
           }
}
         file.close();
}


void MainWindow::toFile()
{
    QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (*.txt);"));;
    if(!file.open(QIODevice::WriteOnly))
        qWarning("Can't open file for reading");
    QTextStream out(&file);
    int table = 1;
    for(int i =0; i < Tail +1; i++)
    {
        out << "#" << table << '\n' << "Date of conversation: " << atsList[i]->date << '\n' << "Code: " << atsList[i]->code<< '\n' << "City: " << atsList[i]->city<< '\n' << "TalkTime: "<< atsList[i]->talkTime<< '\n' <<"Tariff's name: "<< atsList[i]->tariff<< '\n'<< "Phone number(1): "<< atsList[i]->num1<<'\n' <<  "Phone number(2): "<< atsList[i]->num2<<'\n';
                table++;
    }
    file.close();
}

void MainWindow::qSort(ATS **atsList, int last)
{
        int L = 0, R = last , mid = atsList[last/2]->talkTime;
        ATS* temp;
        do{
            while(atsList[L]->talkTime < mid)
                L++;
            while (atsList[R]->talkTime > mid)
                R--;

            if(L <= R){
                temp = atsList[L];
                atsList[L] = atsList[R];
                atsList[R] = temp;
                L++;
                R--;
            }
        }while(L <= R);

            if(R > 0)
                qSort(atsList,R);
            if(last > L)
                qSort(atsList + L,last - L);
    }
void MainWindow::on_AddButton_clicked()
{
        QString date = QInputDialog::getText(this,"Enter the date: "," Date: ",QLineEdit::Normal);
        QRegularExpression form1("[0-9]{2}\\.[0-9]{2}\\.[0-9]{4}$");
        QString day;
        QString month;
        QString year;
        for(int i = 0; i < 10; i++){
            if(i == 0 || i == 1)
                day += date[i];
            else if(i == 3 || i == 4)
                month += date[i];
            else if(i > 5)
                year += date[i];
        }
        int d = day.toInt();
        int m = month.toInt();
        int y = year.toInt();

        while(date.isNull() || date.toInt() || date.isEmpty() || !date.contains(form1) || (d >31 || d < 1) || (m > 12 || m < 1) || (y < 1 || y > 2022) || (m > 4 && d > 14 && y >= 2022) ){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input\n"
                                                                    "Date format: xx.xx.xxxx");
            date = QInputDialog::getText(this,"Enter the date: "," Date: ",QLineEdit::Normal);
            day = "";
            month = "";
            year = "";
            for(int i = 0; i < 10; i++){
                if(i == 0 || i == 1)
                    day += date[i];
                else if(i == 3 || i == 4)
                    month += date[i];
                else if(i > 5)
                    year += date[i];
            }
            d = day.toInt();
            m = month.toInt();
            y = year.toInt();
        }



        short code = QInputDialog::getText(this,"Enter the code:","Code:",QLineEdit::Normal).toShort();
        while(!code || (code > 9999 || code < 1000))
        {
               QMessageBox::critical(ui->centralwidget, "Input error", "Check your input\n"
                                                                       "Code format: xxxx");
                code = QInputDialog::getText(this,"Enter the code:","Code:",QLineEdit::Normal).toShort();
    }



        QString city = QInputDialog::getText(this,"Enter the city: "," City: ",QLineEdit::Normal);
        while(city.isNull() || city.toInt() || city.isEmpty()){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
            city = QInputDialog::getText(this,"Enter the city: "," City: ",QLineEdit::Normal);
        }



        short talkTime = QInputDialog::getText(this,"Enter the talk time:","TalkTime:",QLineEdit::Normal).toShort();
        while(!talkTime)
        {
               QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
               talkTime = QInputDialog::getText(this,"Enter the talk time:","TalkTime:",QLineEdit::Normal).toShort();
    }



        QString tariff = QInputDialog::getText(this,"Enter the name of tariff:","Tariff:",QLineEdit::Normal);
        while(tariff.isNull() || tariff.toInt() || tariff.isEmpty()){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
            tariff = QInputDialog::getText(this,"Enter the name of tariff:","Tariff:",QLineEdit::Normal);
        }



        QString num1 = QInputDialog::getText(this,"Enter the phone number(1):","Phone number(1):",QLineEdit::Normal);
        QRegularExpression form2("[0-9]{12}$");
        while(num1.isNull() || num1.isEmpty() || !num1.contains(form2)){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input\n"
                                                                    "Phone format: xxxxxxxxxxxx");
            num1 = QInputDialog::getText(this,"Enter the phone number(1):","Phone number(1):",QLineEdit::Normal);
        }



        QString num2 = QInputDialog::getText(this,"Enter the phone number(2):","Phone number(2):",QLineEdit::Normal);
        while(num2.isNull() || num2.isEmpty() || !num2.contains(form2)){
            QMessageBox::critical(ui->centralwidget, "Input error", "Check your input\n"
                                                                    "Phone format: xxxxxxxxxxxx");
            num2 = QInputDialog::getText(this,"Enter the phone number(2):","Phone number(2):",QLineEdit::Normal);
        }

        ATS* new_ats = new ATS;
        new_ats->date = date;
        new_ats->code = code;
        new_ats->city = city;
        new_ats->talkTime = talkTime;
        new_ats->tariff = tariff;
        new_ats->num1 = num1;
        new_ats->num2 = num2;

        addInTail(atsList, new_ats);
}

void MainWindow::on_ShowButton_clicked()
{
    Show();
}



void MainWindow::on_toFileButton_clicked()
{
    toFile();
}


void MainWindow::on_fromFileButton_clicked()
{
    fromFile();
}


void MainWindow::on_numInfoButton_clicked()
{
    QString num = QInputDialog::getText(this,"Enter the phone number:","Phone number:",QLineEdit::Normal);
    QRegularExpression form2("[0-9]{12}$");
    while(num.isNull()  || num.isEmpty() || !num.contains(form2)){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input\n"
                                                                "Phone format: xxxxxxxxxxxx");
        num = QInputDialog::getText(this,"Enter the phone number(2):","Phone number(2):",QLineEdit::Normal);
    }
    numInfo(num);

}


void MainWindow::on_CityInfoButton_clicked()
{
    QString city = QInputDialog::getText(this,"Enter the city: "," City: ",QLineEdit::Normal);
    while(city.isNull() || city.toInt() || city.isEmpty()){
        QMessageBox::critical(ui->centralwidget, "Input error", "Check your input");
        city = QInputDialog::getText(this,"Enter the city: "," City: ",QLineEdit::Normal);
    }
    cityInfo(city);
}


void MainWindow::on_deleteButton_clicked()
{
   unsigned short num  = QInputDialog::getText(this,"Enter the num of call:","Index(from 1):",QLineEdit::Normal).toUShort();
   while(num > Tail || !num){
       QMessageBox::critical(ui->centralwidget, "Input error", "Check your input\n"
                                                               "Incorrect index");
       num  = QInputDialog::getText(this,"Enter the num of call:","Index:",QLineEdit::Normal).toUShort();
   }
for (int i=num-1; i < Tail + 1; i++)
    {
        atsList[i] = atsList[i+1];
    }
    Tail--;
}

void MainWindow::on_SortButton_clicked()
{
 qSort(atsList,Tail);
}

