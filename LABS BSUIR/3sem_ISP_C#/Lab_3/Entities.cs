using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_3
{ 
    internal class Hotel
    {
        public delegate void ChangeRoomOrClientCount(string message);
        public event ChangeRoomOrClientCount ChangeRoomOrClientCountEvent;

        public delegate void ClientRegistration(string message);
        public event ClientRegistration ClientRegEvent;

        Dictionary<int, Room> RoomList = new Dictionary<int, Room>();
        List<Client> ClientList = new List<Client>();

        public void AddRoom(string inf, int price)
        {
            RoomList[RoomList.Count()] = (new Room(inf, price));

            ChangeRoomOrClientCountEvent("Hotel: add new room wiht inf: " + inf + ", and price: " + price);
        }

        public void ClientReg(string name, int number)
        {
            ClientRegEvent("Client: " + name + " register room: " + number);

            if (number > RoomList.Count)
            {
                Console.WriteLine("Dont exist");

                return;
            }
            else if(RoomList[number].OwnerName != "none")
            {
                Console.WriteLine("Room is not free");

                return;
            }
            else
            {
                if (ClientList.Count(obj => obj.ClientName == name) == 0)
                {
                    ClientList.Add(new Client(name));

                    ChangeRoomOrClientCountEvent("Hotel: New client: " + name + " register room: " + number);
                }

                RoomList[number].OwnerName = name;

                ClientList.First(obj => obj.ClientName == name).addRoom(RoomList[number]);
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
            }
        }

        public int PeoplePrice(string name)
        {
            int TotalPrice = 0;

            for(int i = 0; i < RoomList.Count;i++)  
            {
                if (RoomList[i].OwnerName == name)
                {
                    TotalPrice += RoomList[i].Price;
                }
            }

            return TotalPrice;
        }

        public IEnumerable<string> getSortRoomList()
        {
           return RoomList.Values.OrderBy(t => t.Price).Select(r=>r.Information);

           // return SortRoomList;
        }

        public int allPrice()
        {
            
            return RoomList.Values
                .Where(room => room.OwnerName != "none")
                .Sum(obj => obj.Price);
        }

        public string maxPaydClient()
        {
            return ClientList.First(obj => obj.TotalPay == ClientList.Max(obj => obj.TotalPay)).ClientName;
        }

        public int normPayd(int RateOfPayment)
        {
            //return ClientList.Aggregate<Client, int>(ClientList, 0, (Client obj, int count) => count + Convert.ToInt32(obj.TotalPay >= RateOfPayment));
            return ClientList.Aggregate(0, (count, obj) => count +=  obj.TotalPay >= RateOfPayment?1:0); // obj.TotalPay >= RateOfPayment ? 1 : 0); // не работает тернарка
        }

        public IEnumerable<IGrouping<string, KeyValuePair<int, Room>>> groupByPayment()
        {
            return RoomList.GroupBy(obj => obj.Value.Category);
        }

    }

    internal class Room
    {
        public Room(string inf, int price)
        {
            Price = price;
            Information = inf;

            if (price <= 500)
            {
                Category = "low";
            }
            else if (price <= 1000)
            {
                Category = "midle";
            }
            else
            {
                Category = "high";
            }
        }

        public string Category;
        public int Price;
        public string OwnerName = "none";
        public string Information;
    }

    internal class Client
    {
        public Client(string name)
        {
            ClientName = name;
        }

        public void addRoom(Room item)
        {
            RoomOwnByClient.Add(item);

            TotalPay+= item.Price;
        }

        public int TotalPay = 0;
        List<Room> RoomOwnByClient = new List<Room>();
        public string ClientName;
    }


    internal class Journal
    {
        List<string> Information = new List<string>();

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