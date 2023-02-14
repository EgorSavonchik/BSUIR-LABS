#ifndef STACK_H
#define STACK_H


template<class T>
class Node {
public:
    T obj;
    Node* next;
};

template<class T>
class Stack {
private:
    Node<T>* pres;
public:
    Stack();
    ~Stack();

    bool empty();

    void push(T ch);

    T& peek();

    void pop();
};

#endif // STACK_H
