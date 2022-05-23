#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
#include <QTimer>
#include <QDateTime>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    showDate();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    chooseFile = new QPushButton("Select File", this);

    connect(chooseFile, SIGNAL(clicked()), this, SLOT(on_ChooseFile_clicked()));
}

void MainWindow::showTime(){
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->Digital_clock->setText(time_text);
}

void MainWindow::showDate(){
    QDate date = QDate::currentDate();
    QString date_text = date.toString("dd/MM/yyyy");
    ui->Digital_date->setText(date_text);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_ChooseFile_clicked()
{
    FilePath = QFileDialog::getOpenFileName(this, "Select TXT File",
                                                    "C:\\Users\\Администратор\\Desktop",
                                                    "TXT File (*.txt);" );

    if (!FilePath.isEmpty())
        chooseFile->setText(FilePath);
    QDate date = QDate::currentDate();
    QString date_text ;
    if(date_text != date.toString("dd/MM/yyyy")){
         QMessageBox::critical(this, "Error", "Сheck the file");
         FilePath = QFileDialog::getOpenFileName(this, "Select TXT File",
                                                         "C:\\Users\\Администратор\\Desktop",
                                                         "TXT File (*.txt);" );
    }


}


void MainWindow::on_Enter_clicked()
{
    Bday = ui->lineEdit->text();
    QString date;
    QString  month;
    QString year;
    for(int i = 0; i < Bday.size(); i++){
        if(i == 0 || i == 1)
            date += Bday[i];
        else if(i == 3 || i == 4)
            month +=   Bday[i];
        else if( i >= 6)
            year += Bday[i];
    }
    int dateINT = date.toInt();
    int monthINT = month.toInt();
    int yearINT = year.toInt();

    QRegularExpression reg("[0-9]{2}\\.[0-9]{2}\\.[0-9]{4}$");
    if (!Bday.contains(reg))
        QMessageBox::critical(this, "Error", "Input Format:\ndd.mm.yyyy");
    else if(((dateINT >31 || dateINT < 1) || (monthINT > 12 || dateINT < 1) || (yearINT < 1 || yearINT > 2022)) || (monthINT > 3 && dateINT > 17 && yearINT >= 2022))
         QMessageBox::critical(this, "Error", "Сheck the correctness of the input");
    else if (FilePath.isEmpty())
        ui->statusbar->showMessage("Select File!");

    else {
        wnd = new QDialog(this);
        wnd->resize(1000, 700);

        QPushButton *btn = new QPushButton("File Data Correction", wnd);
        btn->adjustSize();

        btn->move(800, 650);

        QTableWidget *table = new QTableWidget(wnd);

        table->resize(1000, 650);

        Date *dates = new Date[4];

        QFile file(FilePath);

        file.open(QFile::ReadOnly);

        table->setRowCount(5);
        table->setColumnCount(8);

        QTextStream stream(&file);
        QString buffer;

        for (short i = 1, j = 0; i < table->rowCount(); ++i, ++j) {
            buffer = stream.readLine();

            dates[j].setData(buffer, Bday);

            QTableWidgetItem *itm = new QTableWidgetItem(buffer);
            table->setItem(i, 0, itm);
            buffer = "";
        }

        QTableWidgetItem *itm1 = new QTableWidgetItem("Difference between current and next");
        table->setItem(0, 1, itm1);


        QTableWidgetItem *itm2 = new QTableWidgetItem("NextDay");
        table->setItem(0, 2, itm2);


        QTableWidgetItem *itm3 = new QTableWidgetItem("PrevDay");
        table->setItem(0, 3, itm3);


        QTableWidgetItem *itm4 = new QTableWidgetItem("LeapYear");
        table->setItem(0, 4, itm4);


        QTableWidgetItem *itm5 = new QTableWidgetItem("WeekNumber");
        table->setItem(0, 5, itm5);


        QTableWidgetItem *itm6 = new QTableWidgetItem("DaysTillBday");
        table->setItem(0, 6, itm6);

        QTableWidgetItem *itm7 = new QTableWidgetItem("Duration");
        table->setItem(0, 7, itm7);

        file.close();

        for (short i = 1, k = 0; i < table->rowCount(); ++i, ++k)
            for (short j = 1; j < table->columnCount(); ++j) {

                switch (j) {

                case 1:
                    if (k == 3) buffer = QString::number(dates[k].Duration(dates[0]));
                    else buffer = QString::number(dates[k].Duration(dates[k + 1]));
                    break;
                case 2:
                    buffer = dates[k].NextDay();
                    break;
                case 3:
                    buffer = dates[k].PreviousDay();
                    break;
                case 4:
                    buffer = dates[k].isLeap() ? "Yes" : "No";
                    break;
                case 5:
                    buffer = QString::number(dates[k].WeekNumber());
                    break;
                case 6:
                    buffer = QString::number(dates[k].DaysTillYourBirthday());
                    break;
                case 7:
                    buffer = QString::number(dates[k].Duration(Date("17.09.2012")));
                }

                QTableWidgetItem *itm = new QTableWidgetItem(buffer);
                table->setItem(i, j, itm);
                buffer = "";
            }

        connect(btn, SIGNAL(clicked()), this, SLOT(on_CorrectData_clicked()));

        wnd->show();
    }

}

void MainWindow::on_CorrectData_clicked()
{
    QFile file("C:/Users/Администратор/Desktop/date.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream out(&file);
    Date *date = new Date;
    out << '\n'  << date->retDate();
        file.close();

 }


void MainWindow::on_pushButton_clicked()
{

        QFile file(QFileDialog::getOpenFileName(this,"Select File",  "C:\\Users\\Администратор\\Desktop",  "TXT File (date.txt);"));
        if(!file.open(QIODevice::ReadOnly))
            qWarning("Can't open file for reading");
        file.open(QFile::ReadOnly);
        QTextStream in(&file);
        ui->tableWidget->setRowCount(10);
        ui->tableWidget->setColumnCount(1);
            for(int i = 0; !in.atEnd(); i++)
                    {
                        QString line = file.readLine();
                        QTableWidgetItem *item = new QTableWidgetItem();
                        item->setText(line);
                        ui->tableWidget->setItem(i,0,item);
                    }
        file.close();
}


void MainWindow::on_dateTimeEdit_dateChanged(const QDate &date)
{

}


void MainWindow::on_dateTimeEdit_timeChanged(const QTime &time)
{

}


void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}



void MainWindow::on_pushButton_2_clicked()
{
    QFile file("C:/Users/Администратор/Desktop/date.txt");
    file.open( QFile::ReadWrite);
      file.seek(0);
      file.write("11.05.2008",10);
        file.close();
}

