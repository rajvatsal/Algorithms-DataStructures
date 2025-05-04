#pragma once

float bisection(float a, float b, float (*f)(float value), int decimalAccuracy);
float regulaFalsi(float a, float b, float (*f)(float value), int decimalAccuracy);
