#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int N = 0;
    std::cout << "Enter size of your magic square: " << std::endl;
    while(true)
    {
        std::cin >> N;
        if(std::cin.fail() ||  N != (long long)N || N < 0 || N!= round(N))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    int **arr;
    arr = (int **) malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        arr[i] = (int *) malloc(N * sizeof(int));
    }
    std::cout << "Enter terms of massive" <<std::endl;
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < N ; j++) {
            while(true)
            {
                std::cin >> arr[i][j];
                if(std::cin.fail() ||  i != (long long)i || i!= round(i) || j != (long long)j || j!= round(j))
                {
                    std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
                    std::cin.clear();
                    std::cin.ignore(32000,'\n');
                    continue;
                }
                break;
            }
        }
    }
    std::cout << "Your square: " << std::endl;
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < N ; j++)
        {
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
//rows
    int rows[N];
    for(int i = 0; i < N; i++)
    {   for(int j = 0; j < N; j++)
            rows[i] += arr[i][j];
    }
//columns
    int cols[N];
    for(int j = 0; j < N; j++)
    {   for(int i = 0; i < N; i++)
            cols[j] += arr[i][j];
    }
//diagonal1
    int mD = 0;
    for(int i = 0; i < N; i++)
        mD += arr[i][i];
//diagonal2
    int sD = 0;
    for(int i =0; i < N; i++)
        sD += arr[i][N-i-1];
//check
    bool check = true;
    if(mD != sD)
        check = false;
    for(int i = 0; i < N; i++)
        if(mD != rows[i] || mD != cols[i])
        {   check = false;
            break;
        }
    if(check)
        std::cout << "It's a magic square!!!" << std::endl;
    else
        std::cout << "It's not a magic square!" << std::endl;
    for (int i = 0; i < N; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}