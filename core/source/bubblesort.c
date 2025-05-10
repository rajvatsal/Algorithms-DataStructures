#include "bubblesort.h"
#include <stdio.h>

/** ALGORITHM
 * Step 1: initialize i = 0 and j len - 1
 * Step 2: if arr[j] < arr[j - 1] then switch them
 * Step 3: if j = j - 1; if j > i then repeat step 2
 * Step 4: if i = i - 1; if i != len - 1 then i = i + 1 repeat step 2 and 3
 */

void bubblesort(int len, int arr[len])
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = len - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
