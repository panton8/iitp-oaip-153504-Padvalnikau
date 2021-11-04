//Лабораторная 4, задача 14. Выполнена: Подвальников А.С.
/*На вход подаётся поле для игры в "сапёр" размером n*m
символов, где символ '.' означает пустое место, а символ '*' - бомбу.
Требуется дополнить это поле числами , как в оригинальной игре. Выделение
памяти через функции языка С.*/

#include<iostream>

int Input() {
    int value;

    while (true)
    {
        std::cin >> value;

        if (!std::cin.fail())
            return value;

        std::cin.clear();
        std::cin.ignore(32000, '\n');
        std::cout << "Enter correct value" << std::endl;
    }
}
char InputSymbol() {
    char ch;

    while (true)
    {
        std::cin >> ch;

        if (!std::cin.fail() && (ch == '.' || ch == '*'))
            return ch;

        std::cin.clear();
        std::cin.ignore(32000, '\n');
        std::cout << "Enter correct value" << std::endl;
    }
}
char TopBombs(char** arr, int rowSize, int colSize) {
    int counter = 0;
    for (int i = rowSize; i < rowSize + 2; i++)
    {
        for (int j = colSize; j < colSize + 3; j++)
        {
            if (arr[i][j] == '*')
                counter++;
        }
    }
    if (counter > 0)
        return counter + 48;
    else
        return '.';
}
char OtherBombs(char** arr,int rowSize,int colSize) {
    int counter = 0;
    for (int i = rowSize; i <rowSize + 3; i++)
    {
        for (int j = colSize; j < colSize + 2; j++)
        {
            if (arr[i][j] == '*')
                counter++;
        }
    }
    if (counter > 0)
        return counter + 48;
    else
        return '.';
}

char CornerBombs(char** arr, int rowSize, int colSize) {
    int counter = 0;
    for (int i = rowSize; i < rowSize + 2; i++)
    {
        for (int j = colSize ; j < colSize + 2; j++)
        {
            if (arr[i][j] == '*')
                counter++;
        }
    }
    if (counter > 0)
        return counter + 48;
    else
        return '.';
}

char CentralBombs(char** arr, int rowSize,int colSize) {
    int counter = 0;
    for (int i = rowSize - 1; i < rowSize + 2; i++)
    {
        for (int j = colSize - 1; j < colSize + 2; j++)
        {
            if (arr[i][j] == '*')
                counter++;
        }
    }
    if (counter > 0)
        return counter + 48;
    else
        return '.';
}

int main() {
    int N = Input(), M = Input(), counter = 0;

    char** Field = (char**)malloc(N*sizeof(char));

    for (int i = 0; i < N; i++)
    {
        Field[i] = (char*)malloc(M * sizeof(char));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Field[i][j] = InputSymbol();
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Field[i][j] == '*')
                continue;

            if ((i == N - 1 && j == M - 1))
            {
                Field[i][j] = CornerBombs(Field, abs(i - 1), abs(j - 1));
            }
            else if (i == 0 && j == 0) {
                Field[i][j] = CornerBombs(Field, 0, 0);
            }
            else if (i == 0 && j == M - 1) {
                Field[i][j] = CornerBombs(Field, 0, abs(j-1));
            }
            else if (i == N - 1 && j == 0){

                Field[i][j] = CornerBombs(Field, abs(i - 1) , 0);
            }
            else if ( i == 0 && j != 0 && j != M - 1)
            {
                Field[i][j] = TopBombs(Field, 0, j - 1);
            }
            else if (i == N - 1 && j != 0 && j != M - 1)
            {
                Field[i][j] = TopBombs(Field, abs(i - 1), j - 1);
            }
            else if (j == M - 1 && i != 0 && i != N - 1)
            {
                Field[i][j] = OtherBombs(Field, i - 1 , abs(j-1));
            }
            else if(j == 0 && i != 0 && i != N - 1)
            {
                Field[i][j] = OtherBombs(Field, i - 1, j);
            }
            else
            {
                Field[i][j] =CentralBombs(Field, i , j );
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout <<Field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < M;i++){
        free(Field[i]);
    }
    free(Field);
    return 0;
}