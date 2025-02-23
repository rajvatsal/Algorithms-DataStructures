#include "mergesort.h"

// merge two arrays
void conquer(int *arr, int i, int j, int end)
{
    int tmp[end - i];

    int leftEnd = j;
    int start = i;
    int k = 0;
    while (1)
    {
        if (arr[i] < arr[j])
        {
            tmp[k] = arr[i];
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            j++;
        }

        k++;

        if (i == leftEnd)
        {
            i = start;
            while (i - start < k)
            {
                arr[i] = tmp[i - start];
                i++;
            }
            break;
        }
        else if (j == end)
        {
            int correctValueIndex = k;
            while (k + start < end)
            {
                arr[k + start] = arr[i];
                i++;
                k++;
            }

            i = start;
            k = 0;
            while (k < correctValueIndex)
            {
                arr[i] = tmp[k];
                i++;
                k++;
            }
            break;
        }
    }
}

void divide(int *arr, int start, int end)
{
    if (end - start == 1 || start - end == 1)
    {
        return;
    }

    int middle = ((end - start) / 2) + start;
    divide(arr, start, middle);
    divide(arr, middle, end);

    conquer(arr, start, middle, end);
}

void mergesort(int *arr, int len)
{
    divide(arr, 0, len);
}
