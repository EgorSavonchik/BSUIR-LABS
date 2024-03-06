using Microsoft.AspNetCore.Mvc;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;
using WEB_153501_Savonchik.Extensions;
using WEB_153501_Savonchik.Services.FirmService;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153501_Savonchik.Controllers
{
    public class ProductController : Controller
    {
        readonly ITelephoneService _telephoneService;
        readonly IFirmService _firmService;

        public ProductController(ITelephoneService telephoneService, IFirmService firmService) 
        {
            _telephoneService = telephoneService;
            _firmService = firmService;
        }

        public async Task<IActionResult> Index(string? firm, int? pageNo)
        {
            ResponseData<ListModel<Telephone>> telephoneResponse;

			ResponseData<List<Firm>> firmResponse = _firmService.GetFirmListAsync().Result;
			if (!firmResponse.Success)
			{
				return NotFound(firmResponse.ErrorMessage);
			}
            ViewData["firms"] = firmResponse.Data;

			if (pageNo == null) 
            {
                telephoneResponse = await _telephoneService.GetTelephoneListAsync(firm);
            }
            else 
            {
                telephoneResponse = await _telephoneService.GetTelephoneListAsync(firm, pageNo.Value);
            }

            if (!telephoneResponse.Success)
            {
                return NotFound(telephoneResponse.ErrorMessage);
            }

            if(firm == null) 
            {
                ViewData["currentFirm"] = "Все";
                ViewData["normalizedFirmName"] = null;
            }
            else
            {
				Firm currentFirm = firmResponse.Data.Where(f =>  f.NormalizedName == firm ).First();

                ViewData["currentFirm"] = currentFirm.Name;
                ViewData["normalizedFirmName"] = currentFirm.NormalizedName;
            }

            if (Request.IsAjaxRequest())
            {
                return PartialView("_ProductListPartial", (telephoneResponse.Data, false));
            }

            return View(telephoneResponse.Data);
        }
    }
}
