using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153501_Savonchik.Areas.TelephoneAdmin.Pages
{
    public class DetailsModel : PageModel
    {
        private readonly ITelephoneService _telephoneService;

        public DetailsModel(ITelephoneService telephoneService)
        {
            _telephoneService = telephoneService;
        }

        public Telephone Telephone { get; set; } = default!;

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null || (await _telephoneService.GetTelephoneListAsync(null)).Data.Items == null)
            {
                return NotFound();
            }

            var telephone = (await _telephoneService.GetTelephoneByIdAsync(id.Value)).Data;

            if (telephone == null)
            {
                return NotFound();
            }
            else
            {
                Telephone = telephone;
            }

            return Page();
        }
    }
}
