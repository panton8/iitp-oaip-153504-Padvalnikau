//Лабораторная 7, задача 1.2. Выполнена: Подвальников А.С.
/*Необходимо разработать программу для перевода чисел из
семеричной в двенадцатеричную систему счисления.Выполнить решение
задачи без использования массивов.*/

#include <iostream>
#include <cmath>

/*void system12(int num,int size){
    int num1 = 0;
    for (int i = 0; i < size; i++)
    {
        num1 += (num % 10) * pow(7, i);
        num /= 10;
    }
    int rem;
    for (int i = 0; i < size-1; i++)
    {
        rem = num1 % 12;
        num1 = (num1 - rem) / 12;
        if (rem == 10)
            std::cout << 'a';
        else
            std::cout << rem;
    }
    if (num1 == 10)
        std::cout << 'a';
    else
        std::cout << num1;
}

int main()
{
    int num;
    std::cout << "Enter the num: " << std::endl;
    std::cin >> num;
    int temp_num = num;
    int size1 = 1;
    while (temp_num >= 10){
        temp_num /= 10;
        size1++;
    }
    system12(num,size1);
    return 0;
}*/


void from10To12(int notation10)
{
    if (notation10 > 12)
        from10To12(notation10 / 12);
    if (notation10 % 12 == 10)
        std::cout << "a";
    if(notation10 % 12 == 11)
        std::cout << 'b';
    if (notation10 % 12 < 12 && notation10 % 12 != 10 && notation10 % 12 < 11)
        std::cout << notation10 % 12;
}

int main()
{
    int num;
    std::cout << "Enter the num: " << std::endl;
    std::cin >> num;
    int temp_num = num;
    int digit = 1;
    while (temp_num >= 10)
    {
        temp_num /= 10;
        digit++;
    }
    int notation10 = 0;
    for (int i = 0; i < digit; i++)
    {
        notation10 += (num % 10) * pow(7, i);
        num /= 10;
    }
    from10To12(notation10);
    std::cout << std::endl;
    return 0;
}