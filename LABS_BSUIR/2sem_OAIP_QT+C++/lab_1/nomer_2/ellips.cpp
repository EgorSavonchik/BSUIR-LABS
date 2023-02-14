#include "ellips.h"

ellips::ellips()
{

}

int ellips::area()
{
    return M_PI * xr * yr;
}

int ellips::perimetr()
{
    return 2 * M_PI * sqrt((pow(xr, 2) + pow(yr, 2))/ 2);
}

int &ellips::speshialParametr1()
{
    return xr;
}

int &ellips::speshialParametr2()
{
    return yr;
}

int ellips::upperbound()
{
    return 250;
}

void ellips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen(5);
    painter->setPen(pen);

    painter->drawEllipse(QPoint(0, 0), xr, yr);
}


