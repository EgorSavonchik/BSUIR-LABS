#include "rect.h"
#include <QGraphicsItem>

rect::rect()
{

}

rect::~rect()
{

}

void rect::moveByslot()
{
    this->moveBy(3, 2);
}

QRectF rect::boundingRect() const
{
    return(QRectF(0, 0, 800, 600));
}

void rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBackgroundMode(Qt::BGMode::OpaqueMode);

    QBrush brush(Qt::white);

    painter->setBrush(brush);

    painter->drawRect(50, 50, 150, 50);
}
