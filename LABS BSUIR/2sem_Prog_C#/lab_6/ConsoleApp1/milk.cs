using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_6
{
    public class milk : abstractProduct
    {
        public string brand;
        public milk()
        {
            price = 1000;
            name = "milk";
            brand = "none";
        }

        public milk(int pr, string n) : base(pr, n)
        {
            brand = "none";
        }

        public override void decreasePrice()
        {
            base.price -= 100;
        }

        public void decreasePrice(int decrease)
        {
            base.price -= decrease;
        }

        public void setBrand(string newBrand)
        {
            brand = newBrand;
        }
    }
}
