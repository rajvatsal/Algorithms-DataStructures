#include "nsa.h"
#include <stdio.h>

int main()
{
    int roots[3];
    int matrix[3][4] = {{1, 1, 1, 3},
                        {2, -1, -1, 3},
                        {1, -1, 1, 9}};

    getRootByGaussElimination(3, 4, matrix, roots);

    printf("%d %d %d\n", roots[0], roots[1], roots[2]);
}
