#pragma once

typedef enum partitionType
{
    MIDDLE,
    MEDIAN_OF_THREE,
    RANDOM,
} partitionType_t;

void quicksort(int *, int, partitionType_t type);
