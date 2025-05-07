#include "nsa.h"
#include <stdio.h>

double fx(double y, double z)
{
    return 7 - y - z;
}

double fy(double x, double z)
{
    return (13 - x - z) / 3;
}

double fz(double x, double y)
{
    return (13 - (2 * y) - x) / 2;
}

int main()
{
    double values[3];

    getValuesByGaussJacobi(fx, fy, fz, values, 9);

    printf("%lf %lf %lf\n", values[0], values[1], values[2]);
}
