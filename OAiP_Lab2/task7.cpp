//Лабораторная 2, задача 7. Выполнена: Подвальников А.С.
/*Составить программу для решения уравнений трёх видов:
7.1 ax^4 + bx^2 + c = 0;
7.2 ax^4 + bx^3 + cx^2 + bx + a = 0
7.3 x^3 + px + q = 0*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c;
    cin >> a >> b >> c;
    if(sqrt(b*b - 4*a*c > 0))
    {
        double t1 = ((-b - sqrt(b * b - 4 * a * c)) / (2 * a));
        double t2 = ((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
        if (t1 > 0)
        {
            double x1 = sqrt(t1);
            double x2 = -sqrt(t1);
            cout << "Solution for: ax^4 + bx^2 + c = 0" <<'\n';
            cout << "x1 = " << x1 << '\n' << "x2 = " << x2 << '\n';
        }
        if (t2 > 0)
        {
            double x3 = sqrt(t2);
            double x4 = -sqrt(t2);
            cout << "x3 = "<< x3 << '\n' << "x4 = " <<  x4;
        }
    }
    else
    {
        cout << "No solution!";
    }
    return 0;
}

