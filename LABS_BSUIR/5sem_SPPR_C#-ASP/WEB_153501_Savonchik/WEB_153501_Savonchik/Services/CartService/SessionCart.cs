using System;
using System.Text.Json.Serialization;
using WEB_153501_Savonchik.Domain.Entities;
using Microsoft.AspNetCore.Http;
using WEB_153505_Savonchik.Extensions;

namespace WEB_153501_Savonchik.Services.CartService
{
	public class SessionCart : Cart
	{
		public static Cart GetCart(IServiceProvider services)
		{
			ISession? session = services.GetRequiredService<IHttpContextAccessor>().HttpContext?.Session;
			SessionCart cart = session?.Get<SessionCart>("Cart") ?? new SessionCart();
			cart.Session = session;

			return cart;
		}

		[JsonIgnore]
		public ISession? Session { get; set; }

		public override void AddToCart(Telephone telephone)
		{
			base.AddToCart(telephone);
			Session?.Set("Cart", this);
		}

		public override void RemoveItem(int id)
		{
			base.RemoveItem(id);
			Session?.Set("Cart", this);
		}

		public override void ClearAll()
		{
			base.ClearAll();
			Session?.Remove("Cart");
		}
	}
}