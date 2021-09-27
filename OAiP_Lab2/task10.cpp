//Лабораторная 2, задача 10. Выполнена: Подвальников А.С.
/*Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x|
при заданном х, определить и вывести на экран дисплея минимальное
значение. Библиотеку <cmath> использовать запрещено.*/
#include <iostream>

using namespace std;

int main()
{
    double x, a, b, c;
    cin >> x;
    double y = x*x;
    double z = x*x*x;
    if (x < 0)
    {
        x = -x;
        double ln_x = x - ( y/2) + (z/6) - (y*y /24) + (z*y / 120) - (z*z / 720) + (z*z*y/40320);;
        c = ln_x;
    }
    if (x > 6.28)
    {
        x = x - (6.28 *(int(x / 6.28)));
    }
    double sin_x = x - (z / 6) + ((z*y) / 120) - ((z*y*y) / 5040) + ((z*z*z)/362880) - ((z*z*z*y) / 39916800) + ((z*z*z*y*y)/ 39916800);
    double cos_x = 1 - ((y) / 2 ) + ((y*y) / 24) - ((z*z)/ (720)) + ((z*z*y)/40320) - ((z*z*y*y)/3628800) + ((z*z*z*z)/479001600) - (z*z*z*z*y/87178291200);
    a = sin_x;
    b = cos_x;
    if ((a < b) && (a < c))
    {
        cout << "sin(x) (min) = "  << a;
    }
    else if ((b < a) && (b < c))
    {
        cout << "cos(x) (min) = " << b;
    }
    else if ((c < a) && (c < b))
    {
        cout << "ln|x| (min) = " << c;
    }
    return 0;
}

