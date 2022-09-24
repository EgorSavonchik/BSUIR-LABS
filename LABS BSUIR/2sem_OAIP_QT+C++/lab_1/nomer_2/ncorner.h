#ifndef NCORNER_H
#define NCORNER_H

#include "figure.h"
#include <cmath>

class ncorner : public figure
{

    int n = 3;
    int angl = 270;
    int side = 100; // по умолчанию треугольник со стороной 50
    qreal r;

    QPolygonF pol;


public:
    ncorner();

    int area();
    int perimetr();

    int& speshialParametr1();
    int& speshialParametr2();// не нужна, пустая чтобы не было ошибки абстрактоного класса

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setcorner(int n, int angl);//3 - 270, 4 - 45, 6 - 270
};

#endif // NCORNER_H
