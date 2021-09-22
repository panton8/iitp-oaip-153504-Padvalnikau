//Лабораторная 2, задача 11. Выполнена: Подвальников А.С.
/*Определить, какая из двух фигур (круг или квадрат) имеет большую
площадь. Известно, что сторона квадрата равна a, радиус круга r. Библиотеку
<cmath> использовать запрещено.*/
#include <iostream>
#define Pi 3.14

using namespace std;

int main()
{
    double a, r;
    cin >> a >> r;
    double S_square = a*a;
    double S_circle = Pi*r*r;
    if (S_square > S_circle)
    {
        cout << "Area of square is more than area of circle";
    }
    else
    {
        cout << "Area of circle is more than area of square";
    }
    return 0;
}

