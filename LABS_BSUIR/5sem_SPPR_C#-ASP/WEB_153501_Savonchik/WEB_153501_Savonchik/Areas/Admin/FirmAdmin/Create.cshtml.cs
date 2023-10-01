using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.Domain.Entities;

namespace WEB_153501_Savonchik.Areas.Admin.FirmAdmin
{
    public class CreateModel : PageModel
    {
        private readonly WEB_153501_Savonchik.API.Data.AppDbContext _context;

        public CreateModel(WEB_153501_Savonchik.API.Data.AppDbContext context)
        {
            _context = context;
        }

        public IActionResult OnGet()
        {
            return Page();
        }

        [BindProperty]
        public Firm Firm { get; set; } = default!;
        

        // To protect from overposting attacks, see https://aka.ms/RazorPagesCRUD
        public async Task<IActionResult> OnPostAsync()
        {
          if (!ModelState.IsValid || _context.Firms == null || Firm == null)
            {
                return Page();
            }

            _context.Firms.Add(Firm);
            await _context.SaveChangesAsync();

            return RedirectToPage("./Index");
        }
    }
}
