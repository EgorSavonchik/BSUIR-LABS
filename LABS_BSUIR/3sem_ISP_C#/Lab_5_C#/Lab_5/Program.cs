using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Serialyzer;
using Lab_5.Domain;

namespace Savocnhik_153505_Lab5//вариант 8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            ISerializer serializer = new Serializer();
            List<Restaurant> restaurantList = new List<Restaurant>(), dataList = new List<Restaurant>();

            restaurantList.Add(new Restaurant("Res1", 100, new Kitchen("qwer", 5, true)));
            restaurantList.Add(new Restaurant("Res2", 200, new Kitchen("qwer", 10, true)));
            restaurantList.Add(new Restaurant("Res3", 300, new Kitchen("qwer", 15, false)));
            restaurantList.Add(new Restaurant("Res4", 400, new Kitchen("qwer", 20, true)));
            restaurantList.Add(new Restaurant("Res5", 500, new Kitchen("qwer", 25, true)));


            serializer.SerializeByLINQ(restaurantList, "C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_5\\data.xml");
            serializer.SerializeXML(restaurantList, "C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_5\\data1.xml");
            serializer.SerializeJSON(restaurantList, "C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_5\\data2.json");

            dataList = serializer.DeSerializeByLINQ("C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_5\\data.xml").ToList();

            foreach(Restaurant data in dataList)
            {
                Console.WriteLine(data.name);
                Console.WriteLine(data.income);
                Console.WriteLine(data.kitchen.nameOfTheManager);
                Console.WriteLine(data.kitchen.numberOfCooks);
                Console.WriteLine(data.kitchen.readyToWork);
            }
            Console.WriteLine();

            dataList = serializer.DeSerializeXML("C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_5\\data1.xml").ToList();

            foreach (Restaurant data in dataList)
            {
                Console.WriteLine(data.name);
                Console.WriteLine(data.income);
                Console.WriteLine(data.kitchen.nameOfTheManager);
                Console.WriteLine(data.kitchen.numberOfCooks);
                Console.WriteLine(data.kitchen.readyToWork);
            }
            Console.WriteLine();

            dataList = serializer.DeSerializeJSON("C:\\Users\\HP\\Desktop\\labs\\lab_3sem_C#\\Lab_5\\data2.json").ToList();

            foreach (Restaurant data in dataList)
            {
                Console.WriteLine(data.name);
                Console.WriteLine(data.income);
                Console.WriteLine(data.kitchen.nameOfTheManager);
                Console.WriteLine(data.kitchen.numberOfCooks);
                Console.WriteLine(data.kitchen.readyToWork);
            }
        }
    }
}