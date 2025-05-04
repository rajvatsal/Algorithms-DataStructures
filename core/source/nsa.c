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
    return fabs(num) < pow(10, -(++decimal)); // is the difference between number and 0 very less
}

int checkIfEqual(float x, float y, int decimal)
{
    return fabs(x - y) < pow(10, -(++decimal)); // are there values very close
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

float approxResultByEuler(float x, float y, float lastValueOfX, float stepSize, float (*f)(float x, float y), int accuracyFactor)
{
    int count = 0;

    while (checkIfEqual(x, lastValueOfX, accuracyFactor))
    {
        if (x > lastValueOfX)
        {
            return 0.f;
        }
        float result = y + (stepSize * f(x, y)); // Euler's formula
        printf("y: %f | x: %f | euler: %f | iteration: %d\n", y, x, result, count + 1);
        x += stepSize;
        y = result;
        count++;
    }

    return y;
}
