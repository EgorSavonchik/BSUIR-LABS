using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Client
    {
        public string surname;

        public List<Product> products = new List<Product>();    

        public Client(string input)
        {
            surname = input;
        }

        public static bool operator == (Client first, Client second)
        {
            return (first.surname == second.surname);
        }

        public static bool operator != (Client first, Client second)
        {
            return (first.surname != second.surname);
        }

        public void addProduct(Product product)
        {
            products.Add(product);
        }

        public string getInfo()
        {
            string outStr = "";
            
            for(int i = 0; i < products.Count; i++)
            {
                outStr += products[i].name + " " + products[i].cost;

                if(i != products.Count - 1)
                {
                    outStr += '\n';
                }
            }

            return outStr;
        }

        public int getSum()
        {
            int sum = 0;

            for (int i = 0; i < products.Count; i++)
            {
                sum += products[i].cost;
            }

            return sum;
        }
    }
}
