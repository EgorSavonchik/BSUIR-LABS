using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.API.Services.FirmService;
using WEB_153501_Savonchik.API.Services.TelephoneService;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddHttpContextAccessor();
builder.Services.AddScoped<IFirmService, FirmService>();
builder.Services.AddScoped<ITelephoneService, TelephoneService>();

//
var connStr = builder.Configuration.GetConnectionString("Default");

var options = new DbContextOptionsBuilder<AppDbContext>()
    .UseSqlite(connStr)
    //.UseQueryTrackingBehavior(QueryTrackingBehavior.NoTracking) //
    .Options;

builder.Services.AddScoped((s) => new AppDbContext(options));
builder.Services.AddDbContext<AppDbContext>();
//

builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

//DbInitializer.SeedData(app).Wait();
app.UseStaticFiles();

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
