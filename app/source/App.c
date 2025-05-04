#include "nsa.h"
#include <stdio.h>

float f(float x, float y)
{
    return (y - x) / (y + x);
}

int main()
{
    printf("\nresult: %f", approxResultByEuler(0.f, 1.f, 0.1f, 0.02f, f, 1));
}
