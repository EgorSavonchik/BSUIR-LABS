using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_153505_Savonchik//вариант 8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Hotel hotel = new Hotel();

            hotel.AddRoom("good", 500);
            hotel.AddRoom("bad", 100);

            hotel.PrintFreeRoom();

            hotel.ClientReg("Savonchik", 1);

            hotel.PrintFreeRoom();

            Console.WriteLine(hotel.PeoplePrice("Savonchik"));
        }
    }
}
