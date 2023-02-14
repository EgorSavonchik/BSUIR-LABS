using System;
using lab_7;

namespace nomer_1
{
    public class Program
    {
        public static void Main(string[] args)
        {
            triangle triangle = new triangle(3.5, 5.6, 7.6);
            triangle triangle1 = new triangle(1.2, 5.6, 2.8);
            Console.WriteLine("");
            triangle triangle2 = new triangle(4.76, 8.78, 7.85);

            Console.WriteLine(triangle2.perimeter());
            Console.WriteLine("");
            Console.WriteLine(triangle.area());
            Console.WriteLine("");
            Console.WriteLine(triangle);
            Console.WriteLine("");

            Console.WriteLine(triangle1);
            Console.WriteLine("");

            Console.WriteLine(triangle2);
            Console.WriteLine("");

            triangle++;
            triangle1--;
            triangle2 -= 2;

            Console.WriteLine(triangle);
            Console.WriteLine("");

            Console.WriteLine(triangle1);
            Console.WriteLine("");

            Console.WriteLine(triangle2);
            Console.WriteLine("");

            triangle = triangle - 3;
            triangle1 = triangle1 / 2;

            Console.WriteLine(triangle);
            Console.WriteLine("");

            Console.WriteLine(triangle1);
            Console.WriteLine("");

            Console.WriteLine(triangle[0]);
            Console.WriteLine(triangle[1]);
            Console.WriteLine(triangle[2]);
            Console.WriteLine("");

            Console.WriteLine(triangle1[0]);
            Console.WriteLine(triangle1[1]);
            Console.WriteLine(triangle1[2]);
            Console.WriteLine("");

            Console.WriteLine(triangle1[0]);
            Console.WriteLine(triangle2[1]);
            Console.WriteLine(triangle2[2]);
            Console.WriteLine("");
        }
    }
}