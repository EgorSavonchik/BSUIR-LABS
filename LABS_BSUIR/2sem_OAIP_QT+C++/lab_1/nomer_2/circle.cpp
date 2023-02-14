#include "circle.h"

circle::circle()
{
    xr = yr;
}

int& circle::speshialParametr1()
{
    return xr;
}

void circle::Recalculation()
{
    yr = xr;
}
