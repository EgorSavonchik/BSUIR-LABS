#ifndef SHARED_SLAID_H
#define SHARED_SLAID_H

#include <QGraphicsItem>
#include <QPainter>

class shared_slaid : public QGraphicsItem
{
public:
    shared_slaid();
    
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // SHARED_SLAID_H
