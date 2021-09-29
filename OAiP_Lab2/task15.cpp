//Лабораторная 2, задача 15. Выполнена: Подвальников А.С.
/*Для дробного числа К напечатать фразу "мы нашли К грибов в лесу",
согласовав окончание слова "гриб" с числом К.*/
#include <iostream>
#include <cmath>

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
    else if(((int(K) % 100 != 12 && int(K) % 100 != 13 && int (K) % 100 != 14 ) && ((int(K) % 10 == 2) || (int(K) % 10 == 3) || (int(K) % 10 == 4 )))||(K != round(K) || K !=floor(K)))
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

