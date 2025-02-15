#include <stdio.h>

// int ceil(double num)
// {
//     int int_part = (int)num;
//     return (num > int_part) ? (int_part + 1) : int_part;
// }
//
void sort(int *arr, int startIndex, int endIndex)
{
    int len = (endIndex - startIndex) + 1;

    if (len < 2 || startIndex > endIndex)
    {
        return;
    }

    int i = startIndex;
    int j = endIndex;
    int pivot = ((len + 1) / 2 - 1) + i;

    while (i < j)
    {
        if (arr[i] >= arr[pivot] && arr[j] <= arr[pivot])
        {
            // Inversion Condition Met

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            // Update Pivot

            if (pivot == i)
            {
                i++;
                pivot = j;
                continue;
            }
            else if (pivot == j)
            {
                j--;
                pivot = i;
                continue;
            }
        }

        if (arr[i] < arr[pivot])
        {
            i++;
        }

        if (arr[j] > arr[pivot])
        {
            j--;
        }
    }

    sort(arr, startIndex, pivot - 1);
    sort(arr, pivot + 1, endIndex);
}

void quicksort(int *arr, int len)
{
    sort(arr, 0, len - 1);
}
