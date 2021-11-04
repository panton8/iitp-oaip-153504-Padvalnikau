//Лабораторная 4, задача 15. Выполнена: Подвальников А.С.
/*Таблица заполняется по следующему алгоритму:
В таблицу вносятся все натуральные числа по порядку. 1 становится в левую
верхнюю ячейку, затем выбирается самая левая незаполненная ячейка в
самой первой строке таблицы и заполняется. Затем, пока у последней
заполненной ячейки сосед слева существует и заполнен, опускаемся вниз и
заполняем очередную ячейку. Когда же не окажется соседа слева, то
начинается заполнение клеток справа налево. После того как будет заполнена
ячейка в первом столбце, После этого алгоритм заполнения повторятся.
Необходимо вывести строку и столбец в котором будет находится число,
введенное с клавиатуры.*/

#include <iostream>
#include <cmath>


long long sqr(long long sq)
{
    return sq * sq;
}

int main()
{
    long long num = 0;
    std::cout << "Enter your number: " << std::endl;
    while(true)
    {
        std::cin >> num;
        if(std::cin.fail() || num < 1 ||  num != (long long)(num) || num != round(num))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    long long maxSq = sqrt(num);
    long long col_num = maxSq + 1;
    long long row, col;
    if (num - sqr(maxSq) == 0)
    {
        row = maxSq;
        col = 1;
    }
    else if (num - sqr(maxSq) < col_num)
    {
        row = num - sqr(maxSq);
        col = col_num;
    }
    else
    {
        row = col_num;
        col = sqr(maxSq+1) - num + 1;
    }
    std::cout << "Your number is in "<< "row:" << row << " and column:"<< col;
    return 0;
}