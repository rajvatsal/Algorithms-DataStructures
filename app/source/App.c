#include "printArray.h"
#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50
#define RANGE 100

void shuffle(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int myArray[SIZE];
    int tempArray[RANGE];

    // Fill tempArray with numbers 1 to 100
    for (int i = 0; i < RANGE; i++)
    {
        tempArray[i] = i + 1;
    }

    srand(time(NULL));         // Seed random number generator
    shuffle(tempArray, RANGE); // Shuffle the array

    // Copy first 50 elements to myArray
    for (int i = 0; i < SIZE; i++)
    {
        myArray[i] = tempArray[i];
    }

    int len = sizeof(myArray) / sizeof(myArray[0]);

    printf("\nUNSORTED ARRAY\n");
    printArray(myArray, len);

    quicksort(myArray, len);

    printf("\nSORTED ARRAY\n");
    printArray(myArray, len);

    return 0;
}
