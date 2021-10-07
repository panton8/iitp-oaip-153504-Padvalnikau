//Лабораторная 2, задача 15. Выполнена: Подвальников А.С.
/*Для дробного числа К напечатать фразу "мы нашли К грибов в лесу",
согласовав окончание слова "гриб" с числом К.*/
#include <iostream>

using namespace std;

int main()
{
    double K;
    cout << "Enter the amount of mushrooms you found:" << endl;
    cin >> K;
    if (K < 0)
    {
        cout << "ERROR! Number of mushrooms can't be negative";
    }
    else if ((int(K) % 100 == 5) || (int(K) % 100 == 6)||(int(K) % 100 == 7)||(int(K) % 100 == 8)||(int(K) % 100 == 9)||(int(K) % 100 == 10)||(int(K) % 100 == 11)||(int(K) % 100 == 12)||(int(K) % 100 == 13)||(int(K) % 100 == 14)||(int(K) % 100 == 15)||(int(K) % 100 == 16)||(int(K) % 100 == 17)||(int(K) % 100 == 18) ||(int(K) % 100 == 19))
    {
        cout << "Mi nashli" << " " << K << " " << "gribov v lesy";
    }
    else if ((int(K) % 10 == 2)||(int(K) % 10 == 3)||(int(K) % 10 == 4))
    {
        cout << "Mi nashli" << " " << K << " " << "griba v lesy";
    }
    else if ( int(K) % 10 == 1)
    {
        cout << "Mi nashli" << " " << K << " " << "grib v lesy";
    }
    else
    {
        cout << "Mi nashli" << " " << K << " " << "gribov v lesy";
    }
    return 0;
}

