#include "sportsman.h"

sportsman::sportsman()
{

}

sportsman::sportsman(list<QString> input)
{
    list<QString>::iterator it = input.begin();

    country = *(it++);
    team = *(it++);
    fullname = *(it++) + " ";
    surname =  *(it++);
    fullname += surname + " " + *(it++);
    number = (*(it++)).toInt();
    age = (*(it++)).toInt();
    heigth = (*(it++)).toInt();
    weigth = (*(it++)).toInt();

    it = input.begin();
    for(int i = 0; i  < input.size; i++, it++)
    {
        if(it.getPos() == input.size - 1)
        {
            outname += *(it);

            break;
        }

        outname += *(it) + ' ';
    }
}
