using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace operation
{
    public class operation
    {
        public static double calculate(int z, int b)
        {
            double x, outNum;

            if (z <= 0)
            {
                Console.WriteLine("z <= 0");

                x = Math.Pow(z, b) + Math.Abs(b / 2);
            }
            else
            {
                Console.WriteLine("z > 0");

                x = Math.Sqrt(z);
            }

            outNum = 1 / Math.Cos(x) + Math.Log(Math.Abs(Math.Tan(x / 2)));

            Console.WriteLine(outNum);

            return outNum;
        }
    }
}
