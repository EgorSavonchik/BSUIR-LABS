using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace DataServise.Tests
{
    [TestClass()]
    public class DataServiseTests
    {
        [TestMethod()]
        public void GetDayTest()
        {
            Assert.AreEqual(DataServise.GetDay("30.03.2022"), "Wednesday");
        }

        [TestMethod()]
        public void GetDayTest1()
        {
            Assert.AreEqual(DataServise.GetDay("01.01.0001"), "Monday");
        }

        [TestMethod()]
        public void GetDayTest2()
        {
            Assert.AreEqual(DataServise.GetDay("31.03.2022"), "Thursday");
        }

        [TestMethod()]
        public void GetDayTest3()
        {
            Assert.AreEqual(DataServise.GetDay("29.02.2020"), "Saturday");
        }


        [TestMethod()]
        public void GetDaysSpanTest()
        {
            DateTime time = new DateTime(2022, 03, 30);

            int exp;

            if (time.Subtract(DateTime.Now).Minutes > 0 && time.Subtract(DateTime.Now).Days == 0)
            {
                exp = 1;
            }
            else
            {
                exp = Math.Abs(time.Subtract(DateTime.Now).Days);
            }

            Assert.AreEqual(DataServise.GetDaysSpan(30, 03, 2022), exp);
        }

        [TestMethod()]
        public void GetDaysSpanTest1()
        {
            DateTime time = new DateTime(2022, 04, 01);

            int exp;

            if (time.Subtract(DateTime.Now).Minutes > 0 && time.Subtract(DateTime.Now).Days == 0)
            {
                exp = 1;
            }
            else
            {
                exp = Math.Abs(time.Subtract(DateTime.Now).Days);
            }

            Assert.AreEqual(DataServise.GetDaysSpan(01, 04, 2022), exp);
        }

        [TestMethod()]
        public void GetDaysSpanTest2()
        {
            DateTime time = new DateTime(2022, 03, 31);

            int exp;

            if (time.Subtract(DateTime.Now).Minutes > 0 && time.Subtract(DateTime.Now).Days == 0)
            {
                exp = 1;
            }
            else
            {
                exp = Math.Abs(time.Subtract(DateTime.Now).Days);
            }

            Assert.AreEqual(DataServise.GetDaysSpan(31, 03, 2022), exp);
        }

        [TestMethod()]
        public void GetDaysSpanTest3()
        {
            DateTime time = new DateTime(0001, 01, 01);

            int exp;

            if (time.Subtract(DateTime.Now).Minutes > 0 && time.Subtract(DateTime.Now).Days == 0)
            {
                exp = 1;
            }
            else
            {
                exp = Math.Abs(time.Subtract(DateTime.Now).Days);
            }

            Assert.AreEqual(DataServise.GetDaysSpan(01, 01, 0001), exp);
        }

    }
}