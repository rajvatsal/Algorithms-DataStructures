#include <math.h>

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

float getRoot(float a, float b, float (*f)(float))
{
    float c = (a + b) / 2;
    float fc = f(c);

    float x;
    float y;

    if ((floorf(fc * 1000) / 1000) == 0)
    {
        return c;
    }
    else if (fc < 0)
    {
        return getRoot(c, b, f);
    }
    else
    {
        return getRoot(a, c, f);
    }
}

float bisectRoot(float (*f)(float))
{
    float points[2];
    initCoordinates(points, f);
    return getRoot(points[0], points[1], f);
}
