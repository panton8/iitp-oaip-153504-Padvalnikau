//������������ 7, ������ 9. ���������: ������������ �.�.
/*9. ����� �� ����� ���������� ���� (�������� ����� ������) �����
� ���, ��� ������ ������� ������������ ������ ���������� �������
��������� �����-������ ������. ������, ����������� (��� ��������) ��
���������, ������ � ������� ��������� �� ��������� b � �������� ����
�������� ����� �� 0 �� b - 1. ������� �������, ���� �����, ��� �����
�������� � ������ ������ ����. ��������, ������ �������� �������
��������� ����� ����������� ������� ���������, ��� ������ ������� ����
0, 1, 2 ���� ����� 1, 2 � 3. ���� ��������������� ��������, � ��� ���������
����� n � ��� ������� ���������? ��������, ����� 7 � ���� �������
������������ ��� 21, ��� ��� 7 = 2 x 3 + 1, � ����� 22 ������������ ��� 211, ���
��� 22 = 2 x 9 + 1 x 3 + 1.*/

#include <iostream>
using namespace std;

bool negative;

void system3(int a, string& Digit) {
    if (a / 3)
        system3(a / 3, Digit);
    string temp = to_string(a % 3);
    Digit.push_back(temp[0]);
}
string convert_new3(string digit3, string& Digit, int size) {
    string temp3; temp3[0] = digit3[size];
    short a;
    if (atoi(temp3.c_str()) < 1) {
        string temp = to_string(atoi(temp3.c_str()) + 3);
        Digit[size] = temp[0];
        if (size == 0) {
            string newDigit;
            newDigit.resize(size + 1);
            newDigit[0] = '2';
            for (short j = 0, k = 1; j < Digit.length(); ++j, ++k) newDigit[k] = Digit[j];
            return newDigit;
        }
        temp[0] = digit3[size - 1];
        a = atoi(temp.c_str()) - 1;
        if (a >= 0) {
            temp.erase(0, 1);
            string y = to_string(a);
            temp.push_back(y[0]);
            digit3[size - 1] = temp[0];
        }
        else {
            bool zero = 0;
            a += 3;
            temp.erase(0, 1);
            string y = to_string(a);
            temp.push_back(y[0]);
            if (digit3[size - 1] == '0') zero = 1;
            digit3[size - 1] = temp[0];
            if (zero) {
                temp[0] = digit3[size - 2];
                a = atoi(temp.c_str()) - 1;
                temp = to_string(a);
                digit3[size - 2] = temp[0];
            }
        }
    }
    else Digit[size] = digit3[size];
    if (size - 1 == 0 && digit3[size - 1] == '0') {
        if(negative)
            putchar('-');
        Digit.erase(0, 1);
       return Digit;
    }
    if(size == 0) {
        if (negative)
            putchar('-');
       return  Digit;
    }
    return convert_new3(digit3, Digit, size - 1);
}

int main() {
    int digit;
    string Digit;
    std::cout << "Enter the num for calculate it in new notation: " << std::endl;
    cin >> digit;
    if (digit < 0) {
        digit *= -1;
        negative = false;
    }
    if (digit == 0){
        cout << 0;
        return 0;
    }
    system3(digit, Digit);
    string digit3 = Digit;
    int size = 0;
    for(int i = 0; Digit[i] != '\0'; i++)
        size++;
    std::cout << convert_new3(digit3, Digit, size-1);
    return 0;
}