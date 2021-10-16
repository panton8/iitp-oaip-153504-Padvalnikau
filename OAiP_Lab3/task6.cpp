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

int main()
{
    double result_sin, result_cos,result_atan,lower_limit,upper_limit,limit_step,common_result,x_min;
    int parts_of_limit;
    std::cout << "Enter lower and upper limits: " << std::endl;
    if (std::cin >> lower_limit >> upper_limit){
    }
    else
    {
        std::cout << "Incorrect type of variable";
        return -1;
    }
    if(upper_limit < lower_limit)
    {
        std::cout << "Your input is incorrect";
        return -1;
    }
    std::cout << "Enter parts of limit : " << std::endl;
    if (std::cin >> parts_of_limit){
    }
    else
    {
        std::cout << "Incorrect type of variable";
        return -1;
    }
    if(parts_of_limit < 1)
    {
        std::cout << "Your input is incorrect";
        return -1;
    }
    limit_step = (upper_limit - lower_limit) / parts_of_limit;
    std::cout << "Therefore, step of limit : " << limit_step << std::endl;
    double min_common_res = fabs(sin(lower_limit) + cos(lower_limit) - 2 * atan(lower_limit));
    double x = lower_limit;
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
    std::cout << "With x = " << x_min;
    return 0;
}