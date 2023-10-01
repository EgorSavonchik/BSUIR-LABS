using WEB_153501_Savonchik.Services.ApiService;
using WEB_153501_Savonchik.Services.FirmService;
using WEB_153501_Savonchik.Services.TelephoneService;
using WEB_153501_Savonchik.Util;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

UriData uriData = builder.Configuration.GetSection("UriData").Get<UriData>();

builder.Services.AddHttpClient<ITelephoneService, ApiTelephoneService>(opt => opt.BaseAddress = new Uri(uriData.ApiUri));
builder.Services.AddHttpClient<IFirmService, ApiFirmService>(opt => opt.BaseAddress = new Uri(uriData.ApiUri));

builder.Services.AddControllersWithViews();
builder.Services.AddRazorPages();

//builder.Services.AddScoped<IFirmService, MemoryFirmService>();
//builder.Services.AddScoped<ITelephoneService, MemoryTelephoneService>();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();
app.MapRazorPages();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();
