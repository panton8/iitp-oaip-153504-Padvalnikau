//Лабораторная 7, задача 4. Выполнена: Подвальников А.С.
/*Осуществить сложение и вычитание чисел в двенадцатеричной системе
счисления. В другую систему счисления не переводить. В системах
счисления больших десятичной использовать буквы по аналогии с
шестнадцатеричной системой. Разработать функции для выполнения
операции сложения и функции для выполнения операции вычитания.
Предусмотреть ввод положительных и отрицательных чисел.*/
#include <iostream>
using namespace std;

bool minus1, minus2;

string convert_letter(char number) {
    string temp = "";
    switch (number) {
        case 'a': temp = "10"; break;
        case 'b': temp = "11"; break;
        default: temp = number;
    }
    return temp;
}
string convert_number(short letter) {
    string temp = "";
    switch (letter) {
        case 10: temp = "a"; break;
        case 11: temp = "b"; break;
        default: temp = to_string(letter);
    }
    return temp;
}

void Sum(string a, string b, string sum, short i) {
    string temp_a = convert_letter(a[i]); string temp_b = convert_letter(b[i]);
    short temp_sum = atoi(temp_a.c_str()) + atoi(temp_b.c_str());
    if (temp_sum > 11) { temp_sum = temp_sum - 12;
        string temp = convert_number(temp_sum); sum[i] = temp[0];
        if (i == 0) {
            string newsum; newsum.resize(sum.length() + 1);
            newsum[0] = '1';
            for (short j = 0, k = 1; j < sum.length(); ++j, ++k) newsum[k] = sum[j];
            cout << newsum; return;
        }
        string new_a = convert_letter(a[i - 1]);
        short NEW = atoi(new_a.c_str()) + 1; string A = convert_number(NEW);
        a[i - 1] = A[0];
    }
    else { string temp = convert_number(temp_sum); sum[i] = temp[0]; }
    if (i == 0) { cout << sum; return; }
    Sum(a, b, sum, --i);
}

void diff(string a, string b, string sum, short i) {
    string temp_a = convert_letter(a[i]); string temp_b = convert_letter(b[i]);
    short temp_notsum = atoi(temp_a.c_str()) - atoi(temp_b.c_str());

    if (temp_notsum < 0) {

        string ty = convert_letter(a[i]);
        short y = atoi(ty.c_str()) + 11;
        string tx = convert_letter(b[i]);
        short x = atoi(tx.c_str());
        short div = y - x; string tempagain = to_string(div); sum[i] = tempagain[0];

        if (i == 0) {
            string newsum; newsum.resize(sum.length() + 1);
            newsum[0] = 'b';
            for (short j = 0, k = 1; j < sum.length(); ++j, ++k) newsum[k] = sum[j];
            cout << newsum; return;
        }

        string new_a = convert_letter(a[i - 1]);
        short NEW = atoi(new_a.c_str()) - 1;
        if (NEW < 0) NEW += 12;
        string A = convert_number(NEW);
        a[i - 1] = A[0];
    }

    else { string temp = convert_number(temp_notsum); sum[i] = temp[0]; }
    if (i == 0) { cout << sum; return; }
    diff(a, b, sum, --i);
}

int main() {
    string a, b, sum;
    cin >> a >> b;
    short size_a = a.length(), size_b = b.length();
    if (a[0] == '-') {
        minus1 = 1;
        string temp;
        temp.resize(a.length() - 1);
        for (short i = 1, k = 0; i < a.length(); ++i, ++k) temp[k] = a[i];
        a.resize(temp.length());
        a = temp;
        size_a = a.length();
    }
    if (b[0] == '-') {
        minus2 = 1;
        string temp;
        temp.resize(b.length() - 1);
        for (short i = 1, k = 0; i < b.length(); ++i, ++k) temp[k] = b[i];
        b.resize(temp.length());
        b = temp;
        size_b = b.length();
    }
    short size = size_a > size_b ? size_a : size_b;
    if (size_a < size) {
        string temp = a;
        short j = 0;
        a.resize(size);
        for (short i = 0; i < size; ++i) a[i] = '0';
        for (short i = temp.length() - 1; i >= 0; --i, ++j) a[size - j - 1] = temp[i];
    }
    if (size_b < size) {
        string temp = b;
        short j = 0;
        b.resize(size);
        for (short i = 0; i < size; ++i) b[i] = '0';
        for (short i = temp.length() - 1; i >= 0; --i, ++j) b[size - j - 1] = temp[i];
    }
    sum.resize(size, '0');
    if (minus1 && minus2) {
        cout << a << " + " << b << " = ";
        putchar('-');
        Sum(a, b, sum, size);
        cout << endl;
        cout << a << " - " << b << " = ";
        diff(a, b, sum, size);
    }
    if ((minus1 && !minus2) || (minus2 && !minus1)) {
        cout << a << " + " << b << " = ";
        diff(a, b, sum, size);
        cout << a << " - " << b << " = ";
        cout << endl;
        Sum(a, b, sum, size);
        cout << endl;
    }
    if (!minus1 && !minus2) {
        cout << a << " + " << b << " = ";
        Sum(a, b, sum, size);
        std::cout << std::endl;
        cout << a << " - " << b << " = ";
        diff(a, b, sum, size);
        cout << endl;
    }
    return 0;
}