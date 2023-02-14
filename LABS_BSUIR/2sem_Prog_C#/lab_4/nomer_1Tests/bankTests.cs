using Microsoft.VisualStudio.TestTools.UnitTesting;
using bank;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bank.Tests
{
    [TestClass()]
    public class bankTests
    {


        [TestMethod()]
        public void getInstanceTest()
        {
            bank bankTest = bank.getInstance("we", 10, 10, 30);

            Assert.IsTrue(bankTest.getContribituonNumber() == 10 && bankTest.getName() == "we" && bankTest.getContribituonSize() == 30 && bankTest.getContribituonProcent() == 10);
        }

        [TestMethod()]
        public void up_contributionTest()
        {
            bank bankTest = bank.getInstance("we", 10, 10, 30);

            bankTest.up_contribution(50);

            Assert.AreEqual(bankTest.getContribituonSize(), 80);

            bankTest.down_contribution(50);
        }

        [TestMethod()]
        public void down_contributionTest()
        {
            bank bankTest = bank.getInstance("we", 10, 10, 30);

            bankTest.down_contribution(10);

            Assert.AreEqual(bankTest.getContribituonSize(), 20);

            bankTest.up_contribution(10);
        }

        [TestMethod()]
        public void paymentTest()
        {
            bank bankTest = bank.getInstance("we", 10, 10, 30);

            Assert.AreEqual(bankTest.payment(), 30);
        }

        [TestMethod()]
        public void getContribituonSizeTest()
        {
            bank bankTest = bank.getInstance("we", 10, 10, 30);

            Assert.AreEqual(bankTest.getContribituonSize(), 30);
        }

        [TestMethod()]
        public void getContribituonNumberTest()
        {
            bank bankTest = bank.getInstance("we", 10, 10, 30);

            Assert.AreEqual(bankTest.getContribituonNumber(), 10);
        }

        [TestMethod()]
        public void getContribituonProcentTest()
        {
            bank bankTest = bank.getInstance("we", 10, 10, 30);

            Assert.AreEqual(bankTest.getContribituonProcent(), 10);
        }

        [TestMethod()]
        public void getNameTest()
        {
            bank bankTest = bank.getInstance("we", 10, 10, 30);

            Assert.AreEqual(bankTest.getName(), "we");
        }
    }
}