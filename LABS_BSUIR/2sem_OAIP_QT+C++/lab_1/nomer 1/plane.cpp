#include "plane.h"

plane::plane()
{

}

void plane::chassis_on()
{
    chassisOn = true;

    if(y != 130)
    {
        y++;
    }
}

void plane::chassis_off()
{
    chassisOn = false;

    y = 100;
}



void plane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(chassisOn)
    {
        painter->drawLine(110, y - 30, 110, y - 20);
        painter->drawLine(175, y - 30, 175, y - 20);

        painter->drawEllipse(100, y - 20, 20, 20);
        painter->drawEllipse(165, y - 20, 20, 20);
    }


    this->rect::paint(painter, option, widget);

    QPolygon wing;
    wing << QPoint(160, 50) << QPoint(150, 0) << QPoint(100, 0) << QPoint(110, 50);

    painter->drawLine(170, 50, 200, 75);
    painter->drawLine(0, 40, 50, 100);
    painter->drawLine(0, 40, 50, 50);
    painter->drawPolygon(wing);
}

