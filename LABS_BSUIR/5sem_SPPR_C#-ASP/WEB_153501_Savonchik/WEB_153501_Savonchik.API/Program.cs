using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using WEB_153501_Savonchik.API.Data;
using WEB_153501_Savonchik.API.Services.FirmService;
using WEB_153501_Savonchik.API.Services.TelephoneService;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Models;

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

builder.Services
    .AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
    .AddJwtBearer(opt =>
    {
        opt.Authority = builder
        .Configuration
        .GetSection("isUri").Value;
        opt.TokenValidationParameters.ValidateAudience = false;
        opt.TokenValidationParameters.ValidTypes =
        new[] { "at+jwt" };
    });

builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

builder.Services.AddCors(options =>
{
    options.AddPolicy("BlazorWasmPolicy", builder =>
    {
        builder.WithOrigins("https://localhost:7004")
             .AllowAnyMethod()
             .AllowAnyHeader();
    });
});
var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}


app.UseCors(c => c.AllowAnyOrigin().AllowAnyMethod().AllowAnyHeader());

//DbInitializer.SeedData(app).Wait();
app.UseStaticFiles();

app.UseHttpsRedirection();
app.UseCors("BlazorWasmPolicy");

app.UseAuthentication();
app.UseAuthorization();

app.MapControllers();

app.Run();
