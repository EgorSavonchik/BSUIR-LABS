#ifndef SPORTSMAN_H
#define SPORTSMAN_H

#include <QString>
#include "../../libs/crutch_list/crutch_list.h"

class sportsman
{

public:
    sportsman();

    sportsman(list<QString>);

    QString country;
    QString team;
    QString fullname;
    QString surname;
    int number;
    int age;
    int heigth;
    int weigth;
    QString outname;
};

#endif // SPORTSMAN_H
