#include "library.h"

#include <iostream>

int* copy::copy_arr(int *A, int from, int to)
{
    int *B = new int [to - from];
    for(int i = from; i < to; i++)
    {
        B[i-from] = A[i];
    }
    return B;
}