using Microsoft.VisualStudio.TestTools.UnitTesting;
using nomer_2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace nomer_2.Tests
{
    [TestClass()]
    public class nomer_2Tests
    {
        [TestMethod()]
        public void check_inside()
        {
            int t = nomer_2.check(5, 6);
            
            if (t != 3)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void check_inside1()
        {
            int t = nomer_2.check(1, 10);

            if (t != 3)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void check_outside()
        {
            int t = nomer_2.check(10, 100);

            if (t != 1)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void check_outnside()
        {
            int t = nomer_2.check(5, 4);

            if (t != 1)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void check_borber()
        {
            int t = nomer_2.check(5, 12);

            if (t != 2)
            {
                Assert.Fail();
            }
        }

        [TestMethod()]
        public void check_border1()
        {
            int t = nomer_2.check(5, 5);

            if (t != 2)
            {
                Assert.Fail();
            }
        }
    }
}