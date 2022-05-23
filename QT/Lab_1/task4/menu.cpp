#include "menu.h"


Menu::Menu()
{
}

void Menu::setData(QString dN,QString categ,double pr){
    dishName = dN;
    category = categ;
    price = pr;
}

QString Menu::returnDishName(){
    return dishName;
}

QString Menu::returnCategory(){
    return category;
}

double Menu::returnPrice(){
    return price;
}

QString Menu::returnMenu()
{
    QString menu = "dishName: " + dishName + "  category: " + category + "  dishPrice: " + QString::number(price);
            return menu;
}

