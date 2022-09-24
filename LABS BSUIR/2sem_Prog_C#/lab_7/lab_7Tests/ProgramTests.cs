using Microsoft.VisualStudio.TestTools.UnitTesting;
using nomer_1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using lab_7;

namespace nomer_1.Tests
{
    [TestClass()]
    public class ProgramTests
    {
        [TestMethod()]
        public void correctTest()
        {
            triangle test = new triangle(3, 3, 15);

            Assert.AreEqual(test.Side1, 10);
            Assert.AreEqual(test.Side2, 10);
            Assert.AreEqual(test.Side3, 10);
        }

        [TestMethod()]
        public void toStringTest()
        {
            triangle test = new triangle();

            Assert.AreEqual(test.ToString(), "Side1 = 10 Side2 = 10 Side3 = 10");
        }

        [TestMethod()]
        public void indexTest()
        {
            triangle test = new triangle();

            Assert.AreEqual(test[0], 10);
            Assert.AreEqual(test[1], 10);
            Assert.AreEqual(test[2], 10);
        }

        [TestMethod()]
        public void plusTest()
        {
            triangle test = new triangle();
            triangle test1 = new triangle(15, 15, 15);

            test = test1 + test;

            Assert.AreEqual(test[0], 25);
            Assert.AreEqual(test[1], 25);
            Assert.AreEqual(test[2], 25);
        }

        [TestMethod()]
        public void minusTest()
        {
            triangle test = new triangle();
            triangle test1 = new triangle(15, 15, 15);

            test = test1 - test;

            Assert.AreEqual(test[0], 5);
            Assert.AreEqual(test[1], 5);
            Assert.AreEqual(test[2], 5);
        }

        [TestMethod()]
        public void multiplyTest()
        {
            triangle test = new triangle();
            triangle test1 = new triangle(15, 15, 15);

            test = test1 * test;

            Assert.AreEqual(test[0], 150);
            Assert.AreEqual(test[1], 150);
            Assert.AreEqual(test[2], 150);
        }

        [TestMethod()]
        public void divisionTest()
        {
            triangle test = new triangle();
            triangle test1 = new triangle(150, 150, 150);

            test = test1 / test;

            Assert.AreEqual(test[0], 15);
            Assert.AreEqual(test[1], 15);
            Assert.AreEqual(test[2], 15);
        }

        [TestMethod()]
        public void incTest()
        {
            triangle test = new triangle();

            test++;

            Assert.AreEqual(test[0], 11);
            Assert.AreEqual(test[1], 11);
            Assert.AreEqual(test[2], 11);
        }

        [TestMethod()]
        public void decTest()
        {
            triangle test = new triangle();

            test--;

            Assert.AreEqual(test[0], 9);
            Assert.AreEqual(test[1], 9);
            Assert.AreEqual(test[2], 9);
        }

        [TestMethod()]
        public void lessTest()
        {
            triangle test = new triangle();
            triangle test1 = new triangle(15, 15, 15);

            Assert.AreEqual(test < test1, true);
            Assert.AreEqual(test <= test1, true);
        }

        [TestMethod()]
        public void moreTest()
        {
            triangle test = new triangle();
            triangle test1 = new triangle(15, 15, 15);

            Assert.AreEqual(test > test1, false);
            Assert.AreEqual(test >= test1, false);
        }

        [TestMethod()]
        public void equalTest()
        {
            triangle test = new triangle();
            triangle test1 = new triangle(15, 15, 15);
            triangle test2 = new triangle();

            Assert.AreEqual(test == test1, false);
            Assert.AreEqual(test == test2, true);
        }

        [TestMethod()]
        public void notEqualTest()
        {
            triangle test = new triangle();
            triangle test1 = new triangle(15, 15, 15);
            triangle test2 = new triangle();

            Assert.AreEqual(test != test1, true);
            Assert.AreEqual(test != test2, false);
        }

        [TestMethod()]
        public void toDoubleTest()
        {
            triangle test = new triangle(3, 4, 5);

            Assert.AreEqual((double)test, 6);
        }

        [TestMethod()]
        public void toTriangleTest()
        {
            double num = 10;
            triangle test = (triangle)num;
            
            Assert.AreEqual(test[0], 10);
            Assert.AreEqual(test[1], 10);
            Assert.AreEqual(test[2], 10);
        }

        [TestMethod()]
        public void funcTest()
        {
            triangle test = new triangle(3, 4, 5);

            Assert.AreEqual(test.area(), 6);
            Assert.AreEqual(test.perimeter(), 12);
        }
    }
}