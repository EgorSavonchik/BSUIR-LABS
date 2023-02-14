using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataServise
{
    public class DataServise
    {
        public static string GetDay(string date)
        {
            DateTime time = DateTime.Parse(date);

            string[] listDay = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

            return listDay[((int)time.DayOfWeek) - 1];
            
        }

        public static int GetDaysSpan(int day, int month, int year)
        {
            DateTime time = new DateTime(year, month, day);           

            if(time.Subtract(DateTime.Now).Minutes > 0 && time.Subtract(DateTime.Now).Days == 0)
            {
                return 1;
            }

            return Math.Abs(time.Subtract(DateTime.Now).Days);
        }
    }
}
