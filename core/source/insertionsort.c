#include "insertionsort.h"
#include <stdio.h>

void insertionSort(int len, int arr[len])
{
    for (int i = 0; i < len; i++)
    {
        int j = i;
        while (j > 0)
        {
            if (arr[j] > arr[j - 1])
            {
                break;
            }

            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}
