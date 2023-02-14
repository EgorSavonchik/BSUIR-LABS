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
        public void testBread()
        {
            lab_6.bread testBread = new lab_6.bread();

            Assert.AreEqual(testBread.name, "bread");
            Assert.AreEqual(testBread.price, 500);

            testBread.decreasePrice();

            Assert.AreEqual(testBread.price, 450);

            testBread.changePrice(500);

            Assert.AreEqual(testBread.price, 475);
        }

        [TestMethod()]
        public void testMilk()
        {
            lab_6.milk testMilk = new lab_6.milk();

            Assert.AreEqual(testMilk.name, "milk");
            Assert.AreEqual(testMilk.price, 1000);
            Assert.AreEqual(testMilk.brand, "none");

            testMilk.decreasePrice();

            Assert.AreEqual(testMilk.price, 900);

            testMilk.decreasePrice(500);

            Assert.AreEqual(testMilk.price, 400);

            testMilk.changePrice(500);

            Assert.AreEqual(testMilk.price, 500);

            testMilk.setBrand("qwer");

            Assert.AreEqual(testMilk.brand, "qwer");
        }

        [TestMethod()]
        public void testHiddenMethodMilk()
        {
            lab_6.milkFromSoligorsk testMilk = new lab_6.milkFromSoligorsk();

            Assert.AreEqual(testMilk.brand, "none");

            testMilk.setBrand("qwer");

            Assert.AreEqual(testMilk.brand, "Soligorsk qwer");
        }
    }
}