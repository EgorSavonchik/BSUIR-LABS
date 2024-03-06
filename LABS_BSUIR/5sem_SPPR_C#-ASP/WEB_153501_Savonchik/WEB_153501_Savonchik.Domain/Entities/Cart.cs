using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WEB_153501_Savonchik.Domain.Entities
{
    public class Cart
    {
        /// <summary>
        /// Список объектов в корзине
        /// key - идентификатор объекта
        /// </summary>
        public Dictionary<int, CartItem> CartItems { get; set; } = new();

        /// <summary>
        /// Добавить объект в корзину
        /// </summary>
        /// <param name="telephone">Добавляемый объект</param>
        public virtual void AddToCart(Telephone telephone)
        {
            // Проверяем, есть ли уже такой объект в корзине
            if (CartItems.ContainsKey(telephone.Id))
            {
                // Если объект уже есть в корзине, увеличиваем его количество
                CartItems[telephone.Id].Count++;
            }
            else
            {
                // Если объекта нет в корзине, добавляем его
                CartItems[telephone.Id] = new CartItem
                {
                    Item = telephone,
                    Count = 1
                };
            }
        }

        /// <summary>
        /// Удалить объект из корзины
        /// </summary>
        /// <param name="id"> id удаляемого объекта</param>
        public virtual void RemoveItem(int id)
        {
            if (CartItems.ContainsKey(id))
            {
                CartItems.Remove(id);
            }
        }

        /// <summary>
        /// Очистить корзину
        /// </summary>
        public virtual void ClearAll()
        {
            CartItems.Clear();
        }

        /// <summary>
        /// Количество объектов в корзине
        /// </summary>
        public int Count { get => CartItems.Sum(item => item.Value.Count); }

        /// <summary>
        /// Общее количество калорий
        /// </summary>
        public double TotalPrice
        {
            get => CartItems.Sum(item => item.Value.Item.Price * item.Value.Count);
        }
    }
}
