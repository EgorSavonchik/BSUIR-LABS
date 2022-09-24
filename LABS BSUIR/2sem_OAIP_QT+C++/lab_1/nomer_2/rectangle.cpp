#include "rectangle.h"

rectangle::rectangle()
{

}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen(5);
    painter->setPen(pen);



    painter->drawRect(0 - width / 2, 0 - height / 2, width, height);
}



int rectangle::perimetr()
{
    return 2 * (width + height);
}

int& rectangle::speshialParametr1()
{
    return width;
}

int &rectangle::speshialParametr2()
{
    return height;
}

int rectangle::upperbound()
{
    return 500;
}

int rectangle::area()
{
    return width * height;
}
