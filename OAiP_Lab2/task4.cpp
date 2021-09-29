//Лабораторная 2, задача 4. Выполнена: Подвальников А.С.
/*Дан квадрат с вершинами в точках (0, 0), (0, k), (k, k), (k, 0). Вычислите
наименьшее из расстояний от точки с координатами (x, y), лежащей внутри
квадрата, до сторон данного квадрата. Координаты вещественные. Если точка
лежит за пределами квадрата, выведите сообщение об этом и расстояние до
ближайшей стороны квадрата.*/
#include <iostream>
#include <cmath>

using namespace  std;

int main()
{
    int k;
    double x,y;
    cout << "Enter k,x,y :" << endl;
    cin >> k >> x >> y;
    if (k > 0)
    {
        if ((x < 0 || x > k) || (y < 0 || y > k))
        {
            cout << "Point outside the square" << endl;
            if (x > k && y <= k && y > 0)
            {
                cout << "To the nearest side of the square: " << x - k;
            }
            else if(x > k && y <k && y < 0)
            {
                cout << "To the nearest side of square: " <<sqrt(y*y + (x-k)*(x-k));
            }
            else if (y > k && x <= k)
            {
                cout << "To the nearest side of square: " << y - k;
            }
            else if((x < k && x >= 0) && y < 0)
            {
                cout << "To the nearest side of square: " << -y;
            }
            else if(x < 0 && (y < k && y >= 0))
            {
                cout << "To the nearest side of square: " << -x;
            }
            else if(x < 0 && y < 0)
            {
                cout << "To the nearest side of square: " << sqrt(x*x + y*y);
            }
            else if (y > k && x > k)
            {
                cout << "To the nearest side of square: " << sqrt((y - k) * (y - k) + (x - k) * (x - k));
            }
        }
        else if(x > 0 && x < k && y > 0 && y < k)
        {
            cout << "To side AB: " << x << endl;
            cout << "To side BC: " << k - y << endl;
            cout << "To side CD: " << k - x << endl;
            cout << "To side DA: " << y << endl;
        }
    }
    else if (k < 0)
    {
        if((x > 0 || x < k) || (y > 0 || y < k))
        {
            cout << "Point outside the square" << endl;
            if (x < k && y >= k && y < 0)
            {
                cout << "To the nearest side of square: " << k - x;
            }
            else if(y < k && x >= k && x < 0)
            {
                cout << "To the nearest side of square: " << k - y;
            }
            else if(x < k && y > k && y > 0)
            {
                cout << "To the nearest side of square: " << sqrt(y*y + (k-x)*(k-x));
            }
            else if (x > 0 && x > k && y < k )
            {
                cout << "To the nearest side of square: " << sqrt(x*x + (k-y)*(k-y));
            }
            else if(x > 0 && x > k && y >= k && y <= 0)
            {
                cout << "To the nearest side of square: " << x;
            }
            else if((x > k && x < 0) && y > k)
            {
                cout << "To the nearest side of square: " << y;
            }
            else if((x > k && x > 0) && y > k && y > 0)
            {
                cout << "To the nearest side of square: " << sqrt(x*x + y*y);
            }
            else if(y < k && x < k)
            {
                cout << "To the nearest side of square: " << sqrt((k - y) * (k - y) + (k - x) * (k - x)) ;
            }
        }
        else if(x < 0 && x >= k && y < 0 && y >= k)
        {
            cout << "To side AB: " << -x << endl;
            cout << "To side BC: " << y - k << endl;
            cout << "To side CD: " << x - k << endl;
            cout << "To side DA: " << -y << endl;
        }
    }
    return 0;
}




