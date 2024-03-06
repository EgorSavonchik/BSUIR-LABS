using Microsoft.AspNetCore.Mvc;
using WEB_153501_Savonchik.Domain.Entities;

namespace WEB_153501_Savonchik.ViewComponents
{
	public class CartViewComponent : ViewComponent
	{
        private readonly Cart _sessionCart;

        public CartViewComponent(Cart sessionCart)
        {
            _sessionCart = sessionCart;
        }

        public Task<IViewComponentResult> InvokeAsync()
        {
            return Task.FromResult<IViewComponentResult>(View(_sessionCart));
        }
    }
}
