using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_3//вариант 8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("xiy" + 5);

            Journal journal = new Journal();

            Hotel hotel = new Hotel();

            hotel.ChangeRoomOrClientCountEvent += journal.onChangeRoomList;
            hotel.ClientRegEvent += (string message) => Console.WriteLine(message);


            hotel.AddRoom("good", 500);
            hotel.AddRoom("bad", 100);
            hotel.AddRoom("good", 2000);
            hotel.AddRoom("bad", 700);
            hotel.AddRoom("good", 1500);
            hotel.AddRoom("bad", 1000);

            hotel.PrintFreeRoom();

            hotel.ClientReg("test", 0);
            hotel.ClientReg("Savonchik", 1);
            //hotel.ClientReg("Shunko", 3); //можно ли задать порядок групп
            hotel.ClientReg("Prigozhii", 2);
            hotel.ClientReg("Shunko", 3);
            hotel.ClientReg("name1", 4);
            hotel.ClientReg("name2", 5);

            hotel.PrintFreeRoom();

            Console.WriteLine("Sorted Room list");

            var SortRoom = hotel.getSortRoomList();

            foreach(var room in SortRoom)
            {
                Console.WriteLine(room);
                
            }

            Console.WriteLine("All Price:");
            Console.WriteLine(hotel.allPrice());
            Console.WriteLine();
            
            Console.WriteLine("Max pay client:");
            Console.WriteLine(hotel.maxPaydClient());
            Console.WriteLine();

            Console.WriteLine("Client who pay, more than 1000");
            Console.WriteLine(hotel.normPayd(1000));
            Console.WriteLine();

            Console.WriteLine("Groups client");
            Console.WriteLine();
            
            var ClientGroup = hotel.groupByPayment();

            foreach (var group in ClientGroup)
            {
                Console.WriteLine(group.Key + ':');

                foreach(var client in group)
                {
                    Console.WriteLine("Owner name: " + client.Value.OwnerName);
                    Console.WriteLine("Price: " + client.Value.Price);
                }

                Console.WriteLine();
            }
        }
    }
}