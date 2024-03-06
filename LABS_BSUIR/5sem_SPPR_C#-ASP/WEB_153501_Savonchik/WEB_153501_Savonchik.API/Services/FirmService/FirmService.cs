using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;

namespace WEB_153501_Savonchik.API.Services.FirmService
{
    public class FirmService : IFirmService
    {
        private readonly AppDbContext _appDbContext;

        public FirmService(AppDbContext appDbContext)
        {
            _appDbContext = appDbContext;
        }

        public async Task<ResponseData<List<Firm>>> GetFirmListAsync()
        {
            return new ResponseData<List<Firm>>
            {
                Data = await _appDbContext.Firms.ToListAsync(),
                Success = true
            };
        }
    }
}
