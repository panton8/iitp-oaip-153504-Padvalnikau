//������������ 7, ������ 1.2. ���������: ������������ �.�.
/*���������� ����������� ��������� ��� �������� ����� ��
���������� � ���������������� ������� ���������.��������� �������
������ ��� ������������� ��������.*/

#include <iostream>
#include <cmath>

void from10To12(int notation10)
{
    if (notation10 > 12)
        from10To12(notation10 / 12);
    if (notation10 % 12 == 10)
        std::cout << "a";
    if(notation10 % 12 == 11)
        std::cout << 'b';
    if (notation10 % 12 < 12 && notation10 % 12 != 10 && notation10 % 12 < 11)
        std::cout << notation10 % 12;
}

int main()
{
    int num;
    std::cout << "Enter the num: " << std::endl;
    std::cin >> num;
    int temp_num = num;
    int digit = 1;
    while (temp_num >= 10)
    {
        temp_num /= 10;
        digit++;
    }
    int notation10 = 0;
    for (int i = 0; i < digit; i++)
    {
        notation10 += (num % 10) * pow(7, i);
        num /= 10;
    }
    from10To12(notation10);
    std::cout << std::endl;
    return 0;
}