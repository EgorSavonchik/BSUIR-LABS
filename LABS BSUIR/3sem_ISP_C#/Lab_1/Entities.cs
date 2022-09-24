using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_153505_Savonchik
{
    internal class Hotel
    {
        ICustomCollection<Room> RoomList = new CustomCollection<Room>();
        public void AddRoom(string inf, int price)
        {
            RoomList.Add(new Room(inf, price));
        }

        public void ClientReg(string name, int number)
        {
            if(number > RoomList.Count)
            {
                Console.WriteLine("Dont exist");

                return;
            }
            else
            {
                RoomList[number - 1].OwnerName = name;
            }
        }

        public void PrintFreeRoom()
        {
            if(RoomList.Count == 0)
            {
                Console.WriteLine("No free rooms");

                return;
            }

            for(int i = 0; i< RoomList.Count; i++)
            {
                if(RoomList[i].OwnerName == "none")
                {
                    Console.WriteLine("number " + i);
                    Console.WriteLine("price " + RoomList[i].Price);
                    Console.WriteLine("information " + RoomList[i].Information);
                    Console.WriteLine();
                }

                RoomList.Next();
            }

            RoomList.Reset();
        }

        public int PeoplePrice(string name)
        {
            int TotalPrice = 0;

            for(int i = 0; i < RoomList.Count; i++)
            {
                if(RoomList[i].OwnerName == name)
                {
                    TotalPrice += RoomList[i].Price;
                }

                RoomList.Next();
            }

            RoomList.Reset();

            return TotalPrice;
        }
    }

    internal class Room
    {
        public Room(string inf, int price)
        {
            Price = price;
            Information = inf;
        }

        public int Price;
        public string OwnerName = "none";
        public string Information;
    }
}
