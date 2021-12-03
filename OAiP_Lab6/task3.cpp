//Лабораторная 6, задача 3. Выполнена: Подвальников А.С.
/*Ввести матрицу. Элементы матрицы – строки. Подсчитать сумму
кодов символов каждого слова и, если сумма оказалась четной, развернуть
зеркально это слово в строке. Полученные матрицы вывести на экран.
Стандартных функций работы со строками не использовать.*/

#include <iostream>

int inputCheck(){
    int x;
    while(true){
        std::cin >> x;
        if(std::cin.fail() ||  x != (int)x)
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    return  x;
}

std::string reverse(std::string str, int size) {
    if (size == -1)
        return "";
    else
    {
        char a;
        a = str[size];
        return a + reverse(str, size - 1);
    }
}

int main()
{
    std::cout << "Enter size of array of string: " << std::endl;
    int M = inputCheck();
    int N = inputCheck();
    std::string **str = new std::string*[N];
    for(int i = 0; i < N; i++)
        str[i] = new std::string[M];
    std::cout << "Enter list of strings: " << std::endl;
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
        {
            std::cin >> str[i][j];
        }
    }
    std::cout << "Your list of strings: " << std::endl;
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
        {
            std::cout << str[i][j] << " ";
        }
        std::cout << std::endl;
    }
    long long sum[N*M];
    int m = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++){
            m++;
            for(int k = 0; k < str[i][j].length(); k++)
            sum[m] += str[i][j][k];
        }
    }
    std::cout << "Your new list after checking: " << std::endl;
    m = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++) {
            m++;
            if (sum[m] % 2 == 0)
                std::cout << reverse(str[i][j],str[i][j].length()) << " ";
            else
                std::cout << str[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i =0; i < N; i++)
        delete[]str[i];
    delete[] str;
    return 0;
}