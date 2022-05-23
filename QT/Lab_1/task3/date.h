#ifndef DATE_H
#define DATE_H
#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDateTime>
#include <QDate>
#include <QMessageBox>
#include <QTextStream>


class Date {
public:
    Date(QString date = "", QString birthday= "");

    virtual ~Date() {    }

    void setData(QString date, QString birthday);

    QString NextDay();

    QString retDate();

    QString PreviousDay();

    bool isLeap();

    int WeekNumber();

    short DaysTillYourBirthday();

    unsigned long long Duration(Date rhs);
    void SetDate(QString d = "");

private:
    QString date;
    QString birthday;

    QString DaysInMonth(short MonthNumber);

    bool isLeap(short year);

};

#endif // DATE_H
