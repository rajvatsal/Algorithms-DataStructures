#include "roots/iterative.h"
#include <math.h>
#include <stdio.h>

float f(float x)
{
    // equation is x3 + x - 5 = 0
    return pow(x, 3) - x - 1;
}

int main()
{
    rootMethod_t method = regula_falsi;
    float root = getRoot(f, method, 4);
    printf("ROOT: %f", root);
}
