using Microsoft.AspNetCore.Mvc;

namespace WEB_153501_Savonchik.Components
{
	public class CartViewComponent : ViewComponent
	{
		public Task<IViewComponentResult> InvokeAsync()
		{
			return Task.FromResult<IViewComponentResult>(View());
		}
	}
}
