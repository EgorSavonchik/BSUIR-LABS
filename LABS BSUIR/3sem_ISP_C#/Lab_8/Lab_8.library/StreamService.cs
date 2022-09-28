using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.Json;
namespace Lab_8.library
{
    public class StreamService<T>
    {
        object locker = new();
        public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data)
        {
            lock (locker)

            Console.WriteLine($"Начало записи в паток {Thread.CurrentThread.ManagedThreadId}" );

            await JsonSerializer.SerializeAsync<IEnumerable<T>>(stream, data);

            Console.WriteLine($"Конец записи в паток {Thread.CurrentThread.ManagedThreadId}");


        }

        public async Task CopyFromStreamAsync(Stream stream, string fileName)
        {
            lock (locker)

            Console.WriteLine($"Начало считывания из патока {Thread.CurrentThread.ManagedThreadId}");

            using FileStream file = new FileStream(fileName, FileMode.Create);
            stream.Position = 0;
            await stream.CopyToAsync(file);

            Console.WriteLine($"Конец считывания из патока {Thread.CurrentThread.ManagedThreadId}");
        }

        public async Task<int> GetStatisticsAsync(string fileName, Func<T, bool> filter)
        {
            using FileStream file = new FileStream(fileName, FileMode.Open);

            IEnumerable<T> data = JsonSerializer.Deserialize<IEnumerable<T>>(file);

            return data.Where(filter).Count();
        }
    }
}
