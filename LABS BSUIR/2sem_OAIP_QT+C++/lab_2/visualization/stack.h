#ifndef STACK_H
#define STACK_H
#include "../../libs/smart_ptr/smart_ptrs.h"


template <typename T>
class STACK
{
private:
  unique_ptr<T[]> stack;
  int count = 0;

public:

  STACK()
  {

  }

  void push(T item)
  {
    unique_ptr<T[]> tmp(new T[count]);

    for(int i = 0; i < count; i++)
        tmp[i] = stack[i];


    stack.reset(new T[count + 1]);

    count++;

    for (int i = 0; i < count - 1; i++)
        stack[i] = tmp[i];

    stack[count - 1] = item;
  }

  T pop()
  {
    if (count == 0)
      return 0; // стек пуст
    count--;
    return stack[count];
  }


  T Head()
  {
    if (count == 0)
      return 0;
    return stack[count - 1];
  }

  ~STACK()
  {

  }

  int Count()
  {
    return count;
  }

  bool IsEmpty()
  {
    return count == 0;
  }
};


#endif // STACK_H
