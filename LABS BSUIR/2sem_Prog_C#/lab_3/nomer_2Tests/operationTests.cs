using Microsoft.VisualStudio.TestTools.UnitTesting;
using operation;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace operation.Tests
{
    [TestClass()]
    public class operationTests
    {
        [TestMethod()]
        public void calculateTest()
        {
            Assert.AreEqual(operation.calculate(-2, 2), 3.233659840569033);
        }

        [TestMethod()]
        public void calculateTest1()
        {
            Assert.AreEqual(operation.calculate(1, 1), 1.2462332717393338);
        }

        [TestMethod()]
        public void calculateTest2()
        {
            Assert.AreEqual(operation.calculate(0, 0), 1.2462332717393338);
        }

        [TestMethod()]
        public void calculateTest3()
        {
            Assert.AreEqual(operation.calculate(5, 5), -0.8994418955366902);
        }

        [TestMethod()]
        public void calculateTest4()
        {
            Assert.AreEqual(operation.calculate(1000, 1000), -1.2435521142164332);
        }
    }
}