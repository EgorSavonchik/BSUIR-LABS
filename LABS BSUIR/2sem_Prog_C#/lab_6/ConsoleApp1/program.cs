using System;

namespace nomer_1
{
    public class Program
    {
        public static void Main(string[] args)
        {
            lab_6.bread testBread = new lab_6.bread();

            Console.WriteLine(testBread.name + " " + Convert.ToString(testBread.price));

            testBread.decreasePrice();

            Console.WriteLine(testBread.name + " " + Convert.ToString(testBread.price));

            testBread.changePrice(500);

            Console.WriteLine(testBread.name + " " + Convert.ToString(testBread.price));

            lab_6.milkFromSoligorsk testMilk = new lab_6.milkFromSoligorsk();

            Console.WriteLine(testMilk.name + " " + Convert.ToString(testMilk.price) + " " + testMilk.brand);

            testMilk.decreasePrice();

            Console.WriteLine(testMilk.name + " " + Convert.ToString(testMilk.price));

            testMilk.decreasePrice(300);
            testMilk.setBrand("dfgh");

            Console.WriteLine(testMilk.name + " " + Convert.ToString(testMilk.price) + " " + testMilk.brand);

            testMilk.changePrice(500);

            Console.WriteLine(testMilk.name + " " + Convert.ToString(testMilk.price));

            lab_6.milk baseTest = new lab_6.milk(1500, "MILK");

            Console.WriteLine(baseTest.name + " " + Convert.ToString(baseTest.price));
        }
    }
}