using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;

namespace WEB_153501_Savonchik.API.Services.FirmService
{
    public interface IFirmService
    {
        /// <summary>
        /// Получение списка всех фирм
        /// </summary>
        /// <returns></returns>
        public Task<ResponseData<List<Firm>>> GetCategoryListAsync();
    }
}
