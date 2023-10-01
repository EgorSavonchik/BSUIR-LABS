using Microsoft.EntityFrameworkCore;
using WEB_153501_Savonchik.Domain.Entities;

namespace WEB_153501_Savonchik.API.Data
{
    public class AppDbContext : DbContext
    {
        public DbSet<Telephone> Telephones { get; set; }
        public DbSet<Firm> Firms { get; set; }
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {
            
        }
    }
}
