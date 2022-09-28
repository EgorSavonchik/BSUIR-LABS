using System.Diagnostics;
using System.Text;
//using System.Threading;

namespace Lab_7
{
    public class IntegralCalculate
    {
        public delegate void TimeDelegate(long tic);
        public event TimeDelegate TimeForCalcuLate;

        public delegate void ProgressBarDelegate(int percent, string ProgressBar);
        public event ProgressBarDelegate ProgressBarEvent;
        Mutex mutex = new();
        Semaphore semaphore = new Semaphore(2, 5);
        public void ShowTime(long tic)
        {
            mutex.WaitOne();
            
            Console.SetCursorPosition(0, Convert.ToInt32(Thread.CurrentThread.Name) - 1);
            Console.WriteLine($"Паток {Environment.CurrentManagedThreadId} закончил выполнение за " + Convert.ToDouble(tic) / 1000);
            
            mutex.ReleaseMutex();
        }
        public void OutProgressBar(int percent, string progressBar)
        {
            mutex.WaitOne();
            
            Console.SetCursorPosition(0, Convert.ToInt32(Thread.CurrentThread.Name) - 1);
            Console.WriteLine($"Паток {Environment.CurrentManagedThreadId} процесс {progressBar} {percent}%");

            mutex.ReleaseMutex();
        }
        public void Calculate()
        {
            semaphore.WaitOne();

            Stopwatch sw = Stopwatch.StartNew();
            double sum = 0;
            int percent = 0;
            StringBuilder outString = new StringBuilder("[----------]");

            ProgressBarEvent(0, outString.ToString());

            for (double i = 0; i < 1; i += 0.000001)//убрал 2 нуля
            {
                sum += Math.Sin(i) * 0.000001;
                
                if (i == 0.000001)
                {
                    outString[1] = '>';
                }
                else if(Math.Abs(i - 0.01) < 0.00000000001 || (percent != 0 && Convert.ToInt32(i * 100) > percent))
                {
                    if(percent % 10 == 0)
                    {
                        outString[percent / 10] = '=';
                        outString[percent / 10 + 1] = '>';
                    }

                    ProgressBarEvent(Convert.ToInt32(i * 100), outString.ToString());
                }

                for(int j = 0; j < 1000; j++)//убрал 3 ноль
                {
                    int temp = 2 + 2;
                }

                percent = Convert.ToInt32(i * 100);
            }

            TimeForCalcuLate(sw.ElapsedMilliseconds);

            semaphore.Release();
        }
    }
}
