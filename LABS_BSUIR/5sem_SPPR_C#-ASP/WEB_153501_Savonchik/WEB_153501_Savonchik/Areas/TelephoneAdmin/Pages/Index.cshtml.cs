using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;
using WEB_153501_Savonchik.Extensions;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153501_Savonchik.Areas.TelephoneAdmin.Pages
{
    public class IndexModel : PageModel
    {
        private readonly ITelephoneService _telephoneService;
        public ListModel<Telephone> Telephone { get; set; } = default!;

        public IndexModel(ITelephoneService telephoneService)
        {
            _telephoneService = telephoneService;
        }

        public async Task<IActionResult> OnGetAsync(int? pageNo)
        {
            ViewData["isAdminPage"] = true;            

            if (_telephoneService.GetTelephoneListAsync(null).Result.Data.Items != null)
            {
                if (Request.IsAjaxRequest())
                {
                    if(pageNo.HasValue) 
                    {
                        return Partial("_ProductListPartial", ((await _telephoneService.GetTelephoneListAsync(null, pageNo.Value)).Data, true));
                    }
                    else
                    {
                        return Partial("_ProductListPartial", ((await _telephoneService.GetTelephoneListAsync(null)).Data, true));
                    }
                }

                Telephone = (await _telephoneService.GetTelephoneListAsync(null)).Data;

                return Page();
            }

            return NotFound();
        }
    }
}
