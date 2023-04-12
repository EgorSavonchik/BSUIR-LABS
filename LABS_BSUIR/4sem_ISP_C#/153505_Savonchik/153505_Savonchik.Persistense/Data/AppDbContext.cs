using _153505_Savonchik.Domain.Entities;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Storage;
using static Microsoft.EntityFrameworkCore.DbLoggerCategory.Database;


namespace _153505_Savonchik.Persistense.Data
{
    public class AppDbContext : DbContext
    {
        public DbSet<Brigade> Brigades { get; set; }
        public DbSet<Work> Works { get; set; }
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {
            Database.EnsureCreated();
        }

        /*protected override void OnModelCreating(ModelBuilder builder)
        {
            base.OnModelCreating(builder);
            // Customize the ASP.NET Identity model and override the defaults if needed.
            // For example, you can rename the ASP.NET Identity table names and more.
            // Add your customizations after calling base.OnModelCreating(builder);

            builder.Entity<Brigade>().HasMany(p => p.Works).WithOne(p => p.Brigade).HasForeignKey(p => p.BrigadeId);
            builder.Entity<Brigade>().HasKey(p => p.Id);
        }*/
    }
}
