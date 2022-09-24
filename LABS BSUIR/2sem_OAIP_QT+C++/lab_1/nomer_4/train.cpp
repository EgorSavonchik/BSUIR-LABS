#include "train.h"

train::train()
{

}

train::train(QString input)
{
    QString tmp;

    fullname = input;

    int i = 0;

    for(; i < input.length(); i++)
    {
        if(input[i] != ',')
        {
            data += input[i];
        }
        else
        {
            i++;
            break;
        }
    }

    for(; i < input.length(); i++)
    {

        if(input[i] != ',')
        {
            tmp = tmp + input[i];
        }
        else
        {
            number = tmp.toInt();
            i++;

            tmp = "";
            break;
        }
    }

    for(; i < input.length(); i++)
    {
        if(input[i] != ',')
        {
            destination += input[i];
        }
        else
        {
            i++;
            break;
        }
    }

    for(; i < input.length(); i++)
    {
        if(input[i] != ',')
        {
            time += input[i];
        }
        else
        {
            i++;
            break;
        }
    }

    for(; i < input.length(); i++)
    {
        if(input[i] != ',')
        {
            tmp += input[i];
        }
        else
        {
            compart = tmp.toInt();

            i++;

            tmp = "";
            break;
        }
    }

    for(; i < input.length(); i++)
    {
        if(input[i] != ',')
        {
            tmp += input[i];
        }
        else
        {
            reserved = tmp.toInt();

            i++;

            tmp = "";
            break;
        }
    }

    for(; i < input.length(); i++)
    {
        if(input[i] != ',')
        {
            tmp += input[i];
        }
        else
        {
            compartFree = tmp.toInt();

            i++;

            tmp = "";
            break;
        }
    }

    for(; i < input.length(); i++)
    {
        if(input[i] != '.')
        {
            tmp += input[i];
        }
        else
        {
            reservedFree = tmp.toInt();

            i++;

            tmp = "";
            break;
        }
    }


    days = data[0].digitValue() * 10 + data[1].digitValue();
    months =  data[3].digitValue() * 10 + data[4].digitValue();
}


