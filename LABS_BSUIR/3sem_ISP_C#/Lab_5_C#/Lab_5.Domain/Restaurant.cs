namespace Lab_5.Domain
{
    public class Restaurant
    {
        public Kitchen kitchen;
        public int income;
        public string name;
        
        public int Income { get => income; set { income = value; } }
        public string Name { get => name; set { name = value; } }
        public Kitchen Kitchen { get => kitchen; set { kitchen = value; } }

        public Restaurant()
        {
            name = "none";
            income = 0;
            kitchen = new Kitchen();
        }

        public Restaurant(string name, int income, Kitchen kitchen)
        {
            this.name = name;
            this.income = income;
            this.kitchen = kitchen;
        }
    }
}