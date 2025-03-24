#include "fillRandomInt.h"
#include "mergesort.h"
#include "quicksort.h"
#include <stdio.h>
#include <time.h>

int main()
{
    int arr[90000];
    int backupArr[sizeof(arr) / sizeof(arr[0])];
    double timeRecord[4];
    double totalTime = 0.0f;
    partitionType_t type = MEDIAN_OF_THREE;

    fillRandomInt(arr, 90000, 500000);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        backupArr[i] = arr[i];
    }

    printf("---------------------------------MIDDLE----------------------------------\n");
    type = MIDDLE;
    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
            arr[i] = backupArr[i];
        }
        clock_t begin = clock();
        quicksort(arr, sizeof arr / sizeof arr[0], type);
        clock_t end = clock();
        double timeTaken = (double)(end - begin) / CLOCKS_PER_SEC;
        timeRecord[0] += timeTaken;
        printf("TIME: %f\n", timeTaken);
    }
    printf("AVERAGE: %f\n", timeRecord[0] / 10);

    printf("---------------------------------MEADIAN OF THREE----------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
            arr[i] = backupArr[i];
        }
        clock_t begin = clock();
        quicksort(arr, sizeof arr / sizeof arr[0], type);
        clock_t end = clock();
        double timeTaken = (double)(end - begin) / CLOCKS_PER_SEC;
        timeRecord[1] += timeTaken;
        printf("TIME: %f\n", timeTaken);
    }
    printf("AVERAGE: %f\n", timeRecord[1] / 10);

    printf("----------------------------------RANDOM----------------------------------\n");
    type = RANDOM;
    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
            arr[i] = backupArr[i];
        }
        clock_t begin = clock();
        quicksort(arr, sizeof arr / sizeof arr[0], type);
        clock_t end = clock();
        double timeTaken = (double)(end - begin) / CLOCKS_PER_SEC;
        timeRecord[2] += timeTaken;
        printf("TIME: %f\n", timeTaken);
    }
    printf("AVERAGE: %f\n", timeRecord[2] / 10);

    printf("----------------------------------MERGE SORT----------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
            arr[i] = backupArr[i];
        }
        clock_t begin = clock();
        mergesort(arr, sizeof arr / sizeof arr[0]);
        clock_t end = clock();
        double timeTaken = (double)(end - begin) / CLOCKS_PER_SEC;
        timeRecord[4] += timeTaken;
        printf("TIME: %f\n", timeTaken);
    }
    printf("AVERAGE: %f", timeRecord[4] / 10);
    return 0;
}
