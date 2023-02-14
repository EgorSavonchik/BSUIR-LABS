#ifndef CIRCLE_H
#define CIRCLE_H

#include "ellips.h"

class circle : public ellips
{
public:
    circle();

    int& speshialParametr1();

    void Recalculation();
};

#endif // CIRCLE_H
