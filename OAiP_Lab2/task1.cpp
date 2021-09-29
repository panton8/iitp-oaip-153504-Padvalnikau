//Лабораторная 2, задача 1. Выполнена: Подвальников А.С.
/* Заданы два целых числа x и y. Определите, верно ли, что одно из них
делится на другое без остатка, или нет.*/
#include <iostream>

using namespace std;

int main()
{
   int x,y;
   cout << "Enter x and y :" << endl;
   cin >> x >> y;
   if (x % y == 0 || y % x ==0)
   {
       cout << "True,shares entirely";
   }
   else
   {
       cout << "False,not shared";
   }
    return 0;
}
