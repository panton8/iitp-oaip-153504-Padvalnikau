//Лабораторная 3, задача 6. Выполнена: Подвальников А.С.
/*Необходимо приближенно найти корень уравнения f(x) = 0 для
функции из своего варианта(sin x + cos x - 2 atan x). Корень нужно найти по следующему алгоритму:
перебираем значения от начала до конца интервала с некоторым шагом и
ищем значение функции, минимальное по модулю. Аргумент, при котором оно
достигается, считаем корнем уравнения. Программа должна запросить у
пользователя, на сколько частей разделить область поиска корня, вычислить
шаг, с которым нужно проходить значения, пройти в цикле нужные значения,
найти корень и вывести его.*/

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double result_sin, result_cos,result_atan,lower_limit,upper_limit,limit_step,common_result,x_min,x,parts_of_limit;
    while(true)
    {
        std::cout << "Enter lower ,upper limits and parts of limit: " << std::endl;
        std::cin >> lower_limit >> upper_limit >> parts_of_limit;
        if(std::cin.fail() || (lower_limit > upper_limit) || (lower_limit != (long long)lower_limit) || (upper_limit != (long long)upper_limit || (parts_of_limit < 1.0 ||  parts_of_limit != (long long)parts_of_limit) ||  parts_of_limit != round(parts_of_limit)))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    x = lower_limit;
    limit_step = (upper_limit - lower_limit) / parts_of_limit;
    std::cout << "Therefore, step of limit : " << limit_step << std::endl;
    double min_common_res = fabs(sin(lower_limit) + cos(lower_limit) - 2 * atan(lower_limit));
    for(int i = 0; i < parts_of_limit; i++ )
    {
        x+=limit_step;
        result_sin = sin(x);
        result_cos = cos(x);
        result_atan = atan(x);
        common_result = fabs(result_sin + result_cos - 2  * result_atan);
        if (common_result < min_common_res)
        {
            min_common_res = common_result;
            x_min = x;
        }
    }
    std::cout << "Minimum approximate value :" <<min_common_res << std::endl;
    std::cout << "With x = " <<std::fixed << std::setprecision(20) << x_min;
    return 0;
}