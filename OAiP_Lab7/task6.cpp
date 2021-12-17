//������������ 7, ������ 6. ���������: ������������ �.�.
/*����� S(x) ��� ����� ���� ����� �,����������� � ���������� �������
���������.��������,S(5) = 5,S(10) = 1,S(322) = 7. �� ����� �������� �����
� ����������,���� S(x+1) < S(x).� ������ ����� ���� ����� n.���� ������
��������� ���������� ����� � �����,��� 1 <= x <= n � �-����������.*/

#include<iostream>

long long S(long long n){
    if(n == 0)
        return 0;
    return (n % 10) + S(n/10);
}

long long interesting(long long num){
    return (num+1)/10;
}

int main() {
    short count;
    int n;
    std::cout << "Enter num of repeat: " << std::endl;
    std::cin >> count;
    while(count){
        std::cout << "Enter the num: " << std::endl;
        std::cin >> n;
        std::cout << interesting(n) << std::endl;
        count--;
    }
    return 0;
}