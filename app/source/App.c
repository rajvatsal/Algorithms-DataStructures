#include "binarysearch.h"
#include "insertionsort.h"
#include <stdio.h>

int main(int argc, char *argv[argc])
{
    int arr[10] = {100, 12, 121, 89, 59, 21, 99, 41, 10, 22};
    insertionSort(10, arr);

    int target = binarySearchRecursive(121, 0, 9, 10, arr);
    printf("value: %d | index: %d \n", arr[target], target);
    return 0;
}
