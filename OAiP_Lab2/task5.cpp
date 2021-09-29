//Лабораторная 2, задача 5. Выполнена: Подвальников А.С.
/*Составить программу используя условный оператор if*/
#include <iostream>

using namespace std;

int main()
{
    double a,b,c,d,Z;
    cout << "Enter a,b,c,d :" << endl;
    cin >> a >> b >> c >> d;
    if (c >= d && a<d)
    {
        Z = a+b/c;
        cout << Z;
    }
    if (c < d && a>= d)
    {
        Z = a-b/c;
        cout << Z;
    }
    else
    {
        Z = 0;
        cout << Z;
    }
    return 0;
}

