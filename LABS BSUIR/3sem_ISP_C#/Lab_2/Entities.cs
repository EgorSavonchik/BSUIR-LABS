namespace Lab2_153505_Savonchik
{


    internal class Hotel
    {
        public delegate void ChangeRoomOrClientCount(string message);
        public event ChangeRoomOrClientCount ChangeRoomOrClientCountEvent;

        public delegate void ClientRegistration(string message);
        public event ClientRegistration ClientRegEvent;

        ICustomCollection<Room> RoomList = new CustomCollection<Room>();
        ICustomCollection<string> ClientList = new CustomCollection<string>();
        public void AddRoom(string inf, int price)
        {
            RoomList.Add(new Room(inf, price));

            ChangeRoomOrClientCountEvent("Hotel: add new room wiht inf: " + inf + ", and price: " + price);
        }

        public void ClientReg(string name, int number)
        {
            ClientRegEvent("Client: " + name + " register room: " + number);

            if (!ClientList.IsExist(name))
            {
                ClientList.Add(name);

                ChangeRoomOrClientCountEvent("Hotel: New client: " + name + " register room: " + number);
            }

            if (number > RoomList.Count)
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
            if (RoomList.Count == 0)
            {
                Console.WriteLine("No free rooms");

                return;
            }

            for (int i = 0; i < RoomList.Count; i++)
            {
                if (RoomList[i].OwnerName == "none")
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

            foreach (var room in RoomList)
            {
                if (room.OwnerName == name)
                {
                    TotalPrice += room.Price;
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

    internal class Journal
    {
        ICustomCollection<string> Information = new CustomCollection<string>();

        public void onChangeRoomList(string message)
        {
            Information.Add(message);
        }

        public void printAll()
        {
            foreach (var ev in Information)
            {
                Console.WriteLine(ev);
            }
        }
    }

}
