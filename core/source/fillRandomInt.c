// Fill Random Values To An Array

#include "shuffle.h"

void fillRandomInt(int *myArray, int size, int range)
{
    int tempArray[range];

    // Fill tempArray with numbers 1 to range
    for (int i = 0; i < range; i++)
    {
        tempArray[i] = i + 1;
    }

    shuffle(tempArray, range);

    // Copy first size(number of elements) elements to myArray
    for (int i = 0; i < size; i++)
    {
        myArray[i] = tempArray[i];
    }
}
