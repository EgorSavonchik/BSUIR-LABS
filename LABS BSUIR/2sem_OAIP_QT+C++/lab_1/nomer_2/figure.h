#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QPainter>

class figure : public QGraphicsItem
{

public:
    figure();
    virtual int area() = 0;
    virtual int perimetr() = 0;
    QString getcenter();

    void rotateLeft();
    void rotateRigth();

    void moveUp();
    void moveLeft();
    void moveRigth();
    void moveDown();

    void scalePlus();
    void scaleMinus();

    virtual int& speshialParametr1() = 0;
    virtual int& speshialParametr2() = 0;

    virtual int upperbound() = 0;
    virtual int upperbound2();

    virtual void Recalculation();//костыль для круга

    int y = 250;
    int x = 250;
protected:
    qreal scale = 1;
    int angular = 0;


    QRectF boundingRect() const;
};

#endif // FIGURE_H
