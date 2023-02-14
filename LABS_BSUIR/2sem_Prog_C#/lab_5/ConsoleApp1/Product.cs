using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Product
    {
        public string name;
        public int cost;

        public Product(string productName, int productCost)
        {
            name = productName;
            cost = productCost;
        }

        public bool equal(string productName)
        {
            return name == productName; 
        }
    }
}
