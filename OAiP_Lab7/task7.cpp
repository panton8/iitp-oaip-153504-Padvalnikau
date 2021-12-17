//Лабораторная 7, задача 7. Выполнена: Подвальников А.С.
/*Необходимо разработать программу, которая проверяет, делится
ли введенное пользователем число на 3, 37, 89 . Программа не
должна содержать операций умножения, деления, вычитания (в том числе
взятия остатка от деления). Рекомендуется использовать побитовые
операции.Проверять можно по отдельности (сначала получить ответ для
первого, затем для второго, затем для третьего).*/

#include <iostream>

int subtr(int x, int y) {
    while (y) {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}
int inc(int i) {
    int mask = 1;
    while (i & mask) {
        i &= ~mask;
        mask <<= 1;
    }
    i |= mask;
    return i;
}
int diV(int n, int d) {
    int q = 0;
    while (n >= d) {
        int i = 0, temp_d = d;
        while (n >= (temp_d << 1)) {
            i = inc(i);
            temp_d <<= 1;
        }
        q |= 1 << i;
        n = subtr(n, temp_d);
    }
    return q;
}
int add(int x, int y) {
    while (y) {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}
int mult(int a, int b) {
    int result = 0;
    while (b) {
        if (b & 01) result = add(result, a);
        a <<= 1; b >>= 1;
    }
    return result;
}
int mod(int a, int b) {
    int r = diV(a, b);
    return subtr(a, mult(r, b));
}

int main() {

    int num = 0, check_div1 = 3, check_div2 = 37, check_div3 = 89;
    std::cout << "Enter num for check divisibility: " << std::endl;
    std::cin >> num;

    if (mod(num, check_div1))
        std::cout << num << " don't share on " << check_div1 << std::endl;
    else
        std::cout << num << " share on " << check_div1 << std::endl;

    if (mod(num, check_div2))
        std::cout << num << " don't share on " << check_div2 << std::endl;
    else
        std::cout << num << " share on " << check_div2 << std::endl;

    if (mod(num, check_div3))
        std::cout << num << " don't share on " << check_div3 << std::endl;
    else
        std::cout << num << " share on " << check_div3 << std::endl;

    return 0;
}