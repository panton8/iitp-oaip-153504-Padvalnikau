#include <iostream>
#include <iomanip>
#include <cmath>


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

std::string system3(int k){
    std::string str3;
    for(int i = 4; i >= 0; i--){
        int a = (k % 3);
        if( a == 0) str3 += '0';
        if( a == 1) str3 += '1';
        if( a == 2) str3 += '2';
        k /= 3;
    }
    str3 = reverse(str3,5);
    return str3;
}

int main() {
    int time = 48;
    std::string barrels[240];
    std::string slave1[50];
    std::string slave2[50];
    std::string slave3[50];
    std::string slave4[50];
    std::string slave5[50];
    std::string left[50];
    for (int i = 1; i <= 240; i++) {
        barrels[i] = system3(i);
    }
    int j = 0, k = 0, p = 0, n = 0, m = 0, r = 0;
    for (int i = 1; i <= 240; i++) {
        if (barrels[i][1] == '0')
            slave1[j++] = barrels[i];
        if (barrels[i][2] == '0')
            slave2[k++] = barrels[i];
        if (barrels[i][3] == '0')
            slave3[p++] = barrels[i];
        if (barrels[i][4] == '0')
            slave4[n++] = barrels[i];
        if (barrels[i][5] == '0')
            slave5[m++] = barrels[i];
        if(barrels[i][1] != '0' && barrels[i][2] != '0' && barrels[i][3] != '0' && barrels[i][4] != '0' &&
           barrels[i][5] != '0')
            left[r++] = barrels[i];
    }
    int left_slaves = 0;
    std::cout << "Enter num of left slaves after first check: " << std::endl;
    std::cin >> left_slaves;
    std::cout << "First check is completed." << std::endl << "Slaves left: " << left_slaves << "" << std::endl
              << "The number of options for the number of the poisoned barrel: " << pow(2, left_slaves) << std::endl
              << "Time left: " << time - 24 << " hours" << std::endl;
    switch(left_slaves){
        case 5:
            std::cout << "Second check is completed.Poison in 1 of 6 barrels that a slave will drink and poison";
            break;
        case 4:
            std::cout << "Second check is completed.Poison in 1 of 4 barrels that a slave will drink and poison";
            break;
        case 3:
                std::cout << "Second check is completed.Poison in (1 of 3) or (1 of 2) barrels that a slave will drink and poison";
                break;
        case 2:
                std::cout << "Second check is completed.Poison in 1 of 2 barrels that a slave will drink and poison";
                break;
        case 1:
                std::cout << "Second check is completed.Poison in 1 of 2  barrels that a slave will drink and poison";
                break;
    }
    return 0;
}
