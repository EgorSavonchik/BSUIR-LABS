#ifndef ROMBUS_H
#define ROMBUS_H

#include "figure.h"

class rombus : public figure
{
    int side = 100;
    int angle = 60;
    qreal dx, dy;
public:
    rombus();

    int area();
    int perimetr();

    int& speshialParametr1();
    int& speshialParametr2();

    int upperbound();
    int upperbound2();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ROMBUS_H
