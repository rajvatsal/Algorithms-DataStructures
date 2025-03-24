#include "quicksort.h"
#include <stdlib.h>
#include <time.h>

int getRandomPivot(int iFirst, int iLast)
{
    return (rand() % (iLast - iFirst)) + iFirst;
}

int getMedianOfThreePivot(int *arr, int iFirst, int iLast)
{
    int iMiddle = (iFirst + iLast) / 2;
    int vFirst = arr[iFirst], vMiddle = arr[iMiddle], vLast = arr[iLast];

    if ((vFirst <= vMiddle && vMiddle <= vLast) || (vLast <= vMiddle && vMiddle <= vFirst))
        return iMiddle;
    if ((vMiddle <= vFirst && vFirst <= vLast) || (vLast <= vFirst && vFirst <= vMiddle))
        return iFirst;
    return iLast;
}

void sort(int *arr, const int index, const int lastIndex, partitionType_t type)
{
    const int len = (lastIndex - index) + 1;

    if (len < 2 || index > lastIndex)
    {
        // if there is only one element or we're out of the array we want to sort then
        return;
    }

    int i = index;
    int j = lastIndex;
    int pivot;

    switch (type)
    {
    case MEDIAN_OF_THREE:
        pivot = getMedianOfThreePivot(arr, i, j);
        break;

    case RANDOM:
        pivot = (rand() % (j - i)) + i;
        break;
    default:
        pivot = (((len + 1) / 2) - 1) + i;
        break;
    };

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

    sort(arr, index, pivot - 1, type);
    sort(arr, pivot + 1, lastIndex, type);
}

void quicksort(int *arr, int len, partitionType_t type)
{
    if (type == RANDOM)
    {
        srand(time(NULL));
    }
    sort(arr, 0, len - 1, type);
}
