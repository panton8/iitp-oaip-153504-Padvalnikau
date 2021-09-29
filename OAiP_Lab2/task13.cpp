//Лабораторная 2, задача 13. Выполнена: Подвальников А.С.
/*Сможет ли шар радиуса R пройти в ромбообразное отверстие
стороной P и острым углом Q?*/
#include<iostream>
#include <cmath>
#define Pi 3.14

using namespace std;

int main()
{
    double R,P,Q,r;
    cout << "Enter R,P,Q" << endl;
    cin >> R >> P >> Q;
    r =(P*sin(Q/180*Pi)/2);
    if (r >= R)
    {
        cout << "The ball will pass";
    }
    else
    {
        cout << "The ball wan't pass ";
    }
    return 0;
}

