//Лабораторная 8, задача 2. Выполнена: Подвальников А.С.
/*Разработать программу,реализующую работу с файлами в консольном приложении.
Информация, обрабатываемая программой, должна хранитьсяв файле, результат работы
занести в другой файл и отобразить на экране.Использовать динамический массив структур,
содержащий поля согласно варианту индивидуального задания. Выделение памяти реализовать через
calloc.Программа должна содержать необходимые комментарии.Следует предусмотреть простейший вывод
на экран входных и выходных данных. В каждом варианте задания реализовать следующие функции для
работы со структурой: инициализации данных, добавления,удаления, корректировки и просмотра записей файла.
1. На междугородной АТС информация о разговорах содержит
дату разговора, код и название города, время разговора, тариф, номер
телефона в этом городе и номер телефона абонента. Вывести по каждому
городу общее время разговоров с ним и сумму.
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct PhoneInfo {
    char data[15];
    int kod;
    char city[20];
    long talkTime;
    int tariff;
    char cityNum[20];
    char subNum[20];
};

PhoneInfo *addStruct(PhoneInfo* Obj, int &OldSize, int &NewSize) {
    NewSize = OldSize + NewSize;
    if (OldSize == 0) {
        Obj = (PhoneInfo*) calloc(NewSize,sizeof(PhoneInfo));
    }
    else {
        PhoneInfo *temp_Obj = (PhoneInfo*) calloc(NewSize,sizeof(PhoneInfo));
        for (int i = 0; i < OldSize; i++) {
            temp_Obj[i] = Obj[i];
        }
        delete[] Obj;
        Obj = temp_Obj;
    }
    return Obj;
}

void showStruct(PhoneInfo* obj,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("The data of talking: %s\n", obj[i].data);
        printf("The kod: %d\n", obj[i].kod);
        printf("The name of city: %s\n", obj[i].city);
        printf("The talkTime: %d\n", obj[i].talkTime);
        printf("The tariff: %d\n", obj[i].tariff);
        printf("The cityNum: %s\n", obj[i].cityNum);
        printf("The subNum: %s\n", obj[i].subNum);
        printf("*******************************\n");
    }
}

void fileUsing(PhoneInfo* obj, int n) {
    ofstream output;
    output.open("D:/bsuir/OAiP/OAiP_Lab8/res.txt");
    if (!output.is_open())
        printf("File open error\n");
    char city[30];
    printf("Enter the CityName for calculating result:");
    scanf("%s", city);
    string str1 = "City: ";
    string str2 = "TotalTime: ";
    string str3 = "Sum: ";
    string str4 = "*********************";
    int totalTime = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        if (!strcmp(city, obj[i].city)) {
            sum += (obj[i].talkTime/60.0) * obj[i].tariff;
            totalTime += obj[i].talkTime;
        }
    }
        output << str1 << city << endl;
        output << str2 << totalTime << endl;
        output << str3 << sum << endl;
        output << str4 << endl;
        output.close();
}

void insertSort(PhoneInfo* arr, int n)
{
    PhoneInfo temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j-1].city[0] > arr[j].city[0])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void setStruct(PhoneInfo* obj, int &OldSize, int NewSize) {
    int index;
    cout << "Choose, how you want to input data:\n 1 - full all memory\n 2 - full to a certain element\n";
    while (!(cin >> index)) {
        cout << "Enter correct value\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (index == 1) {
        for (int i = OldSize; i < NewSize; i++) {
            printf("The data of talking: \n");
            rewind(stdin);
            while (!(cin >> obj[i].data)) {
                cout << "Enter correct value\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            printf("The kod: \n");
            while (!(cin >> obj[i].kod)) {
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            printf("The name of city: \n");
            while (!(cin >> obj[i].city)) {
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            printf("The talkTime: \n");
            while (!(cin >> obj[i].talkTime)) {
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            printf("The tariff: \n");
            while (!(cin >> obj[i].tariff)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            printf("The cityNum: \n");
            while (!(cin >> obj[i].cityNum)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            printf("The subNum: \n");
            while (!(cin >> obj[i].subNum)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            OldSize = NewSize;
            for(int i = 0; i < NewSize; i++){
                for(int j = 0; j < NewSize; j++)
                if(obj[i].city == obj[j].city)
                    obj[i].talkTime += obj[j].talkTime;

            }
        }
    }
    else if (index == 2) {
        cout << "Choose element:\n 1 - The data of talking\n 2 - The kod\n 3 - The name of city\n 4 - The talkTime\n 5 - The tariff\n 6 - The cityNum\n 7 - The subNum\n";
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
            printf("Enter the data of talking:\n");
            rewind(stdin);
            while (!(cin >> obj[i].data)) {
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 1 && (obj[i].data)) {
                break;
            }
            printf("Enter The kod:\n");
            while(!(cin >> obj[i].kod)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 2 && (to_string(obj[i].kod) == value)) {
                break;
            }
            printf("Enter the name of city:\n");
            while(!(cin >> obj[i].city)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 3 && ((obj[i].city) == value)) {
                break;
            }
            printf("Enter the talkTime:\n");
            while(!(cin >> obj[i].talkTime)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 4 && (to_string(obj[i].talkTime) == value)) {
                break;
            }
            printf("Enter the tariff:\n");
            while(!(cin >> obj[i].tariff)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 5 && (to_string(obj[i].tariff) == value)) {
                break;
            }
            printf("Enter the cityNum:\n");
            while(!(cin >> obj[i].cityNum)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 6 && ((obj[i].cityNum) == value)) {
                break;
            }
            printf("Enter the subNum:\n");
            while(!(cin >> obj[i].subNum)){
                cout << "Enter correct value:\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (count == 7 && ((obj[i].subNum) == value)) {
                break;
            }
        }
    }
}

PhoneInfo* delStruct(PhoneInfo* Obj, int &Size) {
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
        PhoneInfo* temp_Obj =(PhoneInfo*) calloc(Size - 1,sizeof(PhoneInfo));
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
        printf("Enter the data of talking:\n");
        rewind(stdin);
        while (!(cin >> Obj[m].data)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        printf("Enter The kod:\n");
        while (!(cin >> Obj[m].kod)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        printf("Enter the city name:\n");
        while (!(cin >> Obj[m].city)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        printf("Enter talktime of call: \n");
        while (!(cin >> Obj[m].talkTime)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        printf("Enter cost of tariff: \n");
        while (!(cin >> Obj[m].tariff)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        printf("Enter num of city: \n");
        while (!(cin >> Obj[m].cityNum)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        printf("Enter num of sub: \n");
        while (!(cin >> Obj[m].subNum)) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return Obj;
}

void searchData(PhoneInfo* obj, int NewSize) {
    int N;
    cout << "Choose element:\n 1 - The data of talking\n 2 - The kod\n 3 - The name of city\n 4 - The talkTime\n 5 - The tariff\n 6 - The cityNum\n 7 - The subNum\n";
    cin >> N;
    if (N == 1) {
        string k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            if (obj[i].data == k)
                printf("The data of talking: %s\n", obj[i].data);
            printf("The kod: %d\n", obj[i].kod);
            printf("The name of city: %s\n", obj[i].city);
            printf("The talkTime: %d\n", obj[i].talkTime);
            printf("The tariff: %d\n", obj[i].tariff);
            printf("The cityNum: %s\n", obj[i].cityNum);
            printf("The subNum: %s\n", obj[i].subNum);
            printf("*******************************\n");
        }
    }
    else if (N == 2) {
        int k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            if (obj[i].kod == k)
                printf("The data of talking: %s\n", obj[i].data);
            printf("The kod: %d\n", obj[i].kod);
            printf("The name of city: %s\n", obj[i].city);
            printf("The talkTime: %d\n", obj[i].talkTime);
            printf("The tariff: %d\n", obj[i].tariff);
            printf("The cityNum: %s\n", obj[i].cityNum);
            printf("The subNum: %s\n", obj[i].subNum);
            printf("*******************************\n");
        }
    }
    else if (N == 3) {
        string k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            if (obj[i].city == k)
                printf("The data of talking: %s\n", obj[i].data);
            printf("The kod: %d\n", obj[i].kod);
            printf("The name of city: %s\n", obj[i].city);
            printf("The talkTime: %d\n", obj[i].talkTime);
            printf("The tariff: %d\n", obj[i].tariff);
            printf("The cityNum: %s\n", obj[i].cityNum);
            printf("The subNum: %s\n", obj[i].subNum);
            printf("*******************************\n");
        }
    }
    else if (N == 4) {
        int k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            if (obj[i].talkTime == k)
                printf("The data of talking: %s\n", obj[i].data);
            printf("The kod: %d\n", obj[i].kod);
            printf("The name of city: %s\n", obj[i].city);
            printf("The talkTime: %d\n", obj[i].talkTime);
            printf("The tariff: %d\n", obj[i].tariff);
            printf("The cityNum: %s\n", obj[i].cityNum);
            printf("The subNum: %s\n", obj[i].subNum);
            printf("*******************************\n");
        }
    }
    else if (N == 5) {
        int k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            if (obj[i].tariff == k)
                printf("The data of talking: %s\n", obj[i].data);
            printf("The kod: %d\n", obj[i].kod);
            printf("The name of city: %s\n", obj[i].city);
            printf("The talkTime: %d\n", obj[i].talkTime);
            printf("The tariff: %d\n", obj[i].tariff);
            printf("The cityNum: %s\n", obj[i].cityNum);
            printf("The subNum: %s\n", obj[i].subNum);
            printf("*******************************\n");
        }
    }
    else if (N == 6) {
        string k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            if (obj[i].cityNum == k)
                printf("The data of talking: %s\n", obj[i].data);
            printf("The kod: %d\n", obj[i].kod);
            printf("The name of city: %s\n", obj[i].city);
            printf("The talkTime: %d\n", obj[i].talkTime);
            printf("The tariff: %d\n", obj[i].tariff);
            printf("The cityNum: %s\n", obj[i].cityNum);
            printf("The subNum: %s\n", obj[i].subNum);
            printf("*******************************\n");
        }
    }
    else if (N == 7) {
        string k;
        cout << "Enter value:\n";
        cin >> k;
        cout << "Result of research:\n";
        for (int i = 0; i < NewSize; i++)
        {
            if (obj[i].subNum == k)
                printf("The data of talking: %s\n", obj[i].data);
            printf("The kod: %d\n", obj[i].kod);
            printf("The name of city: %s\n", obj[i].city);
            printf("The talkTime: %d\n", obj[i].talkTime);
            printf("The tariff: %d\n", obj[i].tariff);
            printf("The cityNum: %s\n", obj[i].cityNum);
            printf("The subNum: %s\n", obj[i].subNum);
            printf("*******************************\n");
        }
    }
}

void usingDataFromFile(PhoneInfo *data,int oldSize,int newSize){
    fstream input("data.txt");
    input.open("D:/bsuir/OAiP/OAiP_Lab8/data.txt");
    if(!input.is_open())
        printf("File open error \n");
    else{
        printf("File is open\n");
        for (int i = 0; i < newSize; i++)
        {
            input >> data[i].data;
            input >> data[i].kod;
            input >> data[i].city;
            input >> data[i].talkTime;
            input >> data[i].tariff;
            input >> data[i].cityNum;
            input >> data[i].subNum;
        }
    }
    input.close();
}

int main() {
    PhoneInfo *data = 0;
    int oldSize;
    int newSize;
    ofstream output;
    ifstream input;
    do {
        int action;
        cout << "Choose action:\n 1 - create arrays of struct\n 2 - show data\n 3 - search by element\n 4 - Sort by Cityname\n 5 - delete/change\n 6 - Create file with results\n 7 - full arrays of struct from file \n 0 - exit\n";
        while (!(cin >> action) || action > 7) {
            cout << "Enter correct value:\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (action == 1) {
            printf("Enter the size:\n");
            scanf("%d", &newSize);
            data = addStruct(data, oldSize, newSize);
            setStruct(data, oldSize, newSize);
            oldSize = newSize;
        }
        else if (action == 2) {
            showStruct(data, newSize);
        }
        else if (action == 3) {
            if(data != 0)
                searchData(data, newSize);
        }
        else if (action == 4) {
            if (data != 0)
                insertSort(data, newSize);
        }
        else if (action == 5) {
            if (data != 0)
                data = delStruct(data, newSize);
        }
        else if (action == 6) {
            fileUsing(data,newSize);
        }

        else if(action == 7) {
            printf("Enter the size:\n ");
            scanf("%d", &newSize);
            data = addStruct(data,oldSize,newSize);
            usingDataFromFile(data,oldSize,newSize);
            oldSize = newSize;
        }
        else if (action == 0) {
            break;
        }
    } while (true);
    return 0;
}