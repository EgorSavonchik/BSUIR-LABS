using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_6
{
    public abstract class abstractProduct
    {
        public int price;
        public string name;

        public abstractProduct()
        {
            price = 0;
            name = "";
        }
        public abstractProduct(int pr, string n)
        {
            price = pr;
            name = n;
        }

        public virtual void changePrice(int newPrice)
        {
            price = newPrice;
        }

        abstract public void decreasePrice();
    }
}
