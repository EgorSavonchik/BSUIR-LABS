#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <QTransform>

class rectangle : public figure
{
    int width = 200;
    int height = 100;
public:
    rectangle();
    int area();
    int perimetr();

    int& speshialParametr1();
    int& speshialParametr2();

    int upperbound();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECTANGLE_H
