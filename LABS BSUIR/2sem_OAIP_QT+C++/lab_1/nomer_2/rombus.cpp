#include "rombus.h"

rombus::rombus()
{

}

int rombus::area()
{
    return sin(angle * M_PI / 180) * pow(side, 2);
}

int rombus::perimetr()
{
    return 4 * side;
}

int &rombus::speshialParametr1()
{
    return side;
}

int &rombus::speshialParametr2()
{
    return angle;
}

int rombus::upperbound()
{
    return 250;  //250 / cos(angle * M_PI / 360) < 250 / sin(angle * M_PI / 360) ? 250 / cos(angle * M_PI / 360) : 250 / sin(angle * M_PI / 360);
}

int rombus::upperbound2()
{
    return 180;  //360 * acos(side / 250) / M_PI < 360 * asin(side / 250) / M_PI ? 360 * acos(side / 250) / M_PI : 360 * asin(side / 250) / M_PI;
}

void rombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    dx = cos(angle / 360.0 * M_PI) * side * 2;
    dy = sin(angle / 360.0 * M_PI) * side * 2;

    QPolygonF pol;
    pol << QPointF(-dx / 2, 0) << QPointF(0, dy / 2) << QPointF(dx / 2, 0) << QPointF(0, -dy / 2);

    painter->drawPolygon(pol);
}

