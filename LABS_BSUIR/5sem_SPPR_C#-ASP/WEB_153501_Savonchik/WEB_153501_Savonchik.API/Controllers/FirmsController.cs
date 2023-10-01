using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.API.Services.FirmService;
using WEB_153501_Savonchik.Domain.Entities;

namespace WEB_153501_Savonchik.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class FirmsController : ControllerBase
    {
        private readonly IFirmService _firmService;

        public FirmsController(IFirmService firmService)
        {
            _firmService = firmService;
        }

        // GET: api/Firms
        [HttpGet]
        public async Task<ActionResult<IEnumerable<Firm>>> Getfirms()
        {
            return Ok(await _firmService.GetCategoryListAsync());
        }

        /*// GET: api/Firms/5
        [HttpGet("{id}")]
        public async Task<ActionResult<Firm>> GetFirm(int id)
        {
          if (_context.Firms == null)
          {
              return NotFound();
          }
            var firm = await _context.Firms.FindAsync(id);

            if (firm == null)
            {
                return NotFound();
            }

            return firm;
        }

        // PUT: api/Firms/5
        // To protect from overposting attacks, see https://go.microsoft.com/fwlink/?linkid=2123754
        [HttpPut("{id}")]
        public async Task<IActionResult> PutFirm(int id, Firm firm)
        {
            if (id != firm.Id)
            {
                return BadRequest();
            }

            _context.Entry(firm).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!FirmExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }

        // POST: api/Firms
        // To protect from overposting attacks, see https://go.microsoft.com/fwlink/?linkid=2123754
        [HttpPost]
        public async Task<ActionResult<Firm>> PostFirm(Firm firm)
        {
          if (_context.Firms == null)
          {
              return Problem("Entity set 'AppDbContext.firms'  is null.");
          }
            _context.Firms.Add(firm);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetFirm", new { id = firm.Id }, firm);
        }

        // DELETE: api/Firms/5
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteFirm(int id)
        {
            if (_context.Firms == null)
            {
                return NotFound();
            }
            var firm = await _context.Firms.FindAsync(id);
            if (firm == null)
            {
                return NotFound();
            }

            _context.Firms.Remove(firm);
            await _context.SaveChangesAsync();

            return NoContent();
        }

        private bool FirmExists(int id)
        {
            return (_context.Firms?.Any(e => e.Id == id)).GetValueOrDefault();
        }*/
    }
}
