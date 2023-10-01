using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;

namespace WEB_153501_Savonchik.Services.FirmService
{
    public class MemoryFirmService : IFirmService
    {
        public Task<ResponseData<List<Firm>>> GetFirmListAsync()
        {
            var firms = new List<Firm>
            {
                new Firm {Id=1, Name="Самсунг", NormalizedName="samsung"},
                new Firm {Id=2, Name="Айфон", NormalizedName="iphone"},
            };

            var result = new ResponseData<List<Firm>>();
            result.Data = firms;

            return Task.FromResult(result);
        }
    }
}
