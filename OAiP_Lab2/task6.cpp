//Лабораторная 2, задача 6. Выполнена: Подвальников А.С.
/*Составить программу используя переключатель switch*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c,Y;
    int N;
    cout << "Enter a,b,c,N :" << endl;
    cin >> a >> b >> c >> N;
    switch(N) {
        case 2:
            Y = b * c - pow(a, 2);
            break;
        case 56:
            Y = b * c;
            break;
        case 7:
            Y = pow(a, 2) + c;
            break;
        default :
            Y = pow(a + b, 3);
        case 3:
            Y = a - b * c;
            break;
    }
            cout << Y;
    return 0;
}

