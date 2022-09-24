#ifndef HASH_TRASH_H
#define HASH_TRASH_H

#include <stack>
#include <cmath>
#include <QTableWidget>
#include <QStringList>
#include <QLabel>

class hash_trash
{


public:

    std::stack<std::pair<int, int>> data[50];

    hash_trash();

    int hashing(int key)
    {
        return abs(key) % 50;
    }

    void add(int key, int value)
    {
        data[hashing(key)].push(std::pair(key, value));
    }

    void print(QTableWidget* table)
    {
        for(int i = 0; i < 50; i++)
        {
            QString keys = "", values = "";
            std::stack<std::pair<int, int>> temp = data[i];

            for(int j = 0; j < (int)data[i].size(); j++)
            {
                keys += QString::number(temp.top().first) + " ";
                values += QString::number(temp.top().second) + " ";

                temp.pop();
            }

            table->setItem(i, 0, new QTableWidgetItem(keys));
            table->setItem(i, 1, new QTableWidgetItem(values));
        }
    }

    void search(int key, QLabel* label)
    {
        int hashKey = hashing(key);

        std::stack<std::pair<int, int>> temp = data[hashKey];

        for(int i = 0; i < (int)data[hashKey].size(); i++)
        {
            if(key == temp.top().first)
            {
                label->setText(QString::number(temp.top().second));

                return;
            }

            temp.pop();
        }

        label->setText("not found");
    }

    void delet(int key)
    {
        int hashKey = hashing(key);

        std::stack<std::pair<int, int>> temp = data[hashKey];

        for(int i = 0; i < (int)data[hashKey].size(); i++)
        {
            if(key == temp.top().first)
            {
                std::stack<std::pair<int, int>> newElem;
                std::stack<std::pair<int, int>> temp1 = data[hashKey];

                for(int j = 0; j < (int)data[hashKey].size(); j++)
                {
                    if(j != i)
                    {
                        newElem.push(temp1.top());

                        temp1.pop();
                    }
                }

                data[hashKey] = newElem;

                return;
            }

            temp.pop();
        }
    }
};

class hash_func : public hash_trash
{
public:

    void plusMinus(QTableWidget* main, QTableWidget* plus, QTableWidget* minus)
    {
        hash_trash min, pl;

        for(int i = 0; i < 50; i++)
        {
            int random = rand() % 100 - 50;

            this->add(random, random);
        }

        this->print(main);

        for(int i = 0; i < 50; i++)
        {
            std::stack<std::pair<int, int>> temp = data[i];

            for(int j = 0; j < (int)data[i].size(); j++)
            {
                if(temp.top().first > 0)
                {
                    pl.add(temp.top().first, temp.top().second);
                }
                else
                {
                    min.add(temp.top().first, temp.top().second);
                }

                temp.pop();
            }
        }

        min.print(minus);
        pl.print(plus);
    }
};

#endif // HASH_TRASH_H
