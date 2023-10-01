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
    public class IndexModel : PageModel
    {
        private readonly WEB_153501_Savonchik.API.Data.AppDbContext _context;

        public IndexModel(WEB_153501_Savonchik.API.Data.AppDbContext context)
        {
            _context = context;
        }

        public IList<Firm> Firm { get;set; } = default!;

        public async Task OnGetAsync()
        {
            if (_context.Firms != null)
            {
                Firm = await _context.Firms.ToListAsync();
            }
        }
    }
}
