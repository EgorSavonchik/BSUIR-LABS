using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Services.FirmService;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153501_Savonchik.Areas.TelephoneAdmin.Pages
{
    public class CreateModel : PageModel
    {
        private readonly ITelephoneService _telephoneService;
        private readonly IFirmService _firmService; 

        public CreateModel(ITelephoneService telephoneService, IFirmService firmService)
        {
            _telephoneService = telephoneService;
            _firmService = firmService;
        }

        public async Task<IActionResult> OnGet()
        {
            var firms = (await _firmService.GetFirmListAsync());

            if (!firms.Success)
            {
                return NotFound();
            }

            ViewData["FirmId"] = new SelectList(firms.Data, "Id", "Name");

            return Page();
        }

        [BindProperty]
        public Telephone Telephone { get; set; } = default!;
        [BindProperty]
        public IFormFile? Image { get; set; }


        // To protect from overposting attacks, see https://aka.ms/RazorPagesCRUD
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid || _telephoneService == null || Telephone == null)
            {
                return Page();
            }

            await _telephoneService.CreateTelephoneAsync(Telephone, Image);

            return RedirectToPage("./Index");
        }
    }
}
