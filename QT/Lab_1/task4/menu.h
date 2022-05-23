#ifndef MENU_H
#define MENU_H
#include <QString>

class Menu
{
public:
    Menu();
    void setData(QString dN,QString categ,double pr);
    QString returnDishName();
    QString returnCategory();
    double returnPrice();
    QString returnMenu();
public:
    QString dishName;
    QString category;
    double price;

};

#endif // MENU_H
