#include <stdio.h>

void printArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("ITEM %d: %d\n", i + 1, arr[i]);
    }
}
