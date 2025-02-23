#include "insertionsort.h"
#include "printArray.h"

int main()
{
    int arr[] = {5, 2, 3, 1, 4, 10, 10, 51, 15, 20, 100, 200, 500, 600, 110, 150, 140, 250, 240, 230};
    insertionSort(arr, sizeof arr / sizeof arr[0]);
    printArray(arr, sizeof arr / sizeof arr[0]);

    return 0;
}
