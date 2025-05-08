#pragma once

double getRootByBisection(double (*f)(double value), unsigned short int accuracyAfterDecimalPoint);
double getRootByRegulaFalsi(double (*f)(double value), unsigned short int accuracyAfterDecimalPoint);
double approxResultByEuler(double x, double y, double lastValueOfX, double stepSize, double (*f)(double x, double y), unsigned short int accuracyAfterDecimalPoint);
double getRootBySecant(double (*f)(double x), unsigned short int accuracyFactor);
void getValuesByGaussElimination(int rows, int columns, int matrix[rows][columns], int *roots);
void getValuesByGaussSiedel(double fx(double y, double z), double fy(double x, double z), double fz(double x, double y), double values[3], unsigned short int accuracyFactor);
void getValuesByGaussJacobi(double fx(double y, double z), double fy(double x, double z), double fz(double x, double y), double values[3], unsigned short int accuracyFactor);
double getRootByNewtonRaphson(double (*f)(double x), unsigned short int accuracyFactor);
