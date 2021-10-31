//Лабораторная 4, задача 12. Выполнена: Подвальников А.С.
/*12. Написать функцию которая будет удалять дубликаты элементов
из массива. Входные параметры: массив, длинна массива. Выходные
параметры: новый массив, новый размер.*/
#include <iostream>
#include <time.h>

void RepDel(int *arr,int n)
{
    srand(time(nullptr));
    std::cout << "Array:v" << std::endl;
    for (int i = 0; i < n; ++i) {
        arr[i] = 1 + rand() % 10;
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n; k++)
                    arr[k] = arr[k + 1];
                n--;
                j--;
            }
    std::cout << "Array without duplicates: " << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << arr[i]<< " ";
}
int main()
{
    int *arr = new int[45];
    RepDel(arr,45);
    delete[] arr;
}
