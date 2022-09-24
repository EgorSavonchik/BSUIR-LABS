#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include "../../libs/crutch_list/crutch_list.h"

class product
{
public:
    product();
    product(list_array<QString> input);


    QString productname;
    QString brand;
    QString data;
    QString readiness;
    QString fullname;
};

#endif // PRODUCT_H
