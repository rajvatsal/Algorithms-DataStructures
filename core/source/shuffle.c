// Fisher Yates shuffle

#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int len)
{
    srand(time(NULL)); // Seed random number generator
    for (int i = len - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
