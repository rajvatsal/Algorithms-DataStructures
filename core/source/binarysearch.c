#include "binarysearch.h"
#include <stdio.h>

/** ALGORITHM
 * Step 1: initialize start = 0, end = len - 1
 * Step 2: c = (end - start) / 2;
 * Step 3: if arr[c] == target {
 * return c};
 * else if arr[c] < target then {
 * end = c - 1;
 * repeat steps 2 and 3
 * }
 * else start = c+1 repeat steps 2 & 3
 */
int binarySearch(int target, int len, int arr[len])
{
    int c;
    int start = 0;
    int end = len - 1;

    do
    {
        c = ((end - start) / 2) + start;
        if (c >= len || c < 0)
        {
            c = len + 1;
            break;
        }
        if (target < arr[c])
        {
            end = c - 1;
        }
        else
        {
            start = c + 1;
        }
    } while (arr[c] != target);

    return c;
}

int binarySearchRecursive(int target, int start, int end, int len, int arr[len])
{
    int c = (end - start / 2) + start;

    if (c >= len || c < 0)
        return len + 1;
    else if (arr[c] == target)
        return c;
    else if (target < arr[c])
        return binarySearchRecursive(target, start, c - 1, len, arr);
    else
        return binarySearchRecursive(target, c + 1, end, len, arr);
}
