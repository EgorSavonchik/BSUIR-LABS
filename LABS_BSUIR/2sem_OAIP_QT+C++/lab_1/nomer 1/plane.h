#ifndef PLANE_H
#define PLANE_H

#include "rect.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class plane : public rect
{
    int y = 100;

    bool chassisOn = false;
public:
    plane();

    void chassis_on();
    void chassis_off();



protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // PLANE_H
