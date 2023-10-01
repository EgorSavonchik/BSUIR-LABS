using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.Domain.Entities;

namespace WEB_153501_Savonchik.Areas.Admin.FirmAdmin
{
    public class DeleteModel : PageModel
    {
        private readonly WEB_153501_Savonchik.API.Data.AppDbContext _context;

        public DeleteModel(WEB_153501_Savonchik.API.Data.AppDbContext context)
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

            var firm = await _context.Firms.FirstOrDefaultAsync(m => m.Id == id);

            if (firm == null)
            {
                return NotFound();
            }
            else 
            {
                Firm = firm;
            }
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id == null || _context.Firms == null)
            {
                return NotFound();
            }
            var firm = await _context.Firms.FindAsync(id);

            if (firm != null)
            {
                Firm = firm;
                _context.Firms.Remove(Firm);
                await _context.SaveChangesAsync();
            }

            return RedirectToPage("./Index");
        }
    }
}
