#pragma once

float getRootByBisection(float a, float b, float (*f)(float value), int decimalAccuracy);
float getRootByRegulaFalsi(float a, float b, float (*f)(float value), int decimalAccuracy);
