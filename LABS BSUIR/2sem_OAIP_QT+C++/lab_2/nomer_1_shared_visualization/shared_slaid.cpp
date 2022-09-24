#include "shared_slaid.h"

shared_slaid::shared_slaid()
{

}

QRectF shared_slaid::boundingRect() const
{
    return QRectF(0, 0, 600, 600);
}

void shared_slaid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(250, 275, 100, 50);
    painter->drawRect(50, 125, 100, 50);
    painter->drawRect(250, 125, 100, 50);
    painter->drawRect(450, 125, 100, 50);
}
