#ifndef ATS_H
#define ATS_H
#include <QString>


class ATS
{
public:
    ATS();
    QString date;
    short code;
    QString city;
    short talkTime;
    QString tariff;
    QString num1;
    QString num2;
    int next, prev;
public:
    void setData(QString d, short c, QString city, short talkTime, QString t, QString n1 , QString n2);
    //ATS& operator= (const ATS &ats);

};

#endif // ATS_H
