//Лабораторная 8, задача 1. Выполнена: Подвальников А.С.
/*Разработать программу, реализующую работу со структурами в консольном приложении.
Использовать динамический массив структур, содержащий поля согласно варианту индивидуального задания.
Программа должна содержать необходимые комментарии.Следует ввод/вывод на экран входных и выходных данных. Для
форматированного ввода-вывода использовать scanf и printf, предусмотреть некорректный ввод. Обрабатываемая
структура должна иметь не менее пяти полей (элементов) двух и более типов (если в задании указано меньше -
добавить). В каждом варианте задания реализовать следующие функции для работы со структурой:
1. Функцию формирования динамического одномерного массива структур,
значения которых вводятся с клавиатуры. Предусмотреть возможность
заполнения одного поля структуры, используя известные значения других полей
структуры (придумать самим). С массивом структур работать через оператор new.
При вводе структур необходимо реализовать следующие механизмы:
• ввод заранее заданного количества структур;
• ввод до появления структуры с заданным признаком;
• диалог с пользователем о необходимости продолжать ввод.
2. Функцию просмотра содержимого динамического массива структур.
3. Функцию дополнения уже существующего массива структур новыми
структурами.
4. Функцию поиска и вывода на экран структуры (структур) с заданным
значением элемента.
5. Функции удаления и изменения элемента массива структур с заданным
значением элемента.
6. Функцию упорядочения массива структур по одному из полей
(элементов). Поле для сортировки выбрать самим.
В магазине сформирован список постоянных клиентов, который включает
ФИО, домашний адрес покупателя и размер предоставляемой скидки. Вывести
всех покупателей, имеющих 5 % скидку (сортировка вставкой по возрастанию).*/
#include <iostream>

using namespace std;

struct client_base{
    char firstname[25];
    char lastname[25];
    char middlename[25];
    char address[35];
    int sale;
};

client_base *addStruct(client_base* Obj, int &OldSize, int &NewSize) {
    NewSize = OldSize + NewSize;
    if (OldSize == 0) {
        Obj = new client_base[NewSize];
    }
    else {
        client_base *temp_Obj = new client_base[NewSize];
        for (int i = 0; i < OldSize; i++) {
            temp_Obj[i] = Obj[i];
        }
        delete[] Obj;
        Obj = temp_Obj;
    }
    return Obj;
}

