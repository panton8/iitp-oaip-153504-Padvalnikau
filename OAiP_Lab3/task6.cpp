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
    double result_sin, result_cos,result_atan,lower_limit,upper_limit,limit_step,common_result;
    int parts_of_limit;
    std::cout << "Enter lower and upper limits: " << std::endl;
    std::cin >> lower_limit >> upper_limit;
    double min_res_sin = fabs(sin(lower_limit));
    double min_res_cos = fabs(cos(lower_limit));
    double min_res_atan = fabs(atan(lower_limit));
    std::cout << "Enter parts of limit : " << std::endl;
    std::cin >> parts_of_limit;
    limit_step = (upper_limit - lower_limit) / parts_of_limit;
    std::cout << "Therefore step of limit : " << limit_step << std::endl;
    double x = lower_limit;
    for(int i = 1; i <= parts_of_limit; i++ )
    {
        x+=limit_step;
        result_sin = fabs(sin(x));
        if(result_sin < min_res_sin)
            min_res_sin = result_sin;
        result_cos = fabs(cos(x));
        if(result_cos < min_res_cos)
            min_res_cos = result_cos;
        result_atan = fabs(atan(x));
        if(result_atan < min_res_atan)
            min_res_atan = result_atan;
        common_result = min_res_sin + min_res_cos - 2  * min_res_atan;
    }
    std::cout << "Result of expression: " << common_result;
    return 0;
}

