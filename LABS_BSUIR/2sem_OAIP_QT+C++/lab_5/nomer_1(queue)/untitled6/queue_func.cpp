#include "queue_func.h"


queue_func::queue_func()
{

}

queue<int> queue_func::func(queue<int> first, queue<int> second)
{
    queue<int> temp;

    int max = first[0], min = first[0], maxPos = 0, minPos = 0;

    for(int i = 0; i < first.size(); i++)
    {
        if(first[i] > max)
        {
            max = first[i];
            maxPos = i;
        }

        if(first[i] < min)
        {
            min = first[i];
            minPos = i;
        }
    }

    if(minPos < maxPos)
    {
        for(int i = first.size() - 1; i >= maxPos; i--)
        {
            temp.push_front(first[i]);
        }

        for(int i = second.size() - 1; i >= 0; i--)
        {
            temp.push_front(second[i]);
        }

        for(int i = minPos; i >= 0; i--)
        {
            temp.push_front(first[i]);
        }
    }
    else
    {
        for(int i = first.size() - 1; i >= minPos; i--)
        {
            temp.push_front(first[i]);
        }

        for(int i = second.size() - 1; i >= 0; i--)
        {
            temp.push_front(second[i]);
        }

        for(int i = maxPos; i >= 0; i--)
        {
            temp.push_front(first[i]);
        }
    }

    return temp;
}
