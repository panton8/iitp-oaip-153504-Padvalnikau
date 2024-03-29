//Лабораторная 2, задача 8. Выполнена: Подвальников А.С.
/*Вычислить значение y в зависимости от выбранной функции f(x),
аргумент определяется из поставленного условия. Возможные значения
функции f(x): 2x, x^3, x/3 (выбор осуществляется используя оператор switch).
Предусмотреть вывод сообщений, показывающих, при каком условии и с какой
функцией производились вычисления y.*/
#include <iostream>
#include <cmath>
#define e 2.71
using namespace std;

int main()
{
    int function;
    double z,a,c,x;
    cout << "Choose num of function: 1)2x; 2)x^3; 3)x/3." << endl;
    cin >> function;
    if (function != 1 && function != 2 && function !=3)
    {
        cout << "Try again" << endl;
        return 0;
    }
    cout << "Enter a,z,c" << endl;
    cin >> a >> z >> c;
    if (z <= 1)
    {
        x = pow(z,2) + 1;
        cout << "calculate at x = z^2 + 1" << endl;
    }
    else
    {
        x = 1 / (sqrt(z-1));
        cout << "calculate at x = 1 / sqrt(z-1)" << endl;
    }
    switch (function)
    {
        case 1:
            cout << "Calculation is performed using the function f(x)=2x" << endl;
            cout << (a * log(fabs(x))) + pow(e,x) + (c * pow(sin((2*x) * pow(x,2) - 1),3)) ;
            break;
        case 2:
            cout << "Calculation is performed using the function f(x)=x^3" << endl;
            cout << (a * log(fabs(x))) + pow(e,x) + (c * pow(sin((pow(x,3)) * pow(x,2) - 1),3));
            break;
        case 3:
            cout << "Calculation is performed using the function f(x)=x/3" << endl;
            cout << (a * log(fabs(x)))+ pow(e,x) + (c * pow(sin((x/3) * pow(x,2) - 1),3));
            break;
    }
    return  0;
}