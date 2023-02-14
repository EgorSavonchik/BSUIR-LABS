#ifndef RECT_H
#define RECT_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class rect : public QGraphicsItem
{

public:
    rect();
    ~rect();

    void moveByslot();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECT_H
