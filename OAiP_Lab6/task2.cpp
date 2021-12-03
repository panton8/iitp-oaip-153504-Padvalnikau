//Лабораторная 6, задача 2. Выполнена: Подвальников А.С.
/*Напечатать квитанцию об оплате за телеграмму, если известна
стоимость одного слова.*/

#include <iostream>
#include <cstring>

int numWord(char* str)
{
    int space = 0;
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' && str[i+1] == ' ')
            count--;
    }
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i]))
            count++;
        if(str[i] == ' ')
            space++;
    }

    if (space == strlen(str))
        return 0;
    return count + 1;

}

int main()
{
    int sum = 0;
    char *str = new char[80];
    std::cout << "Enter the telegram: " << std::endl;
    gets(str);
    std::cout << "Enter cost of one word: " << std::endl;
    std::cin >> sum;
    int bill = numWord(str) * sum;
    std::cout << str << std::endl;
    std::cout << "The bill for telegram: " << bill << std::endl;
    delete[] str;
    return 0;
}