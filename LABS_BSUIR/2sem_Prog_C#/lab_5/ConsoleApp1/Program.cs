namespace nomer_1
{
    public class Program
    {
        public static void Main(string[] args)
        {
            ConsoleApp1.Store store = new ConsoleApp1.Store();

            store.addProduct("cucumber", 100);
            store.addProduct("televizor", 240);
            store.addProduct("samalet", 300);
            store.addProduct("telefon", 200);
            store.addProduct("machina", 400);

            store.addOrder("savonchik", "cucumber");
            store.addOrder("savonchik", "cucumber");
            store.addOrder("savonchik", "samalet");

            store.addOrder("victor", "samalet");

            store.getSumCostProducts("savonchik");
            store.listOfProducts("savonchik");

            store.getSumCostProducts("victor");
            store.listOfProducts("victor");
        }
    }
}
        