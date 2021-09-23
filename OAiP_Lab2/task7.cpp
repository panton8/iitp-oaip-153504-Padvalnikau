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
    double D = b*b - 4*a*c;
    if (D > 0)
    {
        double t1 = (-b - sqrt(D) / (2 * a));
        double t2 = (-b + sqrt(D) / (2 * a));
        if (t1 < 0 && t2 < 0 )
        {
            cout << "No solution for ax^4 + bx^2 + c = 0 ! " << endl;
        }
        if (t1 > 0)
        {
            double x1 = sqrt(t1);
            double x2 = -sqrt(t1);
            cout << "Solution for ax^4 + bx^2 + c = 0 :" <<'\n';
            cout << "x1 = " << x1 << '\n' << "x2 = " << x2 << '\n';
        }
        if (t2 > 0)
        {
            double x3 = sqrt(t2);
            double x4 = -sqrt(t2);
            cout << "x3 = "<< x3 << '\n' << "x4 = " <<  x4;
        }
    }
    else if(D < 0)
    {
        cout << "No solution for ax^4 + bx^2 + c = 0 !" << '\n';
    }

    //Second:
    double D2 = b*b - 4*a*(c - 2*a);
    if (D2 > 0)
    {
        double y1 = (-b-sqrt(D2))/(2 * a);
        double y2 = (-b-sqrt(D2))/(2 * a);
        if ((y1 * y1 - 4 < 0) && (y2 * y2 - 4 < 0 ))
        {
            cout << "No solution for ax^4 + bx^3 + cx^2 + bx + a = 0 !" << endl;
        }
        if (y1 * y1 - 4 > 0)
        {
            double z1 = (((-y1) + (sqrt(y1 * y1 - 4)))/2);
            double z2 = (((-y1) - (sqrt(y1 * y1 - 4)))/2);
            cout << "Solution for ax^4 + bx^3 + cx^2 + bx + a = 0 :" << '\n';
            cout << "x1 = " << z1 << '\n' << "x2 = " << z2 <<'\n';
        }
        if( y2 * y2 - 4 > 0)
        {
            double z3 = (((-y2) + (sqrt(y2 * y2 - 4))) / 2);
            double z4 = (((-y2) - (sqrt(y2 * y2 - 4))) / 2);
            cout << "x3 = " << z3 << '\n' << "x4 = " << z4;
        }
    }
    else if (D2 < 0)
    {
        cout << "No solution for ax^4 + bx^3 + cx^2 + bx + a = 0 !";
    }
    return 0;
}

