#pragma once

#include "../smart_ptr/smart_ptrs.h"

template<class T>
struct node
{
	shared_ptr<node<T>> next;
	weak_ptr<node<T>> prev;
	T object;
};

template<class T>
class list
{
public:
	shared_ptr<node<T>> first, last;
	int size = 0;

	list()
	{

	}

	node<T>& findElement(int pos) const
	{
		shared_ptr<node<T>> current;


		if (pos <= size / 2)
		{
			current = first;
			for (int k = 1; k <= pos; k++)
				current = current->next;
		}
		else
		{
			current = last;
			for (int k = size - 2; k >= pos; k--)
				current = current->prev;
		}

		return *current;
	}


	list<T>& add(T item, int pos)//добавляет элемент на позицию
	{

		shared_ptr<node<T>> temp = new node<T>;

		temp->object = item;

		if (size == 0)
		{
			first = last = temp;
		}

		if (pos == 0)
		{
			temp->prev.reset();
			temp->next = first;

			first->prev = temp;
			first = temp;
		}
		else if (pos == size)
		{
			temp->prev = last;
			temp->next.reset();

			last->next = temp;
			last = temp;
		}
		else
		{
			shared_ptr<node<T>> current = &findElement(pos - 1);

			temp->prev = current;
			temp->next = current->next;

			current->next = temp;
			(temp->next)->prev = temp;
		}

		size++;

		return *this;
	}

	list<T>& push_back(T item)
	{
		this->add(item, size);

		return *this;
	}

	T& operator[](int i)
	{
		return findElement(i).object;
	}

	list<T>& deleteNode(int pos)
	{

        if(size == 1)
        {
            first = last = nullptr;
        }
        else if (pos == 0)
		{
			shared_ptr<node<T>> tmp = first->next;

			tmp->prev.reset();

			first->next.reset();
			first->prev.reset();

			first = tmp;
		}
		else if (pos == size - 1)
		{
			last = last->prev.lock();

			(last->next)->next.reset();
			(last->next)->prev.reset();

			last->next.reset();
		}
		else
		{
			weak_ptr<node<T>> pre = (&findElement(pos))->prev;
			shared_ptr<node<T>> temp = pre.lock()->next, post = temp->next;


			post->prev = pre;
			pre.lock()->next = post;

			temp->next.reset();
			temp->prev.reset();
		}

		size--;

		return *this;
	}

	bool isNull()
	{
		return size == 0;
	}

	class iterator
	{
		shared_ptr<node<T>> currect;
		int pos = 0;
	public:
		iterator(shared_ptr<node<T>> input, int p) : currect(input), pos(p) {}

		iterator operator++()
		{
			currect = currect->next;
			pos++;

			return *this;
		}

		iterator operator++(int)
		{
            iterator tmp = *this;
			
			currect = currect->next;
			pos++;

			return tmp;
		}

		iterator operator--()
		{
			currect = currect->prev;
			pos--;

			return *this;
		}

		T& operator*()
		{
			return currect->object;
		}

		int getPos()
		{
			return pos;
		}
	};

	iterator begin()
	{
		return iterator(first, 0);
	}

	iterator end()
	{
		return iterator(last, size - 1);
	}
};

template<class T>
class list_array
{
	
	int next[50];
	T item[50];

	T& fin_element(int pos)
	{
		int current = next[0];

		for (int i = 0; i < pos; i++)
		{
			current = next[current];
		}

		return item[current - 1];
	}

public:
	int count = 0;


	list_array() {}
	~list_array() {}

	list_array<T>& add(T input)
	{
		next[count] = count + 1;
		count++;
		item[count - 1] = input;


		return *this;
	}

	list_array<T>& del(int pos)
	{		
		int current = next[0];

		for (int i = 0; i < pos; i++)
		{
			current = next[current];
		}

		next[current - 1]++;

		count--;

		return *this;
	}

	T& operator[](int i)
	{
		return fin_element(i);
	}

	bool isNull()
	{
		return count == 0;
	}
};

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
