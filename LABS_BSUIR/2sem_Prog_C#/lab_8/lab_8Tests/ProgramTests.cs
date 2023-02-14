using Microsoft.VisualStudio.TestTools.UnitTesting;
using nomer_1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using lab_8;

namespace nomer_1.Tests
{
    [TestClass()]
    public class ProgramTests
    {
        [TestMethod()]
        public void createTest()
        {
            store stor = new store("name");

            Assert.AreEqual(stor.Name, "name");
        }

        [TestMethod()]
        public void addNoDiscTest()
        {
            store stor = new store("name");

            stor.addProduct("product1", 10);
            stor.addProduct("product2", 15); 
            stor.addProduct("product3", 20);
            stor.addProduct("product4", 25);
            stor.addProduct("product5", 30);

            Assert.AreEqual(stor[0].Name, "product1");
            Assert.AreEqual(stor[0].Price.getPrice(), 10);
            Assert.AreEqual(stor[1].Name, "product2");
            Assert.AreEqual(stor[1].Price.getPrice(), 15);
            Assert.AreEqual(stor[2].Name, "product3");
            Assert.AreEqual(stor[2].Price.getPrice(), 20);
            Assert.AreEqual(stor[3].Name, "product4");
            Assert.AreEqual(stor[3].Price.getPrice(), 25);
            Assert.AreEqual(stor[4].Name, "product5");
            Assert.AreEqual(stor[4].Price.getPrice(), 30);

            Assert.AreEqual(stor.getTotalPrice(), 100);
            Assert.AreEqual(stor.minPrice().Price.getPrice(), 10);
        }

        [TestMethod()]
        public void addWithDiscTest()
        {
            store stor = new store("name");

            stor.addDiscountProduct("product1", 10, 10);
            stor.addDiscountProduct("product2", 15, 10);
            stor.addDiscountProduct("product3", 20, 10);
            stor.addDiscountProduct("product4", 25, 10);
            stor.addDiscountProduct("product5", 30, 10);

            Assert.AreEqual(stor[0].Name, "product1");
            Assert.AreEqual(stor[0].Price.getPrice(), 9);
            Assert.AreEqual(stor[1].Name, "product2");
            Assert.AreEqual(stor[1].Price.getPrice(), 13.5);
            Assert.AreEqual(stor[2].Name, "product3");
            Assert.AreEqual(stor[2].Price.getPrice(), 18);
            Assert.AreEqual(stor[3].Name, "product4");
            Assert.AreEqual(stor[3].Price.getPrice(), 22.5);
            Assert.AreEqual(stor[4].Name, "product5");
            Assert.AreEqual(stor[4].Price.getPrice(), 27);

            Assert.AreEqual(stor.getTotalPrice(), 90);
            Assert.AreEqual(stor.minPrice().Price.getPrice(), 9);
        }
    }
}