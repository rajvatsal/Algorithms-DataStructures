#include "math.h"
#include "nsa.h"
#include <stdio.h>

double f(double x)
{
    return pow(x, 3) - x - 1;
}

int main()
{
    double values[3];

    printf("%lf", getRootByNewtonRaphson(f, 4));
}
