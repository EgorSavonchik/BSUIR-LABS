#ifndef OPZ_H
#define OPZ_H

#include <QString>
#include "stack.h"
#include "stack.cpp"
class opz
{
    QString expr;
    double a, b, c, d, e;
public:
    opz();

    opz(const QString input, double x1, double x2, double x3, double x4, double x5);

    int prior(QChar op);

    bool is_op(QChar c);

    bool is_alpha(QChar c);

    QString OPN();

    double Calc();
};

#endif // OPZ_H
