using System.Diagnostics;

namespace Lab_7
{
    public class IntegralCalculate
    {
        public delegate void TimeDelegate();
            
        public event TimeDelegate TimeForCalcuLate;
        public void ShowTime()
        {
            Console.WriteLine(tics);
        }
        private long tics = 0;
        public long Tics{get{return tics;} set { tics = value; } } 

        public double Calculate()
        {
            Stopwatch sw = Stopwatch.StartNew();
            double sum = 0;
            

            for(double i = 0; i < 1; i += 0.000001)//убрал 2 нуля
            {
                sum += Math.Sin(i) * 0.000001;
                tics = sw.ElapsedMilliseconds;

                for(int j = 0; j < 1000; j++)//убрал 2 ноль
                {
                    int temp = 2 + 2;
                }
            }

            TimeForCalcuLate();
            return sum;
        }
    }
}
