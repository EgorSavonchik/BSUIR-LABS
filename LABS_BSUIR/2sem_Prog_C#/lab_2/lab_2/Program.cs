namespace nomer_1
{
    public class nomer_1
    {
        public static bool function(int number)
        {
            return (number % 10 + number / 10) % 3 == 0;
        }

        static void Main(string[] args)
        {

            Console.WriteLine("enter number: ");
            string num_enter = Console.ReadLine();
            int num;

            if (!(int.TryParse(num_enter, out num)) || num < 10 || num > 100)
            {
                Console.WriteLine("uncorrect input");

                Environment.Exit(0);
            }

            if (function(num))
            {
                Console.WriteLine("The sum of digits of a two-digit number is a multiple of three");
            }
            else
            {
                Console.WriteLine("The sum of digits of a two-digit number is not a multiple of three");
            }
        }
    }
}