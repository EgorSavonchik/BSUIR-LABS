using _153505_Savonchik.ApplicationServices.Abstractions;
using _153505_Savonchik.ApplicationServices.Services;
using _153505_Savonchik.Domain.Abstractions;
using _153505_Savonchik.Persistense.Data;
using _153505_Savonchik.Persistense.Repository;
using _153505_Savonchik.UI.Pages;
using _153505_Savonchik.UI.ViewModels;
using CommunityToolkit.Maui;
using Microsoft.EntityFrameworkCore;

namespace _153505_Savonchik.UI;

public static class MauiProgram
{
	public static MauiApp CreateMauiApp()
	{
		var builder = MauiApp.CreateBuilder();
		builder
			.UseMauiApp<App>()
			.ConfigureFonts(fonts =>
			{
				fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
				fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
			});

		builder.UseMauiApp<App>().UseMauiCommunityToolkit(); // спросить про странные варнинги
		SetupServices(builder.Services);

		return builder.Build();
	}

    private static void SetupServices(IServiceCollection services)
    {
		var dataPath = Path.Combine(FileSystem.Current.AppDataDirectory, "Savonchik.db");
			
		//Services
		services.AddDbContext<AppDbContext>(opt=>opt.UseSqlite($"Data Source = {dataPath}"));
		services.AddSingleton<IUnitOfWork, FakeUnitOfWork>();
        services.AddSingleton<IBrigadeService, BrigadeService>();
        services.AddSingleton<IWorkService, WorkService>();

		//Pages

		services.AddSingleton<BrigadesManager>();

        //ViewModels
        services.AddSingleton<BrigadesManagerViewModel>(); 
    }
}
