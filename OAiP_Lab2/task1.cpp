//Лабораторная 2, задача 1. Выполнена: Подвальников А.С.
/* Заданы два целых числа x и y. Определите, верно ли, что одно из них
делится на другое без остатка, или нет.*/
#include <iostream>

using namespace std;

int main()
{
   int x,y;
   cin >> x >> y;
   if (x % y == 0 || y % x ==0)
   {
       cout << "True";
   }
   else
   {
       cout << "False";
   }
    return 0;
}
