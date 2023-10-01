using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;

namespace WEB_153501_Savonchik.API.Services.TelephoneService
{
    public class TelephoneService : ITelephoneService
    {
        private readonly int _maxPageSize = 20;
        private readonly AppDbContext _context;
        private readonly IWebHostEnvironment _environment;
        private readonly IHttpContextAccessor _httpContextAccessor;
       
        public TelephoneService(AppDbContext appDbContext, IWebHostEnvironment webHostEnvironment, IHttpContextAccessor httpContextAccessor) 
        {
            _context = appDbContext;
            _environment = webHostEnvironment;
            _httpContextAccessor = httpContextAccessor;
        }

        public async Task<ResponseData<Telephone>> CreateTelephoneAsync(Telephone telephone)
        {
            _context.Telephones.Add(telephone);
            await _context.SaveChangesAsync();

            return new ResponseData<Telephone>
            {
                Data = telephone,
                Success = true,
                ErrorMessage = null
            };
        }

        public async Task DeleteTelephoneAsync(int id) 
        {
            Telephone telephone = await _context.Telephones.FindAsync(id);

            var imageFolder = Path.Combine(_environment.WebRootPath, "images");
            // Удалить предыдущее изображение
            if (!String.IsNullOrEmpty(telephone.ImageSource + telephone.Mime))
            {
                var prevImage = Path.Combine(imageFolder, Path.GetFileName(telephone.ImageSource + telephone.Mime));
                if (File.Exists(prevImage))
                {
                    File.Delete(prevImage);
                }
            }

            _context.Telephones.Remove(telephone);
            await _context.SaveChangesAsync();
        }

        public async Task<ResponseData<ListModel<Telephone>>> GetTelephoneListAsync(string? firmNormalizedName,
            int pageNo = 1, int pageSize = 3)
        {
            if (pageSize > _maxPageSize)
            {
                pageSize = _maxPageSize;
            }
                
            var query = _context.Telephones.AsQueryable();
            var dataList = new ListModel<Telephone>();

            query = query.Where(d => firmNormalizedName == null || 
                d.FirmId.Equals(_context.Firms.SingleOrDefault(f => f.NormalizedName == firmNormalizedName).Id));

            // количество элементов в списке
            var count = query.Count();
            if (count == 0)
            {
                return new ResponseData<ListModel<Telephone>>
                {
                    Data = dataList
                };
            }
            // количество страниц
            int totalPages = (int)Math.Ceiling(count / (double)pageSize);
            if (pageNo > totalPages)
            {
                return new ResponseData<ListModel<Telephone>>
                {
                    Data = null,
                    Success = false,
                    ErrorMessage = "No such page"
                };
            }
                
            dataList.Items = await query.Skip((pageNo - 1) * pageSize).Take(pageSize).ToListAsync();
            dataList.CurrentPage = pageNo;
            dataList.TotalPages = totalPages;

            var response = new ResponseData<ListModel<Telephone>>
            {
                Data = dataList
            };

            return response;
        }

        public async Task<ResponseData<Telephone>> GetTelephoneByIdAsync(int id)
        {
            var res = _context.Telephones.Find(id);

            if(res == null)
            {
                return new ResponseData<Telephone> 
                {
                    Data = null, 
                    Success = false,
                    ErrorMessage = "No such page"
                };
            }

            return new ResponseData<Telephone> 
            { 
                Data = res,
            };    
        }

        public async Task<ResponseData<string>> SaveImageAsync(int id, IFormFile formFile) 
        {
            var responseData = new ResponseData<string>();
            var telephone = await _context.Telephones.FindAsync(id);

            if (telephone == null)
            {
                responseData.Success = false;
                responseData.ErrorMessage = "No item found";
                return responseData;
            }

            var host = "https://" + _httpContextAccessor.HttpContext.Request.Host;
            var imageFolder = Path.Combine(_environment.WebRootPath, "images");

            if (formFile != null)
            {
                // Удалить предыдущее изображение
                if (!String.IsNullOrEmpty(telephone.ImageSource + telephone.Mime))
                {
                    var prevImage = Path.Combine(imageFolder, Path.GetFileName(telephone.ImageSource + telephone.Mime));
                    if (File.Exists(prevImage))
                    {
                        File.Delete(prevImage);
                    }
                }

                // Создать имя файла
                var ext = Path.GetExtension(formFile.FileName);
                var fName = Path.ChangeExtension(Path.GetRandomFileName(), ext);
                var filePath = Path.Combine(imageFolder, fName);

                // Сохранить файл
                using (var stream = new FileStream(filePath, FileMode.Create))
                {
                    await formFile.CopyToAsync(stream);
                }

                // Указать имя файла в объекте
                telephone.ImageSource = $"{host}/images/{Path.GetFileNameWithoutExtension(fName)}";
                telephone.Mime = Path.GetExtension(fName);
                await _context.SaveChangesAsync();
            }

            responseData.Data = telephone.ImageSource;
            return responseData;
        }

        public async Task UpdateTelephoneAsync(int id, Telephone telephone)
        {
            //_context.Telephones.Update(telephone);
            //await _context.SaveChangesAsync();

            var existingTelephone = await _context.Telephones.FindAsync(telephone.Id);

            // сначала идет обновление телефона - потом добавление к новому телефону картинки
            // при обновлении телефона затирались поля ImageSource и Mime из-за этого не было возможности удалить старую картинку
            // теперь эти поля остаются неизмененными, в методе добавления картинки по ним удаляется старая, и там же они обновляются на новые
            if (existingTelephone != null) 
            {
                _context.Entry(existingTelephone).CurrentValues.SetValues(telephone);
                _context.Entry(existingTelephone).Property(x => x.ImageSource).IsModified = false; // Устанавливаем свойство как неизмененное
                _context.Entry(existingTelephone).Property(x => x.Mime).IsModified = false; // Устанавливаем свойство как неизмененное

                await _context.SaveChangesAsync();
            }
        }
    }
}
