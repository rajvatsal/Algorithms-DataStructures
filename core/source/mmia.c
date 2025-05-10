#include "mmia.h"

int getMax(int len, int arr[len])
{
    int max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int getMin(int len, int arr[len])
{
    int min = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
