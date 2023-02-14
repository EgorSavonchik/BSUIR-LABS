using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Store
    {
        public List<Client> clientsOrder = new List<Client>();

        public List<Product> productsList = new List<Product>(); 

        public void addProduct(string productName, int productCost)
        {
            productsList.Add(new Product(productName, productCost));
        }

        public void addOrder(string surname, string productName)
        {
            int pos = 0;

            for (int i = 0; i < productsList.Count; i++)
            {
                if (productsList[i].equal(productName))
                {
                    pos = i;
                    break;
                }
            }

            int clientPos = 0;
            bool exists = false;

            for (int i = 0; i < clientsOrder.Count; i++)
            {
                if (surname == clientsOrder[i].surname)
                {
                    clientPos = i;
                    exists = true;
                    break;
                }
            }

            if (exists)
            {    
                clientsOrder[clientPos].addProduct(productsList[pos]);
            }
            else
            {
                clientsOrder.Add(new Client(surname));
                clientsOrder.Last().addProduct(productsList[pos]);
            }
        }

        public void listOfProducts(string surname)
        {
            int pos = 0;

            for(int i = 0; i < clientsOrder.Count; i++)
            {
                if (surname == clientsOrder[i].surname)
                {
                    pos = i;
                    break;
                }
            }

            Console.WriteLine(clientsOrder[pos].getInfo());
        }

        public void getSumCostProducts(string surname)
        {

            int pos = 0;

            for (int i = 0; i < clientsOrder.Count; i++)
            {
                if(surname == clientsOrder[i].surname)
                {
                    pos = i;
                    break;
                }
            }

            Console.WriteLine(clientsOrder[pos].getSum());
        }
    }
}
