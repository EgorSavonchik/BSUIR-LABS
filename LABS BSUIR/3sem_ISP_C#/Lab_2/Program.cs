namespace Lab2_153505_Savonchik//вариант 8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Journal journal = new Journal();

            Hotel hotel = new Hotel();

            hotel.ChangeRoomOrClientCountEvent += journal.onChangeRoomList;

            hotel.ClientRegEvent += (string message) => Console.WriteLine(message);
            hotel.AddRoom("good", 500);
            hotel.AddRoom("bad", 100);

            hotel.PrintFreeRoom();

            hotel.ClientReg("Savonchik", 1);
            hotel.ClientReg("Savonchik", 0);

            hotel.PrintFreeRoom();

            Console.WriteLine(hotel.PeoplePrice("Savonchik"));

            journal.printAll();

            //demonstration
            ICustomCollection<int> array = new CustomCollection<int>();
            array.Add(1);
            array.Add(2);
            array.Add(3);

            //Console.WriteLine(array[3]); //get
            //array[3] = 5; //set
            //array.Remove(4); //remove
        }
    }
}
