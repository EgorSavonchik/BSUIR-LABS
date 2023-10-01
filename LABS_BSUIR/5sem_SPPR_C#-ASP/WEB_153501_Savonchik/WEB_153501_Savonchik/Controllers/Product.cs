﻿using Microsoft.AspNetCore.Mvc;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;
using WEB_153501_Savonchik.Services.FirmService;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153501_Savonchik.Controllers
{
    public class Product : Controller
    {
        ITelephoneService _telephoneService;
        IFirmService _firmService;

        public Product(ITelephoneService telephoneService, IFirmService firmService) 
        {
            _telephoneService = telephoneService;
            _firmService = firmService;
        }

        public async Task<IActionResult> Index(string? firm, int? pageNo)
        {
            ResponseData<ListModel<Telephone>> telephoneResponse;

            if(pageNo == null) 
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
                Firm currentFirm = _firmService.GetFirmListAsync().Result.Data.Where(f =>  f.NormalizedName == firm ).First();

                ViewData["currentFirm"] = currentFirm.Name;
                ViewData["normalizedFirmName"] = currentFirm.NormalizedName;
            }

            if (telephoneResponse.Data.CurrentPage == 1)
            {
                ViewData["startPage"] = 1;

                if (telephoneResponse.Data.TotalPages <= 2)
                {
                    ViewData["endPage"] = telephoneResponse.Data.TotalPages;
                }
                else
                {
                    ViewData["endPage"] = telephoneResponse.Data.CurrentPage + 2;
                }
            }
            else if (telephoneResponse.Data.CurrentPage == telephoneResponse.Data.TotalPages)
            {
                ViewData["endPage"] = telephoneResponse.Data.TotalPages;

                if (telephoneResponse.Data.TotalPages <= 2)
                {
                    ViewData["startPage"] = telephoneResponse.Data.CurrentPage - 1;
                }
                else
                {
                    ViewData["startPage"] = telephoneResponse.Data.CurrentPage - 2;
                }
            }
            else
            {
                ViewData["startPage"] = telephoneResponse.Data.CurrentPage - 1;
                ViewData["endPage"] = telephoneResponse.Data.CurrentPage + 1;
            }
            
            return View((telephoneResponse.Data, _firmService.GetFirmListAsync().Result.Data.ToList()));
        }
    }
}
