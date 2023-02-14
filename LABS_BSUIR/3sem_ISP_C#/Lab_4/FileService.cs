using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4
{
    internal class FileService : IFileService<Picture>
    {
        public IEnumerable<Picture> ReadFile(string fileName)
        {
            using BinaryReader reader = new BinaryReader(File.Open(fileName, FileMode.Open));

            for (int i = 0; reader.PeekChar() > -1; i++)
            {
                Picture temp = default;

                try
                {
                    temp  = new Picture(reader.ReadString(), reader.ReadInt32(), reader.ReadBoolean());
                }
                catch (IOException ex)
                {
                    Console.WriteLine("failed to read data from file: " + ex);

                    yield break;
                }

                yield return temp;
            }
                    
            reader.Close();
        }

        public void SaveData(IEnumerable<Picture> data, string fileName)
        {

            using BinaryWriter writer = new BinaryWriter(File.Open(fileName, FileMode.Create));
         
            try
            {
                foreach (Picture item in data)
                {
                    writer.Write(item.Name);
                    writer.Write(item.Price);
                    writer.Write(item.Availability);
                }
            }
            catch (IOException ex)
            {
                Console.WriteLine("failed to write data to file" + ex);
            }

            writer.Close();
        }
    }
}
