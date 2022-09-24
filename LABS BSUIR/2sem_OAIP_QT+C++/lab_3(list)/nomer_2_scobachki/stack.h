#ifndef STACK_H
#define STACK_H

#include <QString>

class List {
protected:
    QChar ch;
    List* next;
public:
    void set(QChar c, List* n_c) {
        ch = c;
        next = n_c;
    }
    QChar info_ch() {
        return ch;
    }
    List* info_next() {
        return next;
    }
};


class Stack {
private:

public:
    List* pres;


    Stack() {
        pres = nullptr;
    }
    ~Stack() {
        while (pres)
            pop();
    }
    bool st_empty()//Проверка на пустоту
    {
        return pres == nullptr;
    }
    void push(QChar ch) //Добавление нового элемента
    {
        List* next_ch = new List;
        next_ch->set(ch, pres);
        pres = next_ch;
    }
    QChar peek() //Считывание головного элемента
    {
        if (!st_empty())
            return pres->info_ch();
        return '\0';
    }
    void pop() //Удаление головного элемента
    {
        if (!st_empty()) {
            List* past = pres->info_next();
            delete pres;
            pres = past;
        }
    }
};

#endif // STACK_H
