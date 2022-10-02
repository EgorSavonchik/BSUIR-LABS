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
        public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data, IProgress<string> progress)
        {
            progress.Report($"Начало записи в паток {Thread.CurrentThread.ManagedThreadId}");

            await Task.Run(() =>
            {
                JsonSerializer.SerializeAsync<IEnumerable<T>>(stream, data);
            });

            await Process();

            progress.Report($"\nКонец записи в паток {Thread.CurrentThread.ManagedThreadId}");
        }

        public async Task CopyFromStreamAsync(Stream stream, string fileName, IProgress<string> progress)
        {
            progress.Report($"Начало считывания из патока {Thread.CurrentThread.ManagedThreadId}");

            using FileStream file = new FileStream(fileName, FileMode.Create);
            stream.Position = 0;

            await Task.Run(() =>
            {
                stream.CopyToAsync(file);
            });

            await Process();

            progress.Report($"\nКонец считывания из патока {Thread.CurrentThread.ManagedThreadId}");
        }

        public async Task<int> GetStatisticsAsync(string fileName, Func<T, bool> filter)
        {
            using FileStream file = new FileStream(fileName, FileMode.Open);

            IEnumerable<T> temp = await JsonSerializer.DeserializeAsync<IEnumerable<T>>(file);
            
            return temp.Where(filter).Count();
        }

        private async Task Process()
        {
            var p = new Progress<string>(m =>
            {
                Console.Write($"\rПаток {Thread.CurrentThread.ManagedThreadId} {m}");
            });

            await GetProgress(p);
        }

        private async Task GetProgress(IProgress<string> progress)
        {
            for (int i = 0; i <= 100; i += 10)
            {
                await Task.Delay(200);
                progress?.Report(new string($"Завершено на : {i} %"));
            }
        }
    }
}
