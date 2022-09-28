﻿using Lab_8.library;

namespace Lab_8
{
    internal class Program
    {
        static async Task Main(string[] args)
        {
            Console.WriteLine($"Начало выполнения мэйна, номер патока {Thread.CurrentThread.ManagedThreadId}");

            List<Galery> list = new List<Galery>();
            //list.Add(new Galery(1, "asdfg", 1));
            for(int i = 0; i < 1000; i++)
            {
                list.Add(new Galery(i, "test" + i, i * 10));
            }

            StreamService<Galery> ss = new StreamService<Galery>();

            Stream temp = new MemoryStream();

            Console.WriteLine($"патоки 1 и 2 запущены из мэйна, номер патока {Thread.CurrentThread.ManagedThreadId}");

            var task1 = ss.WriteToStreamAsync(temp, list);

            Thread.Sleep(300);

            var task2 = ss.CopyFromStreamAsync(temp, "C:\\Users\\HP\\Desktop\\labs\\LABS BSUIR\\3sem_ISP_C#\\Lab_8\\Lab_8\\data.txt");

            task1.Wait();
            task2.Wait();

            int result = await ss.GetStatisticsAsync("C:\\Users\\HP\\Desktop\\labs\\LABS BSUIR\\3sem_ISP_C#\\Lab_8\\Lab_8\\data.txt", obj => obj.NumberOfPicture > 50 ? true : false);
            Console.WriteLine(result);
        
        }
    }
}