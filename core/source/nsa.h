#pragma once

double getRootByBisection(double (*f)(double value), int accuracyAfterDecimalPoint);
double getRootByRegulaFalsi(double (*f)(double value), int accuracyAfterDecimalPoint);
float approxResultByEuler(float x, float y, float lastValueOfX, float stepSize, float (*f)(float x, float y), int accuracyAfterDecimalPoint);
double getRootBySecant(double (*f)(double x), unsigned short int accuracyFactor);
