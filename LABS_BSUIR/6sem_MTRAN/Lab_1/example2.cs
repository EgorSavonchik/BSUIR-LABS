class Program
{
    static void Main()
    {
        // Объявление переменных
        int a = 5;
        int b = 3;
        string input;

        // Вывод текста на консоль
        Console.WriteLine("Пример на C#.");

        // Чтение строки с консоли
        Console.Write("Введите что-нибудь: ");
        input = Console.ReadLine();

        // Операции с переменными
        int sum = a + b;
        int operations = (a * b) / a + a % b - b;

        Console.WriteLine($"Ваш ввод, {input}!");
        Console.WriteLine($"Сумма чисел {a} и {b} равна {sum}.");
        Console.WriteLine(operations);

        // Пример использования цикла for
        Console.WriteLine("Вывод чисел от 1 до 10 (цикл for):");
        for (int i = 1; i <= 10; i++)
        {
            Console.WriteLine(i);
        }

        // Пример использования цикла while
        int counter = 1;
        Console.WriteLine("Вывод чисел от 1 до 10 (цикл while):");
        while (counter <= 10)
        {
            Console.WriteLine(counter);
            counter++;
        }

        // Пример использования цикла do-while
        counter = 1;
        Console.WriteLine("Вывод чисел от 1 до 10 (цикл do-while):");
        do
        {
            Console.WriteLine(counter);
            counter++;
        }
        while (counter <= 10);

        // Пример использования цикла foreach
        string[] arr = { "первый", "второй", "третий" };
        Console.WriteLine("Вывод элементов массива (цикл foreach):");
        foreach (string elem in arr)
        {
            Console.WriteLine(elem);
        }
    }
}

/*Листинг 2 – Файл example2.cs

class TestClass
{
    private int val;

    // Функция для вычисления суммы двух чисел
    public int Sum(int a, int b)
    {
        return a + b;
    }

    // Функция для умножения двух чисел
    public int Multiply(int a, int b)
    {
        return a * b;
    }

    public int GetVal()
    {
        return val;
    }
}

class Program
{
    static void Main()
    {
        // Создание объекта класса TestClass
        TestClass TestClass = new TestClass();

        // Вызов функций объекта TestClass
        int sumResult = TestClass.Sum(5, 3);
        int productResult = TestClass.Multiply(5, 3);
        int val = TestClass.GetVal();

        // Вывод результатов на консоль
        Console.WriteLine($"Сумма чисел: {sumResult}");
        Console.WriteLine($"Произведение чисел: {productResult}");
        Console.WriteLine(val);
    }
}
*/