using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_7
{
    public class triangle
    {
        private double side1, side2, side3;
        static double accurancy = 0.0001;

        public double Side1
        {
            get { return side1; }
            set { side1 = value; }
        }

        public double Side2
        {
            get { return side2; }
            set { side2 = value; }
        }

        public double Side3
        {
            get { return side3; }
            set { side3 = value; }
        }

        public double perimeter()
        {
            return side1 + side2 + side3;
        }

        public double area()
        {
            double p = (side1 + side2 + side3) / 2;

            return Math.Sqrt(p * (p - side1) * (p - side2) * (p - side3));
        }

        public triangle()
        {
            side1 = 10;
            side2 = 10;
            side3 = 10;
        }

        public triangle(double A, double B, double C)
        {
            if (A + B < C || A + C < B || B + C < A || A <= 0 || B <= 0 || C <= 0)
            {
                Console.WriteLine("wrong sides");

                side1 = 10;
                side2 = 10;
                side3 = 10;
            }
            else
            {
                side1 = A;
                side2 = B;
                side3 = C;
            }
        }

        public double this[int index]
        {
            get
            {
                if (index == 0)
                {
                    return side1;
                }
                else if (index == 1)
                {
                    return side2;
                }
                else if (index == 2)
                {
                    return side3;
                }
                else
                {
                    throw new IndexOutOfRangeException();
                }
            }
            set
            {
                if (index == 0)
                {
                    side1 = value;
                }
                else if (index == 1)
                {
                    side2 = value;
                }
                else if (index == 2)
                {
                    side3 = value;
                }
                else
                {
                    throw new IndexOutOfRangeException();
                }
            }
        }

        public override string ToString()
        {
            string temp = "Side1 = " + Convert.ToString(side1) + " Side2 = " + Convert.ToString(side2) + " Side3 = " + Convert.ToString(side3);
            
            return temp;
        }

        public static triangle operator ++(triangle current)
        {
            return new triangle(current.side1 + 1, current.side2 + 1, current.side3 + 1);
        }

        public static triangle operator --(triangle current)
        {
            return new triangle(current.side1 - 1, current.side2 - 1, current.side3 - 1);
        }

        public static triangle operator +(triangle current, double num)
        {
            return new triangle(current.side1 + num, current.side2 + num, current.side3 + num);
        }

        public static triangle operator -(triangle current, double num)
        {
            return new triangle(current.side1 - num, current.side2 - num, current.side3 - num);
        }

        public static triangle operator +(triangle current, triangle other)
        {
            return new triangle(current.side1 + other.side1, current.side2 + other.side2, current.side3 + other.side3);
        }

        public static triangle operator -(triangle current, triangle other)
        {
            return new triangle(current.side1 - other.side1, current.side2 - other.side2, current.side3 - other.side3);
        }

        public static triangle operator *(triangle current, triangle other)
        {
            return new triangle(current.side1 * other.side1, current.side2 * other.side2, current.side3 * other.side3);
        }

        public static triangle operator /(triangle current, triangle other)
        {
            return new triangle(current.side1 / other.side1, current.side2 / other.side2, current.side3 / other.side3);
        }

        public static triangle operator *(triangle current, double num)
        {
            return new triangle(current.side1 * num, current.side2 * num, current.side3 * num);
        }

        public static triangle operator /(triangle current, double num)
        {
            return new triangle(current.side1 / num, current.side2 / num, current.side3 / num);
        }

        public static bool operator >(triangle current, triangle other)
        {
            return (current.area() - other.area()) > accurancy;
        }

        public static bool operator <(triangle current, triangle other)
        {
            return !(current > other);
        }

        public static bool operator >=(triangle current, triangle other)
        {
            return (current.area() - other.area()) >= 0;
        }

        public static bool operator <=(triangle current, triangle other)
        {
            return (other.area() - current.area()) >= 0;
        }

        public static bool operator ==(triangle current, triangle other)
        {
            return (current.area() - other.area()) <= accurancy && (current.area() - other.area()) >= 0;
        }

        public static bool operator !=(triangle current, triangle other)
        {
            return !(current == other);
        }

        public static bool operator false(triangle current)
        {
            return current.side1 == current.side2 && current.side2 == current.side3;
        }

        public static bool operator true(triangle current)
        {
            return current.side1 != current.side2 || current.side2 != current.side3;
        }

        public static explicit operator double(triangle current)
        {
            return current.area();
        }

        public static explicit operator triangle(double val)
        {
            return new triangle(val, val, val);
        }
    }
}
