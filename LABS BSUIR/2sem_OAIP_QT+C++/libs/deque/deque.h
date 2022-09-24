#pragma once

#include "../smart_ptr/smart_ptrs.h"

template<class T>
class queue
{
    struct node
    {
        T obj;
        shared_ptr<node> next;
    };

    int sz = 0;
    shared_ptr<node> head;

public:

    queue()
    {

    }

    ~queue()
    {
        while (sz != 0)
        {
            this->pop_front();
        }
    }

    void push_front(T object)
    {
        shared_ptr<node> temp = new node;

        if (sz != 0)
        {
            temp->next = head;
        }

        temp->obj = object;

        sz++;
        head = temp;
    }

    void pop_front()
    {
        sz--;

        if (sz != 0)
        {
            shared_ptr<node> tmp = head->next;

            head = tmp;
        }
        else
        {
            head = nullptr;
        }
    }

    T& operator[] (int pos)
    {
        shared_ptr <node> tmp = head;

        for (int i = 0; i < pos; i++)
        {
            tmp = tmp->next;
        }

        return tmp->obj;
    }

    T& back()
    {
        return (*this)[sz - 1];
    }

    T& front()
    {
        return head->obj;
    }

    int size()
    {
        return sz;
    }

    void clear()
    {
        this->~queue();
    }
};

template<class T>
class deque//k = 10 потому что я так хочу
{
public:

    struct iterator
    {
        deque<T>* currentDeque;
        T* currentElem;
        int currentPos;
        int numberArray;

        iterator() {}

        iterator(deque<T>* deq, T* elem, int pos, int numArr)
        {
            currentDeque = deq;
            currentElem = elem;
            numberArray = numArr;
        }

        void operator++ (int)
        {
            bool exist = false;

            T* temp = currentDeque->begin;
            numberArray = 0;

            for (int i = 0; i < currentDeque->sz; i++)//костыль убогий
            {
                if (temp == currentElem)
                {
                    exist = true;
                    break;
                }

                if (temp == &currentDeque->arr[numberArray][9])
                {
                    numberArray++;

                    temp = &currentDeque->arr[numberArray][0];
                }
                else
                {
                    temp++;
                }
            }

            if (!exist)
            {
                currentElem = currentDeque->begin;
                numberArray = 0;

                return;
            }

            if (currentElem == &(*currentDeque)[currentDeque->sz - 1])
            {
                currentElem = currentDeque->begin;
                numberArray = 0;

                return;
            }

            if (currentElem == &(currentDeque->arr[numberArray][9]))
            {
                numberArray++;

                currentElem = &(currentDeque->arr[numberArray][0]);
            }
            else
            {
                currentElem++;
            }
        }

        void operator-- (int)
        {
            bool exist = false;
            T* temp = currentDeque->begin;
            numberArray = 0;

            for (int i = 0; i < currentDeque->sz; i++)//два костыля в одном кайф
            {
                if (temp == currentElem)
                {
                    exist = true;
                    break;
                }

                if (temp == &currentDeque->arr[numberArray][9])
                {
                    numberArray++;

                    temp = &currentDeque->arr[numberArray][0];
                }
                else
                {
                    temp++;
                }
            }

            if (!exist)
            {
                currentElem = currentDeque->begin;
                numberArray = 0;

                return;
            }

            if (currentElem == currentDeque->begin)
            {
                numberArray = currentDeque->cap / 10 - 1;
                currentElem = &((*currentDeque)[currentDeque->sz - 1]);

                return;
            }

            if (currentElem == &(currentDeque->arr[numberArray][0]))
            {
                numberArray--;

                currentElem = &(currentDeque->arr[numberArray][9]);
            }
            else
            {
                currentElem--;
            }
        }

        T& operator* ()
        {
            return *currentElem;
        }
    };

    deque()
    {
        arr = new T * [1];
        arr[0] = new T[10];

        begin = &arr[0][1];
        end = &arr[0][2];

        cap = 10;
    }

