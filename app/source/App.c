#include "fillRandomInt.h"
#include "nsa/bisection.h"
#include "printArray.h"
#include "quicksort.h"
#include <stdio.h>

int main()
{
    int myArray[50];
    int len = sizeof(myArray) / sizeof(myArray[0]);

    fillRandomInt(myArray, len, 100);

    printf("\nUNSORTED ARRAY\n");
    printArray(myArray, len);

    quicksort(myArray, len);

    printf("\nSORTED ARRAY\n");
    printArray(myArray, len);

    return 0;
}
