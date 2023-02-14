#ifndef NSTAR_H
#define NSTAR_H

#include "figure.h"

class nstar : public figure
{
    int R = 100;
    int r = 30;
    int n = 5;
    QPolygonF pol;

public:
    nstar();

    int area();
    int perimetr();

    int& speshialParametr1();
    int& speshialParametr2();

    int upperbound();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setpoint(int numberofpoint);
};

#endif // NSTAR_H
