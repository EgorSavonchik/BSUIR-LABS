using _153505_Savonchik.ApplicationServices.Abstractions;
using _153505_Savonchik.ApplicationServices.Services;
using _153505_Savonchik.Domain.Abstractions;
using _153505_Savonchik.Persistense.Repository;
using _153505_Savonchik.UI.Pages;
using _153505_Savonchik.UI.ViewModels;
using CommunityToolkit.Maui;

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
        //Services
		services.AddSingleton<IUnitOfWork, FakeUnitOfWork>();
        services.AddSingleton<IBrigadeService, BrigadeService>();
        services.AddSingleton<IWorkService, WorkService>();

        //Pages

        //ViewModels
        services.AddSingleton<BrigadesManagerViewModel>(); // не работает
    }
}
