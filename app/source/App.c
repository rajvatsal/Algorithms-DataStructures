#include "nsa.h"
#include <math.h>
#include <stdio.h>

double f(double x)
{
    return pow(x, 3) - x - 1;
}

int main()
{
    printf("\nresult: %.12f", getRootByRegulaFalsi(f, 12));
}
