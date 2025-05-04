#pragma once

float getRootByBisection(float a, float b, float (*f)(float value), int accuracyAfterDecimalPoint);
float getRootByRegulaFalsi(float a, float b, float (*f)(float value), int accuracyAfterDecimalPoint);
float approxResultByEuler(float x, float y, float lastValueOfX, float stepSize, float (*f)(float x, float y), int accuracyAfterDecimalPoint);
float getRootBySecant(double (*f)(double x), unsigned short int accuracyFactor);
