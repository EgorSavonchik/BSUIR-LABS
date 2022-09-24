using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace Lab_7
{
    internal class Program
    {
        static void Main(string[] args)
        {
            IntegralCalculate integral = new IntegralCalculate();

            integral.TimeForCalcuLate += () => integral.ShowTime();

            integral.Calculate();
        }
    }
}