using Lab_6;
using System.Text.Json;

namespace Lab_6_library
{
    public class FileService<T>  : IFileService<T>  where T : class
    {
        public IEnumerable<T> ReadFile(string fileName)
        {
            using FileStream file = new FileStream(fileName, FileMode.Open);

            IEnumerable<T> data = JsonSerializer.Deserialize<IEnumerable<T>>(file);

            return data;
        }
        public void SaveData(IEnumerable<T> data, string fileName)
        {
            using FileStream file = new FileStream(fileName, FileMode.OpenOrCreate);

            JsonSerializer.Serialize<IEnumerable<T>>(file, data);
        }
    }
}