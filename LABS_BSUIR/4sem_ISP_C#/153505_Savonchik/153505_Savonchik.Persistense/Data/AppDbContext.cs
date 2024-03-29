﻿using _153505_Savonchik.Domain.Entities;
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
    }
}
