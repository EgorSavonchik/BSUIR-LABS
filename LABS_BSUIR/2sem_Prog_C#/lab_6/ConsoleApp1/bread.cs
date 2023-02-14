namespace lab_6
{
    public sealed class bread : abstractProduct
    {
        double discount = 0.05;

        public bread()
        {
            name = "bread";
            price = 500;
        }

        public override void decreasePrice()
        {
            price -= 50;
        }

        public override void changePrice(int newPrice)
        {
            price = Convert.ToInt32(Convert.ToDouble(newPrice) * (1 - discount));
        }
    }
}
