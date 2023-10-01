using Microsoft.AspNetCore.Mvc;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Domain.Models;
using WEB_153501_Savonchik.Services.FirmService;

namespace WEB_153501_Savonchik.Services.TelephoneService
{
    public class MemoryTelephoneService : ITelephoneService
    {
        List<Telephone> _telephones;
        List<Firm> _firms;
        IConfiguration _configuration;
        public MemoryTelephoneService([FromServices] IConfiguration config, IFirmService firmService)
        {
            _configuration= config;
            _firms = firmService.GetFirmListAsync().Result.Data;
            SetupData();
        }

        public Task<ResponseData<Telephone>> CreateTelephoneAsync(Telephone telephone, IFormFile? formFile)
        {
            throw new NotImplementedException();
        }

        public Task DeleteTelephoneAsync(int id)
        {
            throw new NotImplementedException();
        }

        public Task<ResponseData<Telephone>> GetTelephoneByIdAsync(int id)
        {
            throw new NotImplementedException();
        }

        public async Task<ResponseData<ListModel<Telephone>>> GetTelephoneListAsync(string? firmNormalizedName, int pageNo = 1)
        {
            List<Telephone> data;
            int itemsPerPage = Convert.ToInt32(_configuration.GetSection("ItemsPerPage").Value);

            if (firmNormalizedName == null)
            {
                data = _telephones;
            }
            else
            {
                data = _telephones.Where(tel => tel.FirmId == _firms.Where(firm => firm.NormalizedName == firmNormalizedName)
                    .First().Id).ToList();
            }

            return new ResponseData<ListModel<Telephone>>
            {
                Data = new ListModel<Telephone>
                {
                    Items = data.Skip((pageNo - 1) * itemsPerPage).Take(itemsPerPage).ToList(),
                    CurrentPage = pageNo,
                    TotalPages = Convert.ToInt32(Math.Ceiling((double) data.Count / itemsPerPage))
                }, 
                Success = true, 
                ErrorMessage = null 
            };
        }

        public Task UpdateTelephoneAsync(int id, Telephone telephone, IFormFile? formFile)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Инициализация списков
        /// </summary>
        private void SetupData()
        {
            _telephones = new List<Telephone>
            {
                new Telephone {Id = 1, Name = "Samsung 10", Description = "хороший телефон", Price = 1000, 
                    ImageSource = "/images/samsung10", Mime="jpg" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 9", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung9", Mime="jfif" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 8", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung8", Mime="jfif" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 7", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung7", Mime="jfif" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 10", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung10", Mime="jpg" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 9", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung9", Mime="jfif" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 8", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung8", Mime="jfif" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 7", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung7", Mime="jfif" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 10", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung10", Mime="jpg" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 9", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung9", Mime="jfif" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 8", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung8", Mime="jfif" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone {Id = 1, Name = "Samsung 7", Description = "хороший телефон", Price = 1000,
                    ImageSource = "/images/samsung7", Mime="jfif" , FirmId = _firms.Find(c => c.NormalizedName.Equals("samsung")).Id },
                new Telephone { Id = 2, Name="Iphone 13", Description="дорогой телефон", Price = 5000, ImageSource = "/images/iphone13",
                    Mime = "jpg",FirmId = _firms.Find(c => c.NormalizedName.Equals("iphone")).Id },
            };
        }
    }
}
