namespace Lab_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Test filename: C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\6sem_ISOB_C#\\Labs_ISOB\\Lab_1\\Test\\CDecryptTest.txt");
            Console.WriteLine("Enter filename: ");
            string? fileName = Console.ReadLine();
            string source = "";

            if (File.Exists(fileName))
            {
                try
                {
                    source = File.ReadAllText(fileName);
                }
                catch (IOException e)
                {
                    Console.WriteLine($"Reading file error: {e.Message}");
                }
            }
            else
            {
                Console.WriteLine("File not exists");
                return;
            }

            Console.WriteLine("Choose action:\n1)Encrypt\n2)Decrypt");
            string choiceAction = Console.ReadLine();

            Console.WriteLine("Choose cipher:\n1)Ceasar\n2)Vigenere");
            string choiceCipher = Console.ReadLine();

            if (choiceCipher == "1")
            {
                Console.WriteLine("Enter step: ");
                CaesarСipher cc = new CaesarСipher(Convert.ToInt32(Console.ReadLine()));

                Console.WriteLine("Source: " + source);
                if(choiceAction == "1")
                {
                    Console.WriteLine("Encrypt: " + cc.Encrypt(source));
                }
                else if(choiceAction == "2")
                {
                    Console.WriteLine("Decrypt: " + cc.Decrypt(source));
                }
            }
            else if (choiceCipher == "2")
            {
                Console.WriteLine("Enter key: ");
                VigenereСipher vc = new VigenereСipher(Console.ReadLine().Trim());

                Console.WriteLine("Source: " + source);
                if (choiceAction == "1")
                {
                    Console.WriteLine("Encrypt: " + vc.Encrypt(source));
                }
                else if (choiceAction == "2")
                {
                    Console.WriteLine("Decrypt: " + vc.Decrypt(source));
                }
            }
            else
            {
                Console.WriteLine("Invalid value");
            }
        }
    }
}