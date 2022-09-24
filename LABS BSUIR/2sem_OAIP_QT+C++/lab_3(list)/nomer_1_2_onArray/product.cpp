#include "product.h"

product::product()
{

}

product::product(list_array<QString> input)
{
    productname = input[0];
    brand = input[1];
    data = input[2];
    readiness = input[3];

    for(int i = 0; i < 4; i++)
    {
        if(i == 3)
        {
            fullname += input[i];

            break;
        }

        fullname += input[i] + ' ';
    }
}
