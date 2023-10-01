using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.Domain.Entities;

namespace WEB_153501_Savonchik.Areas.Admin.FirmAdmin
{
    public class EditModel : PageModel
    {
        private readonly WEB_153501_Savonchik.API.Data.AppDbContext _context;

        public EditModel(WEB_153501_Savonchik.API.Data.AppDbContext context)
        {
            _context = context;
        }

        [BindProperty]
        public Firm Firm { get; set; } = default!;

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null || _context.Firms == null)
            {
                return NotFound();
            }

            var firm =  await _context.Firms.FirstOrDefaultAsync(m => m.Id == id);
            if (firm == null)
            {
                return NotFound();
            }
            Firm = firm;
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

            _context.Attach(Firm).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!FirmExists(Firm.Id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return RedirectToPage("./Index");
        }

        private bool FirmExists(int id)
        {
          return (_context.Firms?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
