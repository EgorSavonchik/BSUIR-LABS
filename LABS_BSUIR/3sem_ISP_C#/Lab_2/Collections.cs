//#include "Interfaces.cs"

using System.Collections;

namespace Lab2_153505_Savonchik
{
    class RemoveException : ArgumentException
    {
        public RemoveException(string message = "deleting a non - existent object") : base(message)
        {

        }
    }

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

        public bool IsExist(T item)
        {
            Node<T> temp = head;

            for (int i = 0; i < count; i++)
            {
                if (temp.data.Equals(item))
                {
                    return true;
                }

                temp = temp.next;
            }

            return false;
        }

        public T RemoveCurrent()
        {
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

            count--;
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node<T> temp = head;

            for (int i = 0; i < count; i++)
            {
                yield return temp.data;
                temp = temp.next;
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
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
            Node<T> temp = head;

            for (int i = 0; i < count; i++)
            {
                if (temp!.data!.Equals(item))
                {
                    break;
                }

                temp = temp.next;
            }

            try
            {
                if (temp == null)
                {
                    throw new RemoveException();
                }
            }
            catch (RemoveException)
            {
                Console.WriteLine("remove non-existing element");

                return;
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

            count--;
        }

        public T this[int index]
        {
            get
            {
                try
                {
                    if (index >= count)
                    {
                        throw new IndexOutOfRangeException();
                    }
                }
                catch (IndexOutOfRangeException)
                {
                    Console.WriteLine("Out of range");

                    return default;
                }


                Node<T> tmp = head;
                for (int i = 0; i < index; i++)
                {
                    tmp = tmp.next;
                }

                return tmp.data;
            }

            set
            {
                try
                {
                    if (index >= count)
                    {
                        throw new IndexOutOfRangeException();
                    }
                }
                catch (IndexOutOfRangeException)
                {
                    Console.WriteLine("Out of range");

                    return;
                }

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
