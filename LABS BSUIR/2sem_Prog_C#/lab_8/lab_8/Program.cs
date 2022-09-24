using System;
using lab_8;


namespace nomer_1
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var store = new store("Mila");
            store.addProduct("Milk", 1.545);
            store.addProduct("Bread", 1.45);
            store.addDiscountProduct("Cucumber", 5.29, 20);
            store.addDiscountProduct("Tomato", 2.99, 10);
            store.print();
            Console.WriteLine("Total price: {0}", store.getTotalPrice());
            Console.WriteLine(store.minPrice().Price.getPrice());
        }
    }
}