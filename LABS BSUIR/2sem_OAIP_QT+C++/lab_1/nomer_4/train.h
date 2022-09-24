#ifndef TRAIN_H
#define TRAIN_H

#include <QString>

class train
{
public:
    QString data;
    int number;
    QString destination;
    QString time;
    int compart;
    int reserved;
    int compartFree;
    int reservedFree;//дата отправления, номер
    //рейса, конечный пункт назначения, время отправления, число купейных и
    //плацкартных мест, число свободных купейных и плацкартных мест

    int days = 0;
    int months = 0;

    train();
    QString fullname;
    train(QString input);

    void pushBack(train tr);
};

#endif // TRAIN_H
