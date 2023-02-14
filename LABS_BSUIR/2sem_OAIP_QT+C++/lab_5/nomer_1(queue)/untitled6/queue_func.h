#ifndef QUEUE_FUNC_H
#define QUEUE_FUNC_H

#include "../../../../../git/queue/Header.h"

class queue_func : public queue<int>
{
public:
    queue_func();

    queue<int> func(queue<int> first, queue<int> second);
};

#endif // QUEUE_FUNC_H
