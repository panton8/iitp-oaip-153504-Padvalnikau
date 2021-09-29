//Лабораторная 2, задача 12. Выполнена: Подвальников А.С.
/*Определить, попадает ли круг с точкой в центре которая имеет
координату M1(x1, y1) и радиусом r в круг с точкой в центре которая имеет
координату M2(x2, y2) и радиусом R. Если круг M1 попадает в круг M2, вывести
сообщение “Да”. Если круг M2 попадает в круг M1 вывести сообщение “Да, но
справедливо обратное для двух фигур”. Если круги пересекаются, но не
поглощают друг друга, то вывести сообщение “Фигуры пересекаются”. Иначе
вывести сообщение “Ни одно условие не выполнено”.*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x1, y1, x2, y2, r, R;
    cout << "Enter all(6) parameters:" << endl;
    cin >> x1 >> y1 >> r >> x2 >> y2>> R;
    double S1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    if (S1 < R - r)
    {
      cout << "Yes";
    }
    else if  (S1 <= r - R)
    {
        cout << " Yes, but the opposite is true for two figures";
    }
    else if ((S1 > fabs(r - R)) && (S1 < (r + R)))
    {
        cout << "Intersection of figures";
    }
    else
    {
        cout << "None of the conditions are completed";
    }
    return 0;
}

