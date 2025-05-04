#include "nsa.h"
#include <math.h>
#include <stdio.h>

void initCoordinates(double *x0, double *x1, double (*f)(double x))
{
    int i = 0;
    *x0 = *x1 = 0.f;

    do
    {
        if (f(i) < 0)
        {
            *x0 = i;
        }
        else
        {
            *x1 = i;
        }
        i++;
    } while (f(*x0) * f(*x1) >= 0);
}

int isZero(double num, int decimal)
{
    return fabs(num) < pow(10, -(++decimal)); // is the difference between number and 0 very less
}

int checkIfEqual(double x, double y, int decimal)
{
    return fabs(x - y) < pow(10, -(++decimal)); // are there values very close
}

double getRootByBisection(double (*f)(double x), unsigned short int decimal)
{
    double a = 0.f;
    double b = 0.f;
    double c = 0.f;

    initCoordinates(&a, &b, f);

    do
    {
        c = (a + b) / 2; //' bisection formula to get next value
        if (f(c) < 0.f)
        {
            a = c;
        }
        else
        {
            b = c;
        }
    } while (!isZero(f(c), decimal));

    return c;
}

double getRootByRegulaFalsi(double (*f)(double), unsigned short int decimal)
{
    double a = 0.f;
    double b = 0.f;
    double c = 0.f;

    initCoordinates(&a, &b, f);

    do
    {
        c = a - (f(a) * ((b - a) / (f(b) - f(a)))); // regula falsi formula to get next value
        if (f(c) < 0.f)
        {
            a = c;
        }
        else
        {
            b = c;
        }
    } while (!isZero(f(c), decimal));

    return c;
}

double approxResultByEuler(double x, double y, double lastValueOfX, double stepSize, double (*f)(double x, double y), unsigned short int accuracyFactor)
{
    int count = 0;

    while (!checkIfEqual(x, lastValueOfX, accuracyFactor))
    {
        if (x > lastValueOfX)
        {
            return 0.f;
        }
        double result = y + (stepSize * f(x, y)); // Euler's formula
        printf("y: %.2lf | x: %.2lf | y1: %.2lf | iteration: %d\n", y, x, result, count + 1);
        x += stepSize;
        y = result;
        count++;
    }

    return y;
}

double getRootBySecant(double (*f)(double x), unsigned short int accuracyFactor)
{
    double x0 = 0.f;
    double x1 = 0.f;
    double x2 = 0.f;
    accuracyFactor = accuracyFactor > 15 ? 15 : accuracyFactor;

    initCoordinates(&x0, &x1, f);

    do
    {
        x2 = x0 - (f(x0) * ((x1 - x0) / (f(x1) - f(x0))));
        x0 = x1;
        x1 = x2;
    } while (!isZero(f(x2), accuracyFactor));

    return x2;
}
