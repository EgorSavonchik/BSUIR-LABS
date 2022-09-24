using Microsoft.VisualStudio.TestTools.UnitTesting;
using nomer_1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace nomer_1.Tests
{
    [TestClass()]
    public class ProgramTests
    {
        [TestMethod()]
        public void doubleUserTest()
        {
            ConsoleApp1.Store store = new ConsoleApp1.Store();

            store.addProduct("cucumber", 100);
            store.addProduct("televizor", 240);
            store.addProduct("samalet", 300);
            store.addProduct("telefon", 200);
            store.addProduct("machina", 400);

            store.addOrder("savonchik", "cucumber");
            store.addOrder("savonchik", "cucumber");
            store.addOrder("savonchik", "samalet");

            store.addOrder("victor", "samalet");

            //store.getSumCostProducts("savonchik");
            int pos = 0;

            for (int i = 0; i < store.clientsOrder.Count; i++)
            {
                if ("savonchik" == store.clientsOrder[i].surname)
                {
                    pos = i;
                    break;
                }
            }

            Assert.AreEqual(500, store.clientsOrder[pos].getSum());

            //store.listOfProducts("savonchik");
            for (int i = 0; i < store.clientsOrder.Count; i++)
            {
                if ("savonchik" == store.clientsOrder[i].surname)
                {
                    pos = i;
                    break;
                }
            }

            Assert.AreEqual("cucumber 100\ncucumber 100\nsamalet 300", store.clientsOrder[pos].getInfo());



            //store.getSumCostProducts("victor");
            for (int i = 0; i < store.clientsOrder.Count; i++)
            {
                if ("victor" == store.clientsOrder[i].surname)
                {
                    pos = i;
                    break;
                }
            }

            Assert.AreEqual(300, store.clientsOrder[pos].getSum());


            //store.listOfProducts("victor");
            for (int i = 0; i < store.clientsOrder.Count; i++)
            {
                if ("victor" == store.clientsOrder[i].surname)
                {
                    pos = i;
                    break;
                }
            }

            Assert.AreEqual("samalet 300", store.clientsOrder[pos].getInfo());
        }

        [TestMethod()]
        public void addTest()
        {
            ConsoleApp1.Store store = new ConsoleApp1.Store();

            store.addProduct("cucumber", 100);
            Assert.AreEqual(1, store.productsList.Count);
            Assert.AreEqual("cucumber", store.productsList[0].name);
            Assert.AreEqual(100, store.productsList[0].cost);

            store.addProduct("televizor", 240);
            Assert.AreEqual(2, store.productsList.Count);
            Assert.AreEqual("televizor", store.productsList[1].name);
            Assert.AreEqual(240, store.productsList[1].cost);

            store.addProduct("samalet", 300);
            Assert.AreEqual(3, store.productsList.Count);
            Assert.AreEqual("samalet", store.productsList[2].name);
            Assert.AreEqual(300, store.productsList[2].cost);

            store.addProduct("telefon", 200);
            Assert.AreEqual(4, store.productsList.Count);
            Assert.AreEqual("telefon", store.productsList[3].name);
            Assert.AreEqual(200, store.productsList[3].cost);

            store.addProduct("machina", 400);
            Assert.AreEqual(5, store.productsList.Count);
            Assert.AreEqual("machina", store.productsList[4].name);
            Assert.AreEqual(400, store.productsList[4].cost);


            store.addOrder("savonchik", "cucumber");
            Assert.AreEqual(1, store.clientsOrder.Count);
            Assert.AreEqual("savonchik", store.clientsOrder[0].surname);
            Assert.AreEqual(1, store.clientsOrder[0].products.Count);
            Assert.AreEqual("cucumber", store.clientsOrder[0].products[0].name);

            store.addOrder("savonchik", "cucumber");
            Assert.AreEqual(1, store.clientsOrder.Count);
            Assert.AreEqual("savonchik", store.clientsOrder[0].surname);
            Assert.AreEqual(2, store.clientsOrder[0].products.Count);
            Assert.AreEqual("cucumber", store.clientsOrder[0].products[1].name);

            store.addOrder("savonchik", "samalet");
            Assert.AreEqual(1, store.clientsOrder.Count);
            Assert.AreEqual("savonchik", store.clientsOrder[0].surname);
            Assert.AreEqual(3, store.clientsOrder[0].products.Count);
            Assert.AreEqual("samalet", store.clientsOrder[0].products[2].name);
        }
    }
}