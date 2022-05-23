#ifndef ORDERLIST_H
#define ORDERLIST_H
#include <QString>
#include <menu.h>

class OrderList : public Menu
{
public:
    OrderList();
    void setData(int oN, int tN, QString dN, int nS,double tP);
    int returnTable();
    int returnOrder();
    int returnService();
    QString returnName();
    QString returnList();
    double returnPrice();
public:
    int orderNumber;
    int tableNumber;
    QString dishName;
    int numberService;
    double totalPrice;
};
#endif // ORDERLIST_H
