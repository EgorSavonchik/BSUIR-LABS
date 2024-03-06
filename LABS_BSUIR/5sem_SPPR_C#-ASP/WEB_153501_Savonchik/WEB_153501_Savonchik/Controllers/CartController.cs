using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153505_Savonchik.Controllers;
public class CartController : Controller
{
    private readonly ITelephoneService _TelephoneService;
    private readonly Cart _sessionCart;

    public CartController(ITelephoneService TelephoneService, Cart sessionCart)
    {
        _TelephoneService = TelephoneService;
        _sessionCart = sessionCart;
    }

    public IActionResult Index()
    {
        return View(_sessionCart);
    }

    [Authorize]
    [Route("[controller]/add/{id:int}")]
    public async Task<ActionResult> Add(int id, string returnUrl)
    {
        var data = await _TelephoneService.GetTelephoneByIdAsync(id);
        if (data.Success)
        {
            _sessionCart.AddToCart(data.Data!);
        }
        return Redirect(returnUrl);
    }

    [Authorize]
    [Route("[controller]/remove/{id:int}")]
    public async Task<ActionResult> Remove(int id, string returnUrl)
    {
        var data = await _TelephoneService.GetTelephoneByIdAsync(id);
        if (data.Success)
        {
            _sessionCart.RemoveItem(data.Data!.Id);
        }
        return Redirect(returnUrl);
    }

}