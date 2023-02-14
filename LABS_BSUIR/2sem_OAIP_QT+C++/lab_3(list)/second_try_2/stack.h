#ifndef STACK_H
#define STACK_H

#include <QString>

class Node {
public:
    QChar ch;
    Node* next;
};

class Stack {
private:

public:
    Node* pres;


    Stack() {
        pres = NULL;
    }
    ~Stack() {
        while (pres)
            pop();
    }
    bool st_empty()//Проверка на пустоту
    {
        return pres == NULL;
    }
    void push(QChar ch) //Добавление нового элемента
    {
        Node* next_ch = new Node;
        next_ch->ch = ch;
        next_ch->next =  pres;
        pres = next_ch;
    }
    QChar peek() //Считывание головного элемента
    {
        if (!st_empty())
            return pres->ch;
        return '\0';
    }
    void pop() //Удаление головного элемента
    {
        if (!st_empty()) {
            Node* past = pres->next;
            delete pres;
            pres = past;
        }
    }
};


#endif // STACK_H
