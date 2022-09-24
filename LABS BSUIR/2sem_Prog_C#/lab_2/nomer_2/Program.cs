
namespace nomer_2
{
    public class nomer_2
    {

        static double accuracy = 0.00001;
        public static int check(double x, double y)
        {
            if (y < 12 && (y - Math.Abs(x)) > accuracy)
            {
                return 3;
            }
            else if ((y == 12 && Math.Abs(x) <= 12) || Math.Abs((y - Math.Abs(x))) < accuracy)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }

        static void Main(string[] args)
        {
            double x, y;

            Console.WriteLine("enter point");

            Console.Write("x: ");
            string x_enter = Console.ReadLine();

            if (!double.TryParse(x_enter, out x))
            {
                Console.WriteLine("uncorrect input");

                Environment.Exit(0);
            }

            Console.Write("y: ");
            string y_enter = Console.ReadLine();

            if (!double.TryParse(y_enter, out y))
            {
                Console.WriteLine("uncorrect input");

                Environment.Exit(0);
            }


            if (check(x, y) == 3)
            {
                Console.WriteLine("Yes");
            }
            else if (check(x, y) == 2)
            {
                Console.WriteLine("on border");
            }
            else
            {
                Console.WriteLine("no");
            }
        }
    }
}