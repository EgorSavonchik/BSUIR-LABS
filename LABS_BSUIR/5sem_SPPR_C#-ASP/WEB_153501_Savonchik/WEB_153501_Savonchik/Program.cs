using Serilog;
using WEB_153501_Savonchik.Middleware;
using WEB_153501_Savonchik.Services.ApiService;
using WEB_153501_Savonchik.Services.CartService;
using WEB_153501_Savonchik.Services.FirmService;
using WEB_153501_Savonchik.Services.TelephoneService;
using WEB_153501_Savonchik.Util;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

UriData uriData = builder.Configuration.GetSection("UriData").Get<UriData>();

builder.Services.Configure<UriData>(builder.Configuration.GetSection("UriData")); // добавлени IOptions<UriData>
builder.Services.AddHttpClient<ITelephoneService, ApiTelephoneService>(opt => opt.BaseAddress = new Uri(uriData.ApiUri));
builder.Services.AddHttpClient<IFirmService, ApiFirmService>(opt => opt.BaseAddress = new Uri(uriData.ApiUri));
builder.Services.AddScoped(sp => SessionCart.GetCart(sp));

builder.Services.AddHttpContextAccessor();
builder.Services.AddSession();

builder.Services.AddControllersWithViews();
builder.Services.AddRazorPages();

// регистраци€ сервиса аутентификации 
builder.Services.AddAuthentication(opt =>
{
    opt.DefaultScheme = "cookie";
    opt.DefaultChallengeScheme = "oidc";
})
    .AddCookie("cookie")
    .AddOpenIdConnect("oidc", options =>
    {
        options.Authority =
        builder.Configuration["InteractiveServiceSettings:AuthorityUrl"];
        options.ClientId =
        builder.Configuration["InteractiveServiceSettings:ClientId"];
        options.ClientSecret =
        builder.Configuration["InteractiveServiceSettings:ClientSecret"];
        // ѕолучить Claims пользовател€
        options.GetClaimsFromUserInfoEndpoint = true;
        options.ResponseType = "code";
        options.ResponseMode = "query";
        options.SaveTokens = true;
    });
//

var logger = new LoggerConfiguration()
    .ReadFrom.Configuration(builder.Configuration)
    .CreateLogger();


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

app.UseAuthentication();
app.UseAuthorization();
app.UseSession();

app.MapRazorPages().RequireAuthorization();

app.UseMiddleware<LoggingMiddleware>(logger);

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();
