#include "nsa/bisection.h"
#include <math.h>
#include <stdio.h>

float f(float x)
{
    // equation is x3 + x - 5 = 0
    return pow(x, 3) - x - 5;
}

int main()
{
    float root = bisectRoot(f);
    printf("ROOT: %f", root);
}
