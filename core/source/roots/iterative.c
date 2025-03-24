#include "iterative.h"
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
    int mul = pow(10, decimal);
    return floorf(fabs(num) * mul) == 0;
}

float bisectionMethod(float a, float b, float (*f)(float), int decimal)
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
        return bisectionMethod(c, b, f, decimal);
    }
    else
    {
        return bisectionMethod(a, c, f, decimal);
    }
}

float regulaFalsiMethod(float x, float y, float (*f)(float), int decimal)
{
    // c = x - f(x) . (y - x) / (f(y) - f(x))

    float c = x - (f(x) * ((y - x) / (f(y) - f(x))));

    float fc = f(c);

    if (isZero(fc, decimal))
    {
        return c;
    }
    else if (fc < 0)
    {
        return regulaFalsiMethod(c, y, f, decimal);
    }

    else
    {
        return regulaFalsiMethod(x, c, f, decimal);
    }
}

float getRoot(float (*f)(float), rootMethod_t method, int decimal)
{
    float points[2];
    initCoordinates(points, f);

    float root;

    switch (method)
    {
    case bisection:
        root = bisectionMethod(points[0], points[1], f, decimal);
        break;
    case regula_falsi:
        root = regulaFalsiMethod(points[0], points[1], f, decimal);
        break;
    }

    return root;
}
