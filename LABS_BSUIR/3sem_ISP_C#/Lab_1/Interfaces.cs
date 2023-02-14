using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_153505_Savonchik
{
    internal interface ICustomCollection<T>
    {
        T this[int index] { get; set; }// – индексатор коллекции
        void Reset();// – метод, устанавливает курсор в начало коллекции
        void Next();// – метод, перемещает курсор на следующий элемент коллекции
        T Current(); // – метод, возвращает элемент текущего положения курсора
        int Count { get; }// – свойство, возвращает количество элементов в коллекции
        void Add(T item);// – метод, добавляет объект item в конец коллекции
        void Remove(T item);// – метод, удаляет объект item из коллекции
        T RemoveCurrent();// – метод, удаляет элемент текущего положения курсора
    }
}
