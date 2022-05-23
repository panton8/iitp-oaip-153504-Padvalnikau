#include "orderlist.h"
#include "menu.h"


OrderList::OrderList()
{
};

void OrderList::setData(int oN, int tN, QString dN, int nS,double tP){
    orderNumber = oN;
    tableNumber  = tN;
    dishName = dN;
    numberService = nS;
    totalPrice = tP;
}

int OrderList::returnTable(){
 return tableNumber;
}

int OrderList::returnOrder(){
    return orderNumber;
}

int OrderList::returnService(){
    return numberService;
}

QString OrderList::returnName(){
    return dishName;
}

double OrderList::returnPrice(){
    return totalPrice;
}

/*номер заказа, номер столика, название
блюда, количество порций.*/

QString OrderList::returnList(){
    QString list =  "Num of Order: " + QString::number(orderNumber) + "  Num of Table: " + QString::number(tableNumber) + "  Name of dish: " + dishName + "  Total Price: " + QString::number(totalPrice);
            return list;
}
