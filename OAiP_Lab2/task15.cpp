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
        cout << "ERROR";
    }
    else if (K == round(K))
    {
        cout << "Mi nashli" << " " << K << " " <<"gribov";
    }
    else
    {
        cout << "Mi nashli" << " " << K << " " << "griba";
    }
    return 0;
}

