using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace Lab_6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Employee> employeeList = new List<Employee>();

            employeeList.Add(new Employee("test1", 10, true));
            employeeList.Add(new Employee("test2", 15, true));
            employeeList.Add(new Employee("test3", 20, true));
            employeeList.Add(new Employee("test4", 25, true));
            employeeList.Add(new Employee("test5", 30, false));
            employeeList.Add(new Employee("test6", 35, true));

            Assembly asm = Assembly.LoadFrom("C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_6\\Lab_6.library\\obj\\Debug\\net6.0\\Lab_6_library.dll");

            Type? Service = asm.GetType("Lab_6_library." + asm.GetTypes().Last()).MakeGenericType(typeof(Employee));
            object? fs = Activator.CreateInstance(Service);

            MethodInfo Save = Service.GetMethod("SaveData");
            MethodInfo Load = Service.GetMethod("ReadFile");

            object[] argumentsToSave = new[] {employeeList };// object[2];
            argumentsToSave[0] = employeeList;
            argumentsToSave[1] = "C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_6\\Lab_6\\data.json";
            Save.Invoke(fs, argumentsToSave);

            object[] argumentsToLoad = new object[1];
            argumentsToLoad[0] = "C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_6\\Lab_6\\data.json";
            List<Employee> newEmployeeList = ((IEnumerable<Employee>)Load.Invoke(fs, argumentsToLoad)).ToList<Employee>();

            foreach (Employee emp in newEmployeeList)
            {
                Console.WriteLine(emp.Name);
                Console.WriteLine(emp.Income);
                Console.WriteLine(emp.OnHoliday);
            }
        }
    }
}