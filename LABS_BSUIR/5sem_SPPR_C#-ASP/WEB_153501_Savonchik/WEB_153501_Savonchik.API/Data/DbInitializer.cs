using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.Domain.Entities;

namespace WEB_153501_Savonchik.API.Data
{
    public class DbInitializer
    {
        public static async Task SeedData(WebApplication app)
        {
            // Получение контекста БД
            using var scope = app.Services.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<AppDbContext>();

            // Выполнение миграций
            await context.Database.MigrateAsync();

            var _firms = context.Set<Firm>();
            var _telephones = context.Set<Telephone>();

            await _firms.AddAsync(new Firm { Id = 1, Name = "Самсунг", NormalizedName = "samsung" });
            await _firms.AddAsync(new Firm { Id = 2, Name = "Айфон", NormalizedName = "iphone" });

            await _telephones.AddAsync(new Telephone {Name = "Samsung 10", Description = "хороший телефон", Price = 1000,
                    ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung10", Mime=".jpg" , FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 9", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung9", Mime = ".jfif", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 8", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung8", Mime = ".jfif", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 7", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung7", Mime = ".jfif", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 10", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung10", Mime = ".jpg", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 9", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung9", Mime = ".jfif", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 8", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung8", Mime = ".jfif", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 7", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung7", Mime = ".jfif", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 10", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung10", Mime = ".jpg", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 9", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung9", Mime = ".jfif", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 8", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung8", Mime = ".jfif", FirmId = 1 });
            await _telephones.AddAsync(new Telephone { Name = "Samsung 7", Description = "хороший телефон", Price = 1000,
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/samsung7", Mime = ".jfif", FirmId = 1 });
            await _telephones.AddAsync(new Telephone {Name="Iphone 13", Description="дорогой телефон", Price = 5000, 
                ImageSource = app.Configuration.GetValue<string>("ImageUrl") + "/images/iphone13", Mime = ".jpg",FirmId = 2 });

            context.SaveChanges();
        }
    }
}
