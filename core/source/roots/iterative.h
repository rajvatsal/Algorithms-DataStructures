#pragma once

typedef enum
{
    bisection,
    regula_falsi,
} rootMethod_t;

float getRoot(float (*f)(float), rootMethod_t, int decimal);
