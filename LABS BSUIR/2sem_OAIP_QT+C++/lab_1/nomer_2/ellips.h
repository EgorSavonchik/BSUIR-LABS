#ifndef ELLIPS_H
#define ELLIPS_H

#include "figure.h"

class ellips : public figure
{

public:
    ellips();

    int area();
    int perimetr();

    int& speshialParametr1();
    int& speshialParametr2();

    int upperbound();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int xr = 100;
    int yr = 50;
};

#endif // ELLIPS_H
