#include "math.h"
#include "nsa.h"
#include <stdio.h>

double f(double x)
{
    return pow(x, 3) - x - 1;
}

int main()
{
    double matrix[3][3] = {
        {3, 0, 1},
        {6, 1, 1},
        {-3, 1, 0}};
    double L[3][3] = {{2, -4, 1}, {4, 1, 5}, {1, 1, 2}};
    double U[3][3] = {{2, -4, 1}, {4, 1, 5}, {1, 1, 2}};

    decomposeMatrixToLU(matrix, L, U);
}
