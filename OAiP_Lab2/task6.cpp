//Лабораторная 2, задача 6. Выполнена: Подвальников А.С.
/*Составить программу используя переключатель switch*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c,Y;
    int N;
    cin >> a >> b >> c >> N;

    switch(N)
    {
        case 2:
            Y = b*c - pow(a,2);
            cout << Y;
            break;
        case 56:
            Y = b*c;
            cout << Y;
            break;
        case 7:
            Y = pow(a,2) + c;
            cout << Y;
            break;
        case 3:
            Y = a - b*c;
            cout << Y;
            break;
        default:
            Y = pow(a+b,3);
            cout << Y;
            break;
    }
    return 0;
}

