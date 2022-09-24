using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4
{
    internal class Picture
    {
        int price;
        string name;
        bool availability;
        public int Price { get { return price; } set { price = value; } }
        public string Name { get { return name; } set { name = value; } }
        public bool Availability { get { return availability; } set { availability = value; } }

        public Picture(string name, int price, bool availability)
        {
            this.price = price;
            this.name = name;
            this.availability = availability;
        }

        public Picture()
        {

        }
    }
}
