#pragma once

double getRootByBisection(double (*f)(double value), unsigned short int accuracyAfterDecimalPoint);
double getRootByRegulaFalsi(double (*f)(double value), unsigned short int accuracyAfterDecimalPoint);
double approxResultByEuler(double x, double y, double lastValueOfX, double stepSize, double (*f)(double x, double y), unsigned short int accuracyAfterDecimalPoint);
double getRootBySecant(double (*f)(double x), unsigned short int accuracyFactor);
void getRootByGaussElimination(int rows, int columns, int matrix[rows][columns], int *roots);
