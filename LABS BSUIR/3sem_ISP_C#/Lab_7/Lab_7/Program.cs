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

            integral.TimeForCalcuLate += integral.ShowTime;
            integral.ProgressBarEvent += integral.OutProgressBar;

            Thread thread = new Thread(integral.Calculate);
            Thread thread1 = new Thread(integral.Calculate);
            thread.Priority = ThreadPriority.Highest;
            thread1.Priority = ThreadPriority.Lowest;
            thread.Start();
            thread1.Start();
        }
    }
}