#include "quicksort.h"

static inline int getPivotByMedianOfThree(int *arr, int iFirst, int iLast)
{
    int iMiddle = (iFirst + iLast) / 2;
    int vFirst = arr[iFirst], vMiddle = arr[iMiddle], vLast = arr[iLast];

    if ((vFirst <= vMiddle && vMiddle <= vLast) || (vLast <= vMiddle && vMiddle <= vFirst))
        return iMiddle;
    if ((vMiddle <= vFirst && vFirst <= vLast) || (vLast <= vFirst && vFirst <= vMiddle))
        return iFirst;
    return iLast;
}

static inline void swap(int *arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(const int index, const int lastIndex, int *arr)
{
    int i = index;
    int j = lastIndex;
    int m = getPivotByMedianOfThree(arr, i, j - 1);

    int value = arr[m];
    arr[m] = arr[i];
    arr[i] = value;

    while (i < j)
    {
        do
            i++;
        while (value > arr[i]);

        do
            j--;
        while (value < arr[j]);

        if (i < j)
            swap(arr, i, j);
    }

    arr[index] = arr[j];
    arr[j] = value;

    return j;
}

void quicksort(int p, int q, int *arr)
{
    if (p < q)
    {
        int j = partition(p, q + 1, arr);
        quicksort(p, j - 1, arr);
        quicksort(j + 1, q, arr);
    }
}
