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
    public class DeleteModel : PageModel
    {
        private readonly ITelephoneService _telephoneService;

        public DeleteModel(ITelephoneService telephoneService)
        {
            _telephoneService = telephoneService;
        }

        [BindProperty]
        public Telephone Telephone { get; set; } = default!;

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null || await _telephoneService.GetTelephoneListAsync(null) == null)
            {
                return NotFound();
            }

            var response = await _telephoneService.GetTelephoneByIdAsync(id.Value);

            if (response.Success)
            {
                Telephone = response.Data;
            }
            else 
            {
                return NotFound();
            }

            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id == null || await _telephoneService.GetTelephoneListAsync(null) == null)
            {
                return NotFound();
            }

            if (Telephone != null)
            {
                await _telephoneService.DeleteTelephoneAsync(id.Value); // Правильно использовать id с запроса или с bind Telephone???
            }

            return RedirectToPage("./Index");
        }
    }
}
