//Лабораторная 7, задача 2. Выполнена: Подвальников А.С.
/*Перевести числа из прямого кода в обратный. Предусмотреть
ввод положительных и отрицательных чисел.*/
#include <iostream>

std::string reverseCode(std::string straight_code){
    std::string reverse_code;
    int str_size = 0;
    for(int i = 0; straight_code[i] != '\0'; i++)
        str_size++;
    for(int i = 0; i < str_size; i++)
    {
        if(i == 0)
            reverse_code += straight_code[0];
        if(straight_code[0] == '0' && i > 0)
            reverse_code += straight_code[i];
        else
            if( i > 0 && straight_code[i] == '0')
                reverse_code += '1';
            else if( i > 0 && straight_code[i] == '1')
                reverse_code += '0';
    }
    return reverse_code;
}

int main(){
    std::string straight_code;
    std::cout << "Enter the straight code: " << std::endl;
    std::cin >> straight_code;
    std::string reverse_code = reverseCode(straight_code);
    std::cout << reverse_code;
    return 0;
}