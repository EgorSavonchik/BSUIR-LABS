//#include "Interfaces.cs"

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_153505_Savonchik
{
    internal class CustomCollection<T> : ICustomCollection<T>
    {
        Node<T> head = null;
        Node<T> tail = null;
        Node<T> current = null;
        int count = 0;
        public void Add(T item)
        {
            if (head == null)
            {
                head = new Node<T>(item);

                tail = head;
                current = head;
                count++;
            }
            else
            {
                tail.next = new Node<T>(item);

                Node<T> temp = tail;
                tail = tail.next;

                tail.prev = temp;
                count++;
            }
        }

        public T RemoveCurrent()
        {
            count--;

            if (current == head)
            {
                T tmp = current.data;

                head = current.next;
                current = head;

                return tmp;
            }
            else if (current == tail)
            {
                T tmp = current.data;

                tail = current.prev;
                current = tail;

                return tmp;
            }
            else
            {
                current.prev.next = current.next;
                current.next.prev = current.prev;

                current = current.next;

                return current.data;
            }

        }

        public int Count
        {
            get { return count; }
        }

        public void Reset()
        {
            current = head;
        }

        public void Next()
        {
            current = current.next;
        }

        public T Current()
        {
            return current.data;
        }

        public void Remove(T item)
        {
            count--;
            Node<T> temp = head;

            for(int i = 0; i < count; i++)
            {
                if(temp.data.Equals(item))
                {
                    break;
                }

                temp = temp.next;
            }

            if (temp == head)
            {
                head = temp.next;
            }
            else if (temp == tail)
            {
                tail = temp.prev;
            }
            else
            {
                temp.prev.next = temp.next;
                temp.next.prev = temp.prev;
            }
        }

        public T this[int index]
        {
            get 
            {
                Node<T> tmp = head;
                for(int i = 0; i < index; i++)
                {
                    tmp = tmp.next;
                }

                return tmp.data;
            }

            set
            {
                Node<T> tmp = head;
                for (int i = 0; i < index; i++)
                {
                    tmp = tmp.next;
                }

                tmp.data = value;
            }
        }

    }

    class Node<T>
    {
        public Node(T item)
        {
            data = item;
        }

        public Node<T> next = null;
        public Node<T> prev = null;
        public T data;
    }
}
