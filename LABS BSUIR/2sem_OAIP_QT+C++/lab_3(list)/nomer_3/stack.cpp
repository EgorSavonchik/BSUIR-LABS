#include "stack.h"



template<class T>
Stack<T>::Stack() {
    pres = nullptr;
}

template<class T>
Stack<T>::~Stack() {
    while (pres)
        pop();
}

template<class T>
bool Stack<T>::empty()//Проверка на пустоту
{
    return pres == nullptr;
}

template<class T>
void Stack<T>::push(T ch) //Добавление нового элемента
{
    Node<T>* next_ch = new Node<T>;
    next_ch->obj = ch;
    next_ch->next =  pres;
    pres = next_ch;
}

template<class T>
T &Stack<T>::peek() //Считывание головного элемента
{
    return pres->obj;
}

template<class T>
void Stack<T>::pop() //Удаление головного элемента
{
    if (!empty()) {
        Node<T>* past = pres->next;
        delete pres;
        pres = past;
    }
}
