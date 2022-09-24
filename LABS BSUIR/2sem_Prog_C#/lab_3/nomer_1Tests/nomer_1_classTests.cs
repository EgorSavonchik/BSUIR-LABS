using Microsoft.VisualStudio.TestTools.UnitTesting;
using nomer_1_class;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace nomer_1_class.Tests
{
    [TestClass()]
    public class nomer_1_classTests
    {
        [TestMethod()]
        public void squareTest()
        {
            Assert.AreEqual(nomer_1_class.square(5), 25);
        }

        [TestMethod()]
        public void squareTest1()
        {
            Assert.AreEqual(nomer_1_class.square(0), 0);
        }

        [TestMethod()]
        public void squareTest2()
        {
            Assert.AreEqual(nomer_1_class.square(-5), 25);
        }

        [TestMethod()]
        public void squareTest3()
        {
            Assert.AreEqual(nomer_1_class.square(10000), 100000000);
        }

        [TestMethod()]
        public void squareTest4()
        {
            Assert.AreEqual(nomer_1_class.square(-1), 1);
        }
    }
}