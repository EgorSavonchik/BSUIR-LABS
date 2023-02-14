namespace Lab_4//вариант 8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Picture> pictureList = new List<Picture>();

            pictureList.Add(new Picture("Pictire", 50, true));
            pictureList.Add(new Picture("Atest", 1000, false));
            pictureList.Add(new Picture("Btest", 500, true));
            pictureList.Add(new Picture("Dtest", 200, true));
            pictureList.Add(new Picture("Ctest", 100, true));

            IFileService<Picture> fileService = new FileService();

            fileService.SaveData(pictureList, "C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_4\\data.txt");

            List<Picture> downloadedPictureList = new List<Picture>();
            foreach(Picture picture in fileService.ReadFile("C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_4\\data.txt"))
            {
                downloadedPictureList.Add(picture);
            }

            downloadedPictureList = downloadedPictureList.OrderBy(obj => obj, new MyCustomComparer()).ToList();

            Console.WriteLine("Old list\n");

            foreach(Picture picture in pictureList)
            {
                Console.WriteLine(picture.Name + " " + picture.Price + " " + picture.Availability);
            }
            Console.WriteLine();

            Console.WriteLine("New list, sorted by Name\n");

            foreach (Picture picture in downloadedPictureList)
            {
                Console.WriteLine(picture.Name + " " + picture.Price + " " + picture.Availability);
            }
            Console.WriteLine();

            Console.WriteLine("Sort by price\n");

            foreach (Picture picture in downloadedPictureList.OrderBy(obj => obj.Price))
            {
                Console.WriteLine(picture.Name + " " + picture.Price + " " + picture.Availability);
            }
        }
    }
}