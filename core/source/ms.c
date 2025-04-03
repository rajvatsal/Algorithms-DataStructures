#include <stdio.h>

void mergesort(int *arr, int start, int end)
{
    int i = start;
    int j = ((end - start) / 2) + i;
    int x = j + 1;
    int y = end;
    int size = (end - start) + 1;

    // sort left and right halves individaully (DIVIDE PROBLEM)
    if (i != j)
    {
        mergesort(arr, i, j);
    }
    if (x != y)
    {
        mergesort(arr, x, y);
    }

    // merge two sorted halves together (COMBINE TO GET FINAL ANSwER)
    int tmpArry[size];
    int count = 0;
    while (count < size)
    {
        if (arr[i] <= arr[x])
        {
            tmpArry[count] = arr[i];
            ++i;
        }
        else
        {
            tmpArry[count] = arr[x];
            ++x;
        }
        ++count;

        // if x is out of bounds
        if (x > y)
        {
            while (count < size)
            {
                tmpArry[count] = arr[i];
                ++i;
                ++count;
            }
            break;
        }

        // if i is out of bounds
        if (i > j)
            break;
    }

    // copy to original array
    for (int i = 0; i < count; ++i)
    {
        arr[start + i] = tmpArry[i];
    }
}

int main()
{
    int arr[10] = {11, 10, 5, 40, 50, 42, 1, 47, 21, 28};

    printf("BEFORE:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d | ", arr[i]);
    }

    // sort
    mergesort(arr, 0, 9);

    printf("\nAFTER:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d | ", arr[i]);
    }
}
