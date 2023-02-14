namespace nomer_1
{
    public class nomer_1
    {
        static void Main(string[] args)
        {
            bank.bank bank1 = new bank.bank();

            bank1.create("we", 10, 10, 30);
            bank.bank bank2 = new bank.bank();
            bank1.create("we", 10, 10, 1000);
            bank1.up_contribution(50);

            Console.WriteLine(bank1.getContribituonNumber());
            Console.WriteLine(bank1.getContribituonProcent());
            Console.WriteLine(bank1.getContribituonSize());
        }
    }
}