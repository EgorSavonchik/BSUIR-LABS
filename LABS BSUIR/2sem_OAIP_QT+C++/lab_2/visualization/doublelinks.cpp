#include "doublelinks.h"

doublelinks::doublelinks()
{
    root = new node;
    root->prev;
    root->next;
    length = 0;
}

doublelinks::~doublelinks()
{
}
// Вставить
int doublelinks::doublelink_insert(shared_ptr<doublelinks> ptr, int position, int member)
{
    shared_ptr<node> nodeinsert = new node;
    nodeinsert->date = member;

    if (ptr->doublelink_getlength(ptr) == 0)
    {
        root->next = nodeinsert;
        nodeinsert->prev = nodeinsert;
        nodeinsert->next = nodeinsert;
        ptr->length++;
        return 0;
    }
    else
    {
        if (position == 0)
        {
            nodeinsert->prev = root->next->prev;
            nodeinsert->next = root->next;
            (root->next->prev.lock())->next = nodeinsert;
            root->next->prev = nodeinsert;
            root->next = nodeinsert;
            ptr->length++;
            return 0;
        }
        else
        {
            shared_ptr<node> current = root->next;
            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }

            nodeinsert->next = current;
            nodeinsert->prev = current->prev;
            (current->prev.lock())->next = nodeinsert;
            current->prev = nodeinsert;
            ptr->length++;
            return 0;
        }
    }
}
 //Удалить
int doublelinks::doublelink_erase(shared_ptr<doublelinks> ptr, int position)
{
    if (ptr->doublelink_getlength(ptr) == 0)
    {
        return 0;
    }
    else
    {
        if (ptr->doublelink_getlength(ptr) == 1)
        {
            ptr->root->next = NULL;
            ptr->length--;
        }
        else
        {
            shared_ptr<node> deletenode = root->next;
            for (int i = 0; i < position; i++)
            {
                deletenode = deletenode->next;
            }
            (deletenode->prev.lock())->next = deletenode->next;
            deletenode->next->prev = deletenode->prev;
            ptr->length--;
        }
    }
}

int doublelinks::doublelink_getlength(shared_ptr<doublelinks> ptr)
{
    return ptr->length;
}

int doublelinks::getThisDate(shared_ptr<doublelinks> ptr)
{
    return ptr->root->next->date;
}

int* doublelinks::doublelink_display(shared_ptr<doublelinks> ptr, int num)
{
    int* out = new int[length];

    shared_ptr<node> current = root->next;
    for (int i = 0; i < num; i++)
    {
        out[i] = current->date;
        current = current->next;
    }

    return out;
}
