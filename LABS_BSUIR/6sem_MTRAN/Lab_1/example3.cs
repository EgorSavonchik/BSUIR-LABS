using System;

class QuickSort
{
    // Метод для обмена значений элементов массива
    static void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // Метод для разделения массива на две части по опорному элементу
    static int Partition(int[] array, int low, int high)
    {
        int pivot = array[high]; // Опорный элемент
        int i = low - 1; // Индекс меньшего элемента

        for (int j = low; j < high; j++)
        {
            // Если текущий элемент меньше или равен опорному
            if (array[j] <= pivot)
            {
                i++;
                Swap(ref array[i], ref array[j]);
            }
        }

        // Помещаем опорный элемент в правильную позицию
        Swap(ref array[i + 1], ref array[high]);

        return i + 1;
    }

    // Метод для рекурсивной сортировки массива
    static void Sort(int[] array, int low, int high)
    {
        if (low < high)
        {
            int pi = Partition(array, low, high);

            // Рекурсивно сортируем элементы до и после разделителя
            Sort(array, low, pi - 1);
            Sort(array, pi + 1, high);
        }
    }

    // Метод для вызова быстрой сортировки
    public static void QuickSortFunc(int[] array)
    {
        Sort(array, 0, array.Length - 1);
    }
}

class Program
{
    static void Main()
    {
        int[] array = { 12, 7, 9, 4, 3, 2, 8, 6, 5, 10, 1, 11 };

        Console.WriteLine("Исходный массив:");
        PrintArray(array);

        QuickSort.QuickSortFunc(array);

        Console.WriteLine("\nОтсортированный массив:");
        PrintArray(array);

        Console.ReadLine();
    }

    static void PrintArray(int[] array)
    {
        foreach (int item in array)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();
    }
}