using System;
using System.Collections.Generic;
using System.Drawing.Printing;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.API.Services.FirmService;
using WEB_153501_Savonchik.API.Services.TelephoneService;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;

namespace WEB_153501_Savonchik.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class TelephonesController : ControllerBase
    {
        private readonly AppDbContext _context;
        private readonly IFirmService _firmService;
        private readonly ITelephoneService _telephoneService;
        private readonly string _imagesPath;

        public TelephonesController(IWebHostEnvironment env, AppDbContext context, IFirmService firmService, ITelephoneService telephoneService)
        {
            _context = context;
            _firmService = firmService;
            _imagesPath = Path.Combine(env.WebRootPath, "Images");
            _telephoneService = telephoneService;
        }

        // GET: api/Telephones
        [AllowAnonymous]
        [HttpGet("")]
        [HttpGet("{category}")]
        [HttpGet("page{pageNo}")]
        [HttpGet("{category}/page{pageNo}")]
        public async Task<ActionResult<ResponseData<List<Telephone>>>> GetTelephones(string? category, int pageNo = 1,int pageSize = 3)
        {
            return Ok(await _telephoneService.GetTelephoneListAsync(category, pageNo, pageSize));
        }

        // GET: api/Telephones/5
        [AllowAnonymous]
        [HttpGet("{id:int}")]
        public async Task<ActionResult<Telephone>> GetTelephone(int id)
        {
            var telephone = await _telephoneService.GetTelephoneByIdAsync(id);

            if (telephone == null)
            {
                return NotFound();
            }

            return Ok(telephone);
        }

        // PUT: api/Telephones/5
        // To protect from overposting attacks, see https://go.microsoft.com/fwlink/?linkid=2123754
        [Authorize]
        [HttpPut("{id}")]
        public async Task<IActionResult> PutTelephone(int id, Telephone telephone)
        {
            /*if (id != telephone.Id)
            {
                return BadRequest();
            }*/
            
            if (!TelephoneExists(id))
            {
                return NotFound();
            }

            await _telephoneService.UpdateTelephoneAsync(id, telephone);

            return NoContent();
        }

        // POST: api/Telephones
        // To protect from overposting attacks, see https://go.microsoft.com/fwlink/?linkid=2123754
        [Authorize]
        [HttpPost]
        public async Task<ActionResult<Telephone>> PostTelephone(Telephone telephone)
        {
            var res = await _telephoneService.CreateTelephoneAsync(telephone);

            return CreatedAtAction("GetTelephone", new { id = res.Data.Id }, res);
        }

        // DELETE: api/Telephones/5
        [Authorize]
        [HttpDelete("{id:int}")]
        public async Task<IActionResult> DeleteTelephone(int id)
        {
            if (await _telephoneService.GetTelephoneListAsync(null) == null)
            {
                return NotFound();
            }
            
            if (await _telephoneService.GetTelephoneByIdAsync(id) == null)
            {
                return NotFound();
            }

            await _telephoneService.DeleteTelephoneAsync(id);

            return NoContent();
        }

        // POST: api/Telephones/5
        [Authorize]
        [HttpPost("{id:int}")]
        public async Task<ActionResult<ResponseData<string>>> PostImage(int id, IFormFile formFile)
        {
            var response = await _telephoneService.SaveImageAsync(id, formFile);

            if (response.Success)
            {
                return Ok(response);
            }

            return NotFound(response);
        }

        private bool TelephoneExists(int id)
        {
            return (_context.Telephones?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
