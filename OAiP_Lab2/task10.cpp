//Лабораторная 2, задача 10. Выполнена: Подвальников А.С.
/*Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x|
при заданном х, определить и вывести на экран дисплея минимальное
значение. Библиотеку <cmath> использовать запрещено.*/
#include <iostream>
#define e 2.71

using namespace std;

int main()
{
    double x, a, b, c;
    cin >> x;
    if (x > 6.28)
    {
        x = x - (6.28 *(int(x / 6.28)));
    }
    double sin_x = x - ((x * x * x) / (1 * 2 * 3)) + ((x * x * x * x * x) / (1 * 2 * 3 * 4 * 5)) -((x * x * x * x * x * x * x) / (1 * 2 * 3 * 4 * 5 * 6 * 7));
    double cos_x = 1 - ((x * x) / (1 * 2)) + ((x * x * x * x ) / ( 1 * 2 * 3 * 4)) -((x * x * x * x * x * x )/ (1 * 2 * 3 * 4 * 5 * 6));
    x > 0 ? x = x : x = -x;
    double ln_x = 0;
    a = sin_x;
    b = cos_x;
    c = ln_x;
    if (a < b && a < c)
    {
        cout << a;
    }
    else if (b < a && b < c)
    {
        cout << b;
    }
    else if (c < a && c < b)
    {
        cout << c;
    }
    return 0;
}

