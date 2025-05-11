#include "quicksort.h"
#include <stdio.h>

int main(int argc, char *argv[argc])
{
    int arr[10] = {100, 12, 121, 89, 59, 21, 99, 41, 10, 22};
    quicksort(0, 9, arr);

    for (int i = 0; i < 10; i++)
    {
        printf("%d | ", arr[i]);
    }

    printf("\n");
    return 0;
}