    ~deque()
    {
        for (int i = 0; i < sz; i++)
        {
            this->pop_back();
        }
    }

    void push_front(T input)
    {
        if (begin == &arr[0][0])
        {
            cap += 10;
            T** newArr = new T * [cap / 10];

            for (int i = 1; i < cap / 10; i++)
            {
                newArr[i] = std::move(arr[i - 1]);

                /*newArr[i] = new T[10];

                for (int j = 0; j < 10; j++)
                {
                    newArr[i][j] = arr[i][j];
                }*/
            }

            newArr[0] = new T[10];
            newArr[0][9] = input;
            begin = &newArr[0][9];

            sz++;

            arr = newArr;
            /*std::cout << "\n";
            for (int i = 0; i < cap; i++)
            {
                std::cout << arr[i / 10][i % 10] << "\n";
            }*/
        }
        else
        {
            begin--;
            *begin = input;
            sz++;
        }
    }

    void push_back(T input)
    {
        if (end == &arr[cap / 10 - 1][9])
        {
            //*end = input;
            cap += 10;
            T** newArr = new T * [cap / 10];

            for (int i = 0; i < cap / 10 - 1; i++)
            {
                newArr[i] = std::move(arr[i]);
            }

            newArr[cap / 10 - 1] = new T[10];
            newArr[cap / 10 - 2][8] = input;
            end = &newArr[cap / 10 - 1][0];

            sz++;

            arr = newArr;
            /*std::cout << "\n";
            for (int i = 0; i < cap; i++)
            {
                std::cout << arr[i / 10][i % 10] << "\n";
            }*/
        }
        else if (end == &arr[cap / 10 - 1][0])
        {
            arr[cap / 10 - 2][9] = input;
            end++;
            sz++;
        }
        else
        {
            *(end - 1) = input;
            end++;
            sz++;
        }
    }

    void pop_front()
    {
        if (begin == &arr[0][9])
        {
            begin->~T();
            begin = &arr[1][0];

            cap -= 10;

            T** newArr = new T * [cap / 10];

            for (int i = 0; i < cap / 10; i++)
            {
                newArr[i] = std::move(arr[i + 1]);
            }

            delete[] arr[0];
            arr = newArr;
            sz--;
        }
        else
        {
            begin->~T();

            begin++;
            sz--;
        }
    }

    iterator begin_it()
    {
        return iterator(this, begin, 0, 0);
    }

    void pop_back()
    {
        if (end == &arr[cap / 10 - 1][0])
        {
            cap -= 10;

            T** newArr = new T * [cap / 10];

            for (int i = 0; i < cap / 10; i++)
            {
                newArr[i] = std::move(arr[i]);
            }

            end = &arr[cap / 10 - 1][9];
            end->~T();

            delete[] arr[cap / 10];
            arr = newArr;
            sz--;
        }
        else
        {
            end--;
            end->~T();

            sz--;
        }
    }

    T& operator[] (int pos)
    {
        T* temp;

        if (pos < sz / 2)
        {
            temp = begin;

            for (int i = 0, j = 0; i < pos; i++)
            {
                if (temp == &arr[j][9])
                {
                    j++;
                    temp = &arr[j][0];
                }
                else
                {
                    temp++;
                }
            }
        }
        else
        {
            temp = end;

            for (int i = 0, j = cap / 10 - 1; i < sz - pos + 1; i++)
            {
                if (temp == &arr[j][0])
                {
                    j--;
                    temp = &arr[j][9];
                }
                else
                {
                    temp--;
                }
            }
        }

        return *temp;
    }

    int size()
    {
        return sz;
    }

    bool isEmpty()
    {
        return sz == 0;
    }

    void clear()
    {
        this->~deque();

        *this = deque();
    }

private:

    int sz = 0;
    int cap = 0;
    T** arr;

    T* begin;
    T* end;
};





#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
