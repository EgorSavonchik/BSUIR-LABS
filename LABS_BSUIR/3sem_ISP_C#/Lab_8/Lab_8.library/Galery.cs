namespace Lab_8.library
{
    public class Galery
    {
        int id = 0;
        string nameOfArtist = "none";
        int numberOfPicture = 0;

        public int Id { get { return id; } set { id = value; } }
        public string NameOfArtist { get { return nameOfArtist; } set { nameOfArtist = value; } }
        public int NumberOfPicture { get { return numberOfPicture; } set { numberOfPicture = value; } }
        public Galery(int id, string name, int number)
        {
            id = id;
            nameOfArtist = name;
            numberOfPicture = number;
        }

        public Galery()
        {

        }
    }
}