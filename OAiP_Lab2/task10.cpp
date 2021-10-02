//Лабораторная 2, задача 10. Выполнена: Подвальников А.С.
/*Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x|
при заданном х, определить и вывести на экран дисплея минимальное
значение. Библиотеку <cmath> использовать запрещено.*/
#include <iostream>

using namespace std;

int main()
{
    double x, a, b, c;
    cout << "Enter x:";
    cin >> x;
    double m = x < 0 ? -x : x;
    double ln_x = 2 * (((m-1)/(m+1)) + (1.0/3*(((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1)))) + (1.0/5*(((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1)))) + (1.0/7*((((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))))) + (1.0/9 * ((((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))))) + (1.0/11 * ((((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))))) + (1.0/13 * ((((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))*((m-1)/(m+1))))));
    c = ln_x;
    if (x > 6.28)
    {
        x = x - (6.28 *(int(x / 6.28)));
    }
    if (x < -6.28)
    {
        x = x - (-6.28 *(int(x / -6.28)));
    }
    double sin_x = x - (x*x*x/6) + (x*x*x*x*x)/120 - (x*x*x*x*x*x*x)/5040 + (x*x*x*x*x*x*x*x*x)/362880 - ((x*x*x*x*x*x*x*x*x*x*x)/39916800) + (x*x*x*x*x*x*x*x*x*x*x*x*x/6227020800)-(x*x*x*x*x*x*x*x*x*x*x*x*x*x*x/1307674400000) +(x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x/355687430000000)-(x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x/121645100000000000.0);
    double cos_x = 1 - (x*x)/2 + (x*x*x*x)/24 - (x*x*x*x*x*x)/720 + (x*x*x*x*x*x*x*x)/40320 - (x*x*x*x*x*x*x*x*x*x)/3628800 + (x*x*x*x*x*x*x*x*x*x*x*x)/479001600 - (x*x*x*x*x*x*x*x*x*x*x*x*x*x)/87178291200 + (x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x)/20922790000000 - (x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x*x)/6402373700000000;
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