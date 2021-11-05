//Лабораторная 4, задача 12. Выполнена: Подвальников А.С.
/*12. Написать функцию которая будет удалять дубликаты элементов
из массива. Входные параметры: массив, длинна массива. Выходные
параметры: новый массив, новый размер.*/
#include <iostream>
#include <time.h>
int n2 ;
int* RepDel(int *arr,int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n; k++)
                    arr[k] = arr[k + 1];
                n--;
                j--;
            }
        }
    }
    n2 = n;
    return arr;
}
int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];
    srand(time(nullptr));
    std::cout << "Array: " << std::endl;
    for (int i = 0; i < n; ++i) {
        arr[i] = 1 + rand() % 10;
        std::cout << " " << arr[i];
    }
    std::cout << std::endl << "Array without duplicates: " << std::endl;
    RepDel(arr,n);
    for(int i = 0;i < n2;i++) {
    std::cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}