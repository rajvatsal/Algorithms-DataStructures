#include "quicksort.h"
#include <stdio.h>

int main()
{
    int myArray[5] = {20, 30, 40, 50, 60};
    int len = sizeof(myArray) / sizeof(myArray[0]);
    quicksort(myArray, len);
    return 0;
}
