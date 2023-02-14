#include "ncorner.h"

ncorner::ncorner()
{

}

void ncorner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    r = side / (2 * sin(M_PI / n));

    int x1 = 0, y1 = 0;

    for(int i = 0; i < n; i++)
    {
        x1 = r * cos(angl * M_PI / 180);
        y1 = r * sin(angl * M_PI / 180);

        pol << QPointF(x1, y1);
        angl = angl + 360.0 / n;
    }

    painter->drawPolygon(pol);
}

void ncorner::setcorner(int corner, int angle)
{
    n = corner;
    angl = angle;
}

int ncorner::area()
{
    return pow(r, 2) * sin(2 * M_PI / n) / 2 * n;
}

int ncorner::perimetr()
{
    return sin(M_PI / n) * 2.0 * r * n;
}

int &ncorner::speshialParametr1()
{
    pol.clear();

    return side;
}

int &ncorner::speshialParametr2()//костыль, не используется, но надо переопределить тк виртуальная
{
    return side;
}



