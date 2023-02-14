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

            Thread thread1 = new Thread(integral.Calculate);
            Thread thread2 = new Thread(integral.Calculate);
            Thread thread3 = new Thread(integral.Calculate);
            Thread thread4 = new Thread(integral.Calculate);
            Thread thread5 = new Thread(integral.Calculate);


            thread1.Name = "1";
            thread2.Name = "2";
            thread3.Name = "3";
            thread4.Name = "4";
            thread5.Name = "5";

            thread1.Priority = ThreadPriority.Highest;
            thread2.Priority = ThreadPriority.Lowest;

            thread1.Start();
            thread2.Start();
            thread3.Start();
            thread4.Start();
            thread5.Start();
        }
    }
}