#include "nstar.h"

nstar::nstar()
{

}

int nstar::area()
{
    return n * r * R * sin(M_PI / n);
}

int nstar::perimetr()
{
    return 2 * n * sqrt(pow(R, 2) + pow(r, 2) - 2 * R * r * cos(M_PI / n));
}

int &nstar::speshialParametr1()
{
    pol.clear();

    return R;
}

int &nstar::speshialParametr2()
{
    pol.clear();

    return r;
}

int nstar::upperbound()
{
    return 250;
}

void nstar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    for (int i = 1; i <= n; i++)
    {
        pol << QPointF(sin((i * 2 - 1) * M_PI / n) * r, cos((i * 2 - 1) * M_PI / n) * r);
        pol << QPointF(sin(i * 2 * M_PI / n) * R + 1, cos(i * 2 * M_PI / n) * R - 1);
    }

    painter->drawPolygon(pol);

}

void nstar::setpoint(int numberofpoint)
{
    n = numberofpoint;
}
