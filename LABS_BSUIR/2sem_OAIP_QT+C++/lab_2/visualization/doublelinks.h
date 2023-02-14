#ifndef DOUBLELINKS_H
#define DOUBLELINKS_H

#include "../../libs/smart_ptr/smart_ptrs.h"
#include <QMainWindow>

struct node
{
    int date;
    weak_ptr<node> prev;
    shared_ptr<node> next;
};
class doublelinks
{
public:
    doublelinks();
    ~doublelinks();
public:
     int doublelink_insert (shared_ptr<doublelinks> ptr, int position, int member); // вставка
     int doublelink_erase (shared_ptr<doublelinks> ptr, int position); // Удалить
     int doublelink_getlength (shared_ptr<doublelinks> ptr); // Получить длину
     int getThisDate(shared_ptr<doublelinks> ptr);
     int* doublelink_display(shared_ptr<doublelinks> ptr, int num);
private:
    int length;
    node* root;

};

#endif // DOUBLELINKS_H
