#include "insertionsort.h"
#include <stdio.h>

void insertionSort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            j--;
        }
    }
}
