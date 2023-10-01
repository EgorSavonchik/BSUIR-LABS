using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;

namespace WEB_153501_Savonchik.Services.FirmService
{
    public interface IFirmService
    {
        /// <summary>
        /// Получение списка всех категорий
        /// </summary>
        /// <returns></returns>
        public Task<ResponseData<List<Firm>>> GetFirmListAsync();
    }
}
