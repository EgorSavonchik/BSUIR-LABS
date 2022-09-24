#include "figure.h"

figure::figure()
{

}

QString figure::getcenter()
{
    QString str = QString::number(x - 250) + ',' + QString::number(-y + 250);
    return str;
}

void figure::rotateLeft()
{
    angular -= 3;

    this->setRotation(angular);
}

void figure::rotateRigth()
{
    angular += 3;

    this->setRotation(angular);
}

void figure::moveUp()
{
    this->moveBy(0, -2);

    y -= 2;
}

void figure::moveLeft()
{
    this->moveBy(-2, 0);

    x -= 2;
}

void figure::moveRigth()
{
    this->moveBy(2, 0);

    x += 2;
}

void figure::moveDown()
{
    this->moveBy(0, 2);

    y += 2;
}


void figure::scalePlus()
{

    scale += 0.2;

    this->setScale(scale);
}

void figure::scaleMinus()
{

    if(scale > 0.4)
    {
        scale -= 0.2;
    }

    this->setScale(scale);
}

/*int figure::upperbound()
{
    return x;
}*/

int figure::upperbound2()
{
    return upperbound();
}

void figure::Recalculation()
{

}

QRectF figure::boundingRect() const
{
    return(QRectF(-250 , -250 , 500, 500));
}




