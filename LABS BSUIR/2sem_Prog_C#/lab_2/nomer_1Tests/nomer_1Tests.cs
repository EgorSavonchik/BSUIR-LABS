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
    public class nomer_1Tests
    {
        [TestMethod()]
        public void functionTest1()
        {
            if (nomer_1.function(10) != false)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void functionTest2()
        {
            if (nomer_1.function(33) != true)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void functionTest3()
        {
            if (nomer_1.function(45) != true)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void functionTest4()
        {
            if (nomer_1.function(99) != true)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void functionTest5()
        {
            if (nomer_1.function(11) != false)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void functionTest6()
        {
            if (nomer_1.function(55) != false)
            {
                Assert.Fail();
            }
        }
    }
}