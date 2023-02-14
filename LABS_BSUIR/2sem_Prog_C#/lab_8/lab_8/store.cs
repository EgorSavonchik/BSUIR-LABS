using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_8
{
    public class store
    {
        private string name;

        private List<product> products;
        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }

        }

        public product this[int index]
        {
            get
            {
                return products[index];
            }
        }

        public store(string newName)
        {
            name = newName;
            products = new List<product>();
        }

        public store(string newName, List<product> newProducts)
        {
            name = newName;
            products = newProducts;
        }

        public product minPrice()
        {
            product min = products[0];

            foreach(var prod in products)
            {
                if(prod.Price.getPrice() < min.Price.getPrice())
                {
                    min = prod;
                }
            }

            return min;
        }

        public void addDiscountProduct(string name, double price, double discount)
        {
            products.Add(new product(name, new withDiscount(price, discount)));
        }

        public void addProduct(string name, double price)
        {
            products.Add(new product(name, new noDiscount(price)));
        }

        public double getTotalPrice()
        {
            double totalPrice = 0;

            foreach (var product in products)
            {
                totalPrice += product.Price.getPrice();
            }

            return Math.Round(totalPrice, 3);
        }


        public void print()
        {
            Console.WriteLine("Store: " + name);
            Console.WriteLine("Products:");

            foreach (var product in products)
            {
                Console.WriteLine(product.Name + " " + Convert.ToString(Math.Round(product.Price.getPrice(), 3)));
            }
        }

        public product getProduct(string name)
        {
            foreach (var product in products)
            {
                if (product.Name == name)
                {
                    return product;
                }
            }
            return null;
        }

    }
    public class product
    {
        private string name;
        private IPrice price;

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }

        public IPrice Price
        {
            get
            {
                return price;
            }
            set
            {
                price = value;
            }
        }


        public product(string newName, IPrice newPrice)
        {
            name = newName;
            price = newPrice;
        }

    }

    public interface IPrice
    {
        double getPrice();
    }

    class noDiscount : IPrice
    {
        private double price;

        public noDiscount(double newPrice)
        {
            price = newPrice;
        }

        public double getPrice()
        {
            return price;
        }
    }


    class withDiscount : IPrice
    {
        private double price;
        private double discount;

        public withDiscount(double newPrice, double newDiscount)
        {
            price = newPrice;
            discount = newDiscount;
        }

        public double getPrice()
        {
            return price * (1 - discount / 100);
        }
    }
}