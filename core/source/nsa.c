#include "nsa.h"
#include <math.h>
#include <stdio.h>

/*
 * TODO: Fix inline function not found in Debug Mode
 */

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

void printMatrix(int rows, int cols, double matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("| %.2f |\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void getValuesByGaussElimination(int rows, int columns, int matrix[rows][columns], int *values)
{
    int lrow = matrix[rows - 1][0];
    int urow = matrix[rows - 2][0];

    for (int i = 0; i < columns; i++)
    {
        matrix[rows - 1][i] = (matrix[rows - 1][i] * urow) - (matrix[rows - 2][i] * lrow);
    }

    lrow = matrix[rows - 2][0];
    urow = matrix[rows - 3][0];

    for (int i = 0; i < columns; i++)
    {
        matrix[rows - 2][i] = (matrix[rows - 2][i] * urow) - (matrix[rows - 3][i] * lrow);
    }

    lrow = matrix[rows - 1][1];
    urow = matrix[rows - 2][1];

    for (int i = 0; i < columns; i++)
    {
        matrix[rows - 1][i] = (matrix[rows - 1][i] * urow) - (matrix[rows - 2][i] * lrow);
    }

    values[2] = matrix[rows - 1][columns - 1] / matrix[rows - 1][columns - 2];
    values[1] = (matrix[rows - 2][columns - 1] - (matrix[rows - 2][columns - 2] * values[2])) / matrix[rows - 2][columns - 3];
    values[0] = (matrix[rows - 3][columns - 1] - (matrix[rows - 3][columns - 2] * values[2]) - (matrix[rows - 3][columns - 3] * values[1])) / matrix[rows - 3][columns - 4];
}

static inline int areCloseToAnInteger(double x, double y, double z, unsigned short int aFactor)
{
    double accuracyFactor = pow(10, -aFactor);

    int isX = fabs(x - floor(x + 1)) > accuracyFactor && fabs(x - floor(x)) > accuracyFactor;
    int isY = fabs(y - floor(y + 1)) > accuracyFactor && fabs(y - floor(y)) > accuracyFactor;
    int isZ = fabs(z - floor(z + 1)) > accuracyFactor && fabs(z - floor(z)) > accuracyFactor;

    if (isX || isY || isZ)
        return 0;

    return 1;
}

void getValuesByGaussSiedel(double fx(double y, double z), double fy(double x, double z), double fz(double x, double y), double values[3], unsigned short int accuracyFactor)
{
    values[0] = values[1] = values[2] = 0;
    int count = 0;
    int valuesAreCloseEnough = 1;

    do
    {
        values[0] = fx(values[1], values[2]);
        values[1] = fy(values[0], values[2]);
        values[2] = fz(values[0], values[1]);

        valuesAreCloseEnough = areCloseToAnInteger(values[0], values[1], values[2], accuracyFactor);

        count++;
    } while (count < 20 || !valuesAreCloseEnough);
}

void getValuesByGaussJacobi(double fx(double y, double z), double fy(double x, double z), double fz(double x, double y), double values[3], unsigned short int accuracyFactor)
{
    values[0] = values[1] = values[2] = 0;
    int count = 0;
    int valuesAreCloseEnough = 1;
    double x, y, z = 0;

    do
    {
        x = values[0];
        y = values[1];
        z = values[2];
        values[0] = fx(y, z);
        values[1] = fy(x, z);
        values[2] = fz(x, y);

        valuesAreCloseEnough = areCloseToAnInteger(values[0], values[1], values[2], accuracyFactor);

        count++;
    } while (count < 20 || !valuesAreCloseEnough);
}

static inline double derive(double (*f)(double value), double value)
{
    double delta = 1e-6;
    double x1 = value + delta;
    double x2 = value - delta;
    double y1 = f(x1);
    double y2 = f(x2);

    return (y2 - y1) / (x2 - x1);
}

double getRootByNewtonRaphson(double (*f)(double x), unsigned short int accuracyFactor)
{
    double a = 0;
    double b = 0;
    double x0 = (a + b) / 2;

    initCoordinates(&a, &b, f);

    do
    {
        double x1 = x0 - (f(x0) / derive(f, x0));
        x0 = x1;
    } while (!isZero(f(x0), accuracyFactor));

    return x0;
}

/* TODO: make this more general and less hardcoded.
 * introduce loops to make it more generic
 * allow it to take any square matrices
 */
void decomposeMatrixToLU(double matrix[3][3], double L[3][3], double U[3][3])
{
    int i = 0;
    int j = 0;
    double value = matrix[i][j];

    // Initialize L
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                L[i][j] = 1;
            else
                L[i][j] = 0;
        }
    }

    // Introduce 1 at matrix[0][0]
    for (int j = 0; j < 3; j++)
    {
        matrix[i][j] /= value;
    }

    // Add coefficient to L
    L[0][0] = value;

    i = 1;
    value = matrix[i][0];

    for (int j = 0; j < 3; j++)
    {
        matrix[i][j] -= matrix[0][j] * value;
    }

    L[i][0] = value;

    i = 2;
    value = matrix[i][0];

    for (int j = 0; j < 3; j++)
    {
        matrix[i][j] -= matrix[0][j] * value;
    }

    L[i][0] = value;

    i = 1;
    j = 1;

    // Intridouce one at matrix [1][1] if there isn't
    if (matrix[i][j] != 1)
    {
        value = matrix[i][j];
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] /= value;
        }
        L[i][j] = value;
    }

    // Add zero at matrix[2][1]
    i++;
    value = matrix[2][1];

    for (int j = 0; j < 3; j++)
    {
        matrix[i][j] -= value * matrix[1][j];
    }
    L[2][1] = value;

    // If the element at matrix[2][3] is not 1 matke it one
    value = matrix[2][2];
    if (value != 1 && value != 0)
    {
        matrix[2][2] /= value;
    }

    L[2][2] = value;

    printMatrix(3, 3, matrix);
    printMatrix(3, 3, L);
}
