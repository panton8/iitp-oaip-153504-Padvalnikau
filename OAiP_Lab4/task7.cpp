//Лабораторная 4, задача 7. Выполнена: Подвальников А.С.
/*Дано натуральное число n. Требуется подсчитать количество цифр
числа и определить, какая цифра стоит в разряде с номером i (разряды
нумеруются с конца, т.е. разряд единиц имеет номер 0).*/

#include <iostream>
#include <cmath>

int main()
{
    int i = 0,n,temp ;
    std::cout << "Enter your number: " << std::endl;
    while(true)
    {
        std::cin >> n;
        if(std::cin.fail() || n < 1 || n != (int)n || n != round(n))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    temp = n;
    while(n){
        n /= 10;
        i++;
    }
    std::cout << "You have " << i << " digits" << std::endl;
    int *arr = new int [i];
        for (int j = 0; j < i; j++) {
            arr[j] = temp % 10;
            temp /= 10;
        }
    for(int j = i-1; j > -1 ;j--)
    {
        std::cout << "digit(" << j << ") = " << arr[j] << std::endl;
    }
    delete[] arr;
    return 0;
}