//Лабораторная 2, задача 15. Выполнена: Подвальников А.С.
/*Для дробного числа К напечатать фразу "мы нашли К грибов в лесу",
согласовав окончание слова "гриб" с числом К.*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double K;
    cin >> K;
    if (K < 0)
    {
        cout << "ERROR!";
    }
    else if(((int(K) % 10 == 2) || (int(K) % 10 == 3) || (int(K) % 10 == 4 )) || (K != round(K)))
    {
        cout << "Mi nashli" << " " << K << " " << "griba v lesy";
    }
    else if ((K == 1) || ((K >= 21) &&  ((int(K) % 10 == 1))) )
    {
        cout << "Mi nashli" << " " << K << " " << "grib v lesy";
    }
    else if ((K == round(K)) && ((int(K) % 10 != 1) || (int(K) % 10 != 2) || (int(K) % 10 != 3) || (int(K) % 10 !=4)))
    {
        cout << "Mi nashli" << " " << K << " " << "gribov v lesy";
    }
    return 0;
}

