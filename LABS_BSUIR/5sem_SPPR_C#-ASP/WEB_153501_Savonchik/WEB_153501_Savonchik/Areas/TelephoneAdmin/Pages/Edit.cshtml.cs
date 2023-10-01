using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Services.FirmService;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153501_Savonchik.Areas.TelephoneAdmin.Pages
{
    public class EditModel : PageModel
    {
        private readonly ITelephoneService _telephoneService;
        private readonly IFirmService _firmService;

        public EditModel(ITelephoneService telephoneService, IFirmService firmSevice)
        {
            _telephoneService = telephoneService;
            _firmService = firmSevice;
        }

        [BindProperty]
        public Telephone Telephone { get; set; } = default!;

        [BindProperty]
        public IFormFile? Image { get; set; }

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null || (await _telephoneService.GetTelephoneListAsync(null)).Data.Items == null)
            {
                return NotFound();
            }

            var telephone = (await _telephoneService.GetTelephoneByIdAsync(id.Value));
            var firms = (await _firmService.GetFirmListAsync());

            if (!telephone.Success || !firms.Success)
            {
                return NotFound();
            }

            ViewData["FirmId"] = new SelectList(firms.Data, "Id", "Name");
            Telephone = telephone.Data;

            return Page();
        }

        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            await _telephoneService.UpdateTelephoneAsync(Telephone.Id, Telephone, Image);

            return RedirectToPage("./Index");
        }

        private bool TelephoneExists(int id)
        {
            return _telephoneService.GetTelephoneByIdAsync(id).Result.Success;
        }
    }
}