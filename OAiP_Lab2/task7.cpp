//Лабораторная 2, задача 7. Выполнена: Подвальников А.С.
/*Составить программу для решения уравнений трёх видов:
7.1 ax^4 + bx^2 + c = 0;
7.2 ax^4 + bx^3 + cx^2 + bx + a = 0
7.3 x^3 + px + q = 0*/
#include <iostream>
#include <cmath>
#define Pi 3.14

using namespace std;

int main()
{
    double a,b,c,p,q;
    cin >> a >> b >> c >> p >> q;

    //First:
    double D1 = b * b - 4 * a * c;
    if (D1 > 0)
    {
        double t1 = (-b - sqrt(D1) )/ (2 * a);
        double t2 = (-b + sqrt(D1)) / (2 * a);
        if ((t1 < 0) && (t2 < 0 ))
        {
            cout << "No solution for ax^4 + bx^2 + c = 0 ! " << endl;
        }
        if (t1 >= 0)
        {
            double x1 = sqrt(t1);
            double x2 = -sqrt(t1);
            cout << "Solution for ax^4 + bx^2 + c = 0(First part) :" << endl;
            cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
        }
        if (t2 >= 0)
        {
            double x3 = sqrt(t2);
            double x4 = -sqrt(t2);
            cout << "Solution for ax^4 + bx^2 + c = 0(Second part) :" << endl;
            cout << "x3 = "<< x3 << endl << "x4 = " <<  x4 << endl;
        }
    }
    else if (D1 == 0)
    {
        double t3 = (-b) / (2 * a);
        if (t3 >= 0)
        {
            double x_1 = sqrt(t3);
            double x_2 = - sqrt(t3);
            cout << "Solution for ax^4 + bx^2 + c = 0(Second part) :" << endl;
            cout << "x1 = " << x_1 << endl << "x2 = " << x_2 << endl;
        }
        if (t3 < 0)
        {
            cout << "No solution for ax^4 + bx^2 + c = 0 ! " << endl;
        }
    }
    else if(D1 < 0)
    {
        cout << "No solution for ax^4 + bx^2 + c = 0 !" << endl;
    }

    //Second:
    double D2 = b * b - 4*a*(c - 2 * a);
    if (D2 > 0)
    {
        double y1 = (-b-sqrt(D2))/(2 * a);
        double y2 = (-b+sqrt(D2))/(2 * a);
        if ((y1 * y1 - 4 < 0) && (y2 * y2 - 4 < 0 ))
        {
            cout << "No solution for ax^4 + bx^3 + cx^2 + bx + a = 0 !" << endl;
        }
        if (y1 * y1 - 4 > 0)
        {
            double z1 = (-((-y1) + (sqrt(y1 * y1 - 4)))/2);
            double z2 = (-((-y1) - (sqrt(y1 * y1 - 4)))/2);
            cout << "Solution for ax^4 + bx^3 + cx^2 + bx + a = 0(First part) :" << endl;
            cout << "x1 = " << z1 << endl << "x2 = " << z2 << endl;
        }
        if( y2 * y2 - 4 > 0)
        {
            double z3 = (-((-y2) + (sqrt(y2 * y2 - 4))) / 2);
            double z4 = (-((-y2) - (sqrt(y2 * y2 - 4))) / 2);
            cout << "Solution for ax^4 + bx^3 + cx^2 + bx + a = 0(Second part) :" << endl;
            cout << "x3 = " << z3 << endl << "x4 = " << z4 << endl;
        }
    }
    else if (D2 == 0)
    {
       double y3 = (-b) / (2 * a) ;
       if (y3 * y3 - 4 > 0)
       {
           double z5 = (-((-y3) + (sqrt(y3 * y3 - 4))) / 2);
           double z6 = (-((-y3) - (sqrt(y3 * y3 - 4))) / 2);
           cout << "Solution for ax^4 + bx^3 + cx^2 + bx + a = 0 :" << endl;
           cout << "x1 = " << z5 << endl << "x2 = " << z6;
       }
        if (y3 * y3 - 4 < 0)
        {
            cout << "No solution for ax^4 + bx^3 + cx^2 + bx + a = 0 !" << endl;
        }
    }
    else if (D2 < 0)
    {
        cout << "No solution for ax^4 + bx^3 + cx^2 + bx + a = 0 !" << endl;
    }

    //Third
    double D3 = pow(p/3,3) + pow(q/2,2);
    double F;
    if (q == 0)
    {
        F = Pi / 2;
    }
    else if (q > 0)
    {
        F = atan (sqrt(-D3) / (-q/2))+ Pi;
    }
    else if (q < 0)
    {
        F = (sqrt(-D3) / (-q/2));
    }
    if (D3 > 0)
    {
        double A =  double (pow((-q/2) + sqrt(D3),(1.0/3)));
        double B =  double (pow((-q/2) - sqrt(D3),(1.0/3)));
        double k1 = A + B;
        cout << "Solution for x^3 + px + q = 0 :" << endl;
        cout << "x1 = " << k1 << endl;
    }
    else if (D3 <0)
    {
        double k2 = 2 * sqrt(-p/3) * cos(F/3);
        double k3 = 2 * sqrt(-p/3) * cos(F/3 + (2 * Pi / 3));
        double k4 = 2 * sqrt(-p/3) * cos(F/3 + (4 * Pi / 3)) ;
        cout << "Solution for x^3 + px + q = 0 :" << endl;
        cout << "x1 = " << k2 << endl << "x2 = " << k3 << endl << "x3 = " << k4 << endl;
    }
    else if (D3 == 0)
    {
        double k5 = -2 * pow(q/2,1.0/3);
        double k6 = pow(q/2,1.0/3);
        cout << "Solution for x^3 + px + q = 0 :" << endl;
        cout << "x1 = " << k5 << endl << "x2 = x3 = " << k6 << endl;
    }

    return 0;
}