#include "ATS.h"

ATS::ATS() : next(next = 0), prev(prev = 0){

 };

void ATS::setData(QString d, short c, QString cit, short tT, QString t, QString n1 , QString n2){
    date = d;
    code= c;
    city = cit;
    talkTime = tT;
    tariff = t;
    num1 = n1;
    num2 = n2;
}