void setStruct(client_base* obj, int &OldSize, int NewSize) {
    int index;
    cout << "Choose, how you want to input data:\n 1 - full all memory\n 2 - full to a certain element\n";
    while (!(cin >> index)) {
        cout << "Enter correct value\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (index == 1) {
        for (int i = OldSize; i < NewSize; i++) {
            printf("FIO of costumer %d: ", i + 1);
            rewind(stdin);
            while (!(cin >> obj[i].lastname >> obj[i].firstname >> obj[i].middlename)) {
                cout << "Enter correct value\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            printf("Address: ");
            while (!(cin >> obj[i].address)) {
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            printf("Size of sale: ");
            while (!(cin >> obj[i].sale)) {
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            OldSize = NewSize;
        }
    }
    else if (index == 2) {
        cout << "Choose element:\n 1 - FIO\n 2 - address\n 3 - size of sale\n";
        int count;
        while(!(cin >> count)){
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        string value;
        cout << "Enter value:\n";
        while(!(cin >> value)){
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        for (int i = OldSize; i < NewSize; i++) {
            printf("Enter FIO:\n");
            rewind(stdin);
            while (!(cin >> obj[i].lastname >> obj[i].firstname >> obj[i].middlename)) {
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 1 && (obj[i].lastname == value && obj[i].firstname == value && obj[i].middlename == value)) {
                break;
            }
            printf("Enter the address:\n");
            while(!(cin >> obj[i].address)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 2 && ((obj[i].address) == value)) {
                break;
            }
            printf("Enter the size of sale:\n");
            while(!(cin >> obj[i].sale)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 3 && (to_string(obj[i].sale) == value)) {
                break;
            }
        }
    }
}

void showStruct(client_base* obj, int NewSize) { // вывести структуру
    for (int i = 0; i < NewSize; i++)
    {
        printf("Costumer %d : \n",i + 1);
        printf("FIO: %s  %s  %s \n", obj[i].lastname, obj[i].firstname, obj[i].middlename);
        printf("Address: %s \n", obj[i].address);
        printf("Size of sale: %d \n", obj[i].sale);
        printf("\n***************************************\n");
    }
}

void searchData(client_base* obj, int NewSize) {
    int N;
    cout << "Choose element for searching:\n 1 - lastname\n 2 - firstname\n 3 - middlename\n 4 - Address\n 5 - Size of sale\n";
    cin >> N;
    if (N == 1) {
        string k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            printf("Costumer %d : \n",i + 1);
            printf("FIO: %s  %s  %s \n", obj[i].lastname, obj[i].firstname, obj[i].middlename);
            printf("Address: %s \n", obj[i].address);
            printf("Size of sale: %d \n", obj[i].sale);
            printf("\n***************************************\n");
        }
    }
    else if (N == 2) {
        string k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            printf("Costumer %d : \n",i + 1);
            printf("FIO: %s  %s  %s \n", obj[i].lastname, obj[i].firstname, obj[i].middlename);
            printf("Address: %s \n", obj[i].address);
            printf("Size of sale: %d \n", obj[i].sale);
            printf("\n***************************************\n");
        }
    }
    else if (N == 3) {
        string k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            printf("Costumer %d : \n",i + 1);
            printf("FIO: %s  %s  %s \n", obj[i].lastname, obj[i].firstname, obj[i].middlename);
            printf("Address: %s \n", obj[i].address);
            printf("Size of sale: %d \n", obj[i].sale);
            printf("\n***************************************\n");
        }
    }
    else if (N == 4) {
        string k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            printf("Costumer %d : \n",i + 1);
            printf("FIO: %s  %s  %s \n", obj[i].lastname, obj[i].firstname, obj[i].middlename);
            printf("Address: %s \n", obj[i].address);
            printf("Size of sale: %d \n", obj[i].sale);
            printf("\n***************************************\n");
        }
    }
    else if (N == 5) {
        int k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            printf("Costumer %d : \n",i + 1);
            printf("FIO: %s  %s  %s \n", obj[i].lastname, obj[i].firstname, obj[i].middlename);
            printf("Address: %s \n", obj[i].address);
            printf("Size of sale: %d \n", obj[i].sale);
            printf("\n***************************************\n");
        }
    }
}
client_base* delStruct(client_base* Obj, int &Size) {
    int k;
    cout << "1 - delete struct\n 2 - Change struct\n";
    while (!(cin >> k)) {
        cout << "Enter correct value:\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (k == 1) {
        int m;
        showStruct(Obj, Size);
        cout << "Choose element, which you want delete:\n";
        while (!(cin >> m)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        int j = 0;
        client_base* temp_Obj = new client_base[Size - 1];
        for (int i = 0; i < Size; i++) {
            if (i != m - 1){
                temp_Obj[j] = Obj[i];
                j++;
            }
            else
                continue;
        }
        Size--;
        delete[] Obj;
        Obj = temp_Obj;
    }
    else if (k == 2) {
        int m;
        showStruct(Obj, Size);
        cout << "Choose element, which you want change:\n";
        while (!(cin >> m)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        m--;
        printf("Enter FIO:\n");
        rewind(stdin);
        while (!(cin >> Obj[m].lastname >> Obj[m].firstname >> Obj[m].middlename)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        printf("Enter address:\n");
        while (!(cin >> Obj[m].address)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        printf("Enter the size of sale:\n");
        while (!(cin >> Obj[m].sale)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return Obj;
}

void sale5(client_base* obj, int n){
    for (int i = 0; i < n; i++)
    {
        if(obj[i].sale == 5) {
            printf("Costumer %d : \n", i + 1);
            printf("FIO: %s  %s  %s \n", obj[i].lastname, obj[i].firstname, obj[i].middlename);
            printf("Address: %s \n", obj[i].address);
            printf("Size of sale: %d \n", obj[i].sale);
            printf("***************************************\n");
        }
    }
}

void insertSort(client_base* arr, int n)
{
    client_base temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j-1].lastname[0] > arr[j].lastname[0])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

int main() {
    client_base* people = 0;
    int oldSize = 0;
    int newSize = 0;
    do {
        int action;
        cout << "Choose action:\n 1 - create arrays of struct\n 2 - show data\n 3 - search by element\n 4 - Sort by lastname\n 5 - delete/change\n 6 - people with 5% sale\n 0 - exit\n";
        while (!(cin >> action) || action > 6) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (action == 1) {
            printf("Enter size:\n");
            scanf("%d", &newSize);
            people = addStruct(people, oldSize, newSize);
            setStruct(people, oldSize, newSize);
            oldSize = newSize;
        }
        else if (action == 2) {
            showStruct(people, newSize);
        }
        else if (action == 3) {
            if(people != 0)
                searchData(people, newSize);
        }
        else if (action == 4) {
            if (people != 0)
                insertSort(people, newSize);
        }
        else if (action == 5) {
            if (people != 0)
                people = delStruct(people, newSize);
        }
        else if (action == 6){
            sale5(people,newSize);
        }
        else if (action == 0) {
            break;
        }
    } while (true);
    return 0;
}