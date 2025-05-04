#include "nsa.h"
#include <math.h>
#include <stdio.h>

void initCoordinates(float *pts, float (*f)(float))
{
    int i = 0;
    pts[0] = pts[1] = i;

    do
    {
        if (f(i) < 0)
        {
            pts[0] = i;
        }
        else
        {
            pts[1] = i;
        }
        i++;
    } while (f(pts[0]) * f(pts[1]) >= 0);
}

int isZero(float num, int decimal)
{
    int quotient = pow(10, decimal + 1);
    return fabs(num) < 1.f / quotient;
}

float getRootByBisection(float a, float b, float (*f)(float), int decimal)
{
    float c = (a + b) / 2;
    float fc = f(c);

    float x;
    float y;

    if (isZero(fc, 5))
    {
        return c;
    }
    else if (fc < 0)
    {
        return getRootByBisection(c, b, f, decimal);
    }
    else
    {
        return getRootByBisection(a, c, f, decimal);
    }
}

float getRootByRegulaFalsi(float a, float b, float (*f)(float), int decimal)
{
    // c = a - f(a) . (b - a) / (f(b) - f(a))

    float c = a - (f(a) * ((b - a) / (f(b) - f(a))));

    float fc = f(c);

    if (isZero(fc, decimal))
    {
        return c;
    }
    else if (fc < 0)
    {
        return getRootByRegulaFalsi(c, b, f, decimal);
    }

    else
    {
        return getRootByRegulaFalsi(a, c, f, decimal);
    }
}
