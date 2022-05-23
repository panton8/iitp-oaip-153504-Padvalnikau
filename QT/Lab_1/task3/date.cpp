#include "date.h"


Date::Date(QString date, QString birthday)
{
    this->date = date;
    this->birthday = birthday;
}

void Date::setData(QString date, QString birthday) {
    this->date = date;
    this->birthday = birthday;
}

QString Date::NextDay() {
   QString year = date;
   year.remove(0, 6);

   while (year[0] == '0')
       year.remove(0, 1);

   QString month = date;
   month.remove(0, 3);
   month.remove(2, 5);

   if (month[0] == '0') month.remove(0, 1);

   QString day = date;
   day.remove(2, 8);
   if (day[0] == '0') day.remove(0, 1);

   if (DaysInMonth(month.toInt()) < "30") {
       if (day == "29") return QString("01.03." + year);
       else if (day == "28" && isLeap()) return QString("29.02" + year);
       else return QString(QString::number(day.toInt() + 1) + ".02." + year);
   }
    if (day == "31" && month == "12") return QString("01.01." + QString::number(year.toInt() + 1));
    else if ((DaysInMonth(month.toInt()) == "30" && day == "30") || (day == "31"))
        return QString("01." + QString::number(month.toInt() + 1) + "." + year);
   return QString(QString::number(day.toInt() + 1) + "." + month + "." + year);
 }

QString Date::PreviousDay() {
    QString year = date;
    year.remove(0, 6);

    while (year[0] == '0')
        year.remove(0, 1);

    QString month = date;
    month.remove(0, 3);
    month.remove(2, 5);

    if (month[0] == '0') month.remove(0, 1);

    QString day = date;
    day.remove(2, 8);

    if (day[0] == '0') day.remove(0, 1);

    if (day == "1") {
        if (month == "1") return QString("31.12." + QString::number(day.toInt() - 1) +
                                         "." + year);
        else return QString(DaysInMonth((month.toInt() - 1)) + "." +
                            QString::number(month.toInt() - 1) + "." + year);
}
    else return QString(QString::number(day.toInt() - 1) + "." + month + "." + year);
    }


bool Date::isLeap() {
    QString TempDate = date;
    TempDate.remove(0, 6);
    if (TempDate[0] == '0') TempDate.remove(0, 1);

    int year = TempDate.toInt();

    if (!(year % 4)) {
        if (!(year % 100)) {
            if (!(year % 400))
                return true;
        }
        else return true;
    }
    else return false;
}

int Date::WeekNumber(){

    QString month = date;
    month.remove(0, 3); month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString day = date;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

    long long SecsDate = 24 * month.toInt() * DaysInMonth(month.toInt()).toInt() +
            24 * 3600 * day.toInt();

    long long week = SecsDate/(24*3600);
    week /= 7;
    return (int)++week;

}

short Date::DaysTillYourBirthday(){

    QString month = date;
    month.remove(0, 3); month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString day = date;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

    QString bdayMonth = birthday;
    bdayMonth.remove(0, 3); bdayMonth.remove(2, 5);
    if (bdayMonth[0] == '0') bdayMonth.remove(0, 1);

    QString bdayDay = birthday;
    bdayDay.remove(2, 8);
    if (bdayDay[0] == '0') bdayDay.remove(0, 1);

    short currentMonth = 0, daysInputDate = 0;
    for (; currentMonth != month.toInt(); ++currentMonth)
        daysInputDate += DaysInMonth(currentMonth).toInt();

    short daysBday = 0;
    for (currentMonth = 0; currentMonth != bdayMonth.toInt(); ++currentMonth)
        daysBday += DaysInMonth(currentMonth).toInt();

    daysInputDate += day.toInt();
    daysBday += bdayDay.toInt();

    short days = daysInputDate - daysBday;

    if (days < 0) days *= -1;

    return days;
}

unsigned long long Date::Duration(Date rhs) {

    QString year = date;
    year.remove(0, 6);
    while (year[0] == '0')
        year.remove(0, 1);

    QString month = date;
    month.remove(0, 3); month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString day = date;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

    unsigned long long YearsDays = 0;
    short currentYear = 0;

    for (; currentYear != year.toInt(); ++currentYear) {
        if (isLeap(currentYear)) YearsDays += 366;
        else YearsDays += 365;
    }

    short currentMonth = 0;
    for (; currentMonth != month.toInt(); ++currentMonth)
        YearsDays += DaysInMonth(currentMonth).toInt();

    YearsDays += day.toInt();

    QString Rhsmonth = rhs.date;
    Rhsmonth.remove(0, 3); Rhsmonth.remove(2, 5);
    if (Rhsmonth[0] == '0') Rhsmonth.remove(0, 1);

    QString Rhsday = rhs.date;
    Rhsday.remove(2, 8);
    if (Rhsday[0] == '0') Rhsday.remove(0, 1);

    QString Rhsyear = rhs.date;
    Rhsyear.remove(0, 6);
    while (Rhsyear[0] == '0')
        Rhsyear.remove(0, 1);

    unsigned long long NextDateYear = 0;
    short currentNextYear = 0;

    for (; currentNextYear != Rhsyear.toInt(); ++currentNextYear) {
        if (isLeap(currentNextYear)) NextDateYear += 366;
        else NextDateYear += 365;
    }

    for (currentMonth = 0; currentMonth != Rhsmonth.toInt(); ++currentMonth)
        NextDateYear += DaysInMonth(currentMonth).toInt();

    NextDateYear += Rhsday.toInt();

   unsigned long long difference = NextDateYear > YearsDays ?
               NextDateYear - YearsDays : YearsDays - NextDateYear;

   return difference;
}

void Date::SetDate(QString d)
{
    date = d;
}

QString Date::DaysInMonth(short MonthNumber) {
    if (MonthNumber == 2) { //February
        if (isLeap()) return "29";
        else return "28";
    }
    else if (MonthNumber == 4 || MonthNumber == 6 || MonthNumber == 9 || MonthNumber == 11)
        return "30";
    else return "31";
}

bool Date::isLeap(short year) {
    if (!(year % 4)) {
        if (!(year % 100)) {
            if (!(year % 400))
                return true;
        }
        else return true;
    }
    else return false;
}


QString Date::retDate(){
    QString date = "25.04.1963 ";
    return date;
}
