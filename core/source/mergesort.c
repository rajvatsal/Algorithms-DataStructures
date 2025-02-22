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
            while (j < end)
            {
                tmp[k] = arr[j];
                j++;
                k++;
            }
            break;
        }
        else if (j == end)
        {
            while (i < leftEnd)
            {
                tmp[k] = arr[i];
                i++;
                k++;
            }
            break;
        }
    }

    for (int l = 0; l < sizeof tmp / sizeof tmp[0]; l++)
    {
        arr[l + start] = tmp[l];
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
