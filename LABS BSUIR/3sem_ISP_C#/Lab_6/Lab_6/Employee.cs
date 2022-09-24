using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_6
{
    public class Employee
    {
        int income;
        string name;
        bool onHoliday;

        public int Income { get { return income; } set { income = value; } }
        
        public string Name { get { return name; } set { name = value; } }
        public bool OnHoliday { get { return onHoliday; } set { onHoliday = value; } }

        public Employee()
        {
            income = 0;
            name = "none";
            onHoliday = false;
        }

        public Employee(string name, int income, bool onHoliday)
        {
            this.income = income;
            this.name = name;
            this.onHoliday = onHoliday;
        }
    }
}
