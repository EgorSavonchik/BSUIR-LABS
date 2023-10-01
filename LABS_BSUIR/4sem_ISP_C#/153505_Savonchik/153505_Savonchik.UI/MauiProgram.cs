using _153505_Malihtorovich.ApplicationServices.Abstractions;
using _153505_Malihtorovich.ApplicationServices.Services;
using _153505_Malihtorovich.Domain.Abstractions;
using _153505_Malihtorovich.Domain.Entities;
using _153505_Malihtorovich.Persistense.Data;
using _153505_Malihtorovich.Persistense.Repository;
using _153505_Malihtorovich.UI.Pages;
using _153505_Malihtorovich.UI.ViewModels;
using CommunityToolkit.Maui;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using System.Reflection;

namespace _153505_Malihtorovich.UI;

public static class MauiProgram
{
    public static MauiApp CreateMauiApp()
	{
		string settingsStream = "_153505_Malihtorovich.UI.appsettings.json";

        var builder = MauiApp.CreateBuilder();
		builder
			.UseMauiApp<App>()
			.ConfigureFonts(fonts =>
			{
				fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
				fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
			});

        var a = Assembly.GetExecutingAssembly(); // получаем сборку, которая содержит выполняемый в текущий момент код.
        using var stream = a.GetManifestResourceStream(settingsStream); // встраимваем файлик
        builder.Configuration.AddJsonStream(stream); // спросить зачем встраивать его тут то, если он и так в проекте

		builder.UseMauiApp<App>().UseMauiCommunityToolkit(); // спросить про странные варнинги
		SetupServices(builder.Services);   // added services
        AddDbContext(builder);
        SeedData(builder.Services);

        return builder.Build();
	}

    private static void SetupServices(IServiceCollection services)
    {		
		//Services
		services.AddScoped<IUnitOfWork, EfUnitOfWork>();
        services.AddScoped<IBrigadeService, BrigadeService>();
        services.AddScoped<IWorkService, WorkService>();

		//Pages
		services.AddSingleton<BrigadesManager>();
        services.AddTransient<WorkDetails>();
        services.AddSingleton<AddBrigade>();
        services.AddSingleton<AddWork>();
        services.AddTransient<EditWork>();

        //ViewModels
        services.AddSingleton<BrigadesManagerViewModel>();
        services.AddTransient<WorkDetailsViewModel>();
        services.AddTransient<WorkEditViewModel>();
    }

    private static void AddDbContext(MauiAppBuilder builder)
    {
        var connStr = builder.Configuration.GetConnectionString("SqliteConnection");
        string dataDirectory = String.Empty;
        
        #if ANDROID
            dataDirectory = FileSystem.AppDataDirectory+"/";
        #endif
        
        connStr = String.Format(connStr, dataDirectory);

        var options = new DbContextOptionsBuilder<AppDbContext>()
            .UseSqlite(connStr)
            //.UseQueryTrackingBehavior(QueryTrackingBehavior.NoTracking) //
            .Options;

        builder.Services.AddSingleton<AppDbContext>((s) => new AppDbContext(options));
    }

    public async static void SeedData(IServiceCollection services)
    {
        using var provider = services.BuildServiceProvider();
        var unitOfWork = provider.GetService<IUnitOfWork>();
        
        await unitOfWork.RemoveDatbaseAsync();
        await unitOfWork.CreateDatabaseAsync();
        
        // Add brigades
        IReadOnlyList<Brigade> brigades = new List<Brigade>()
        {
            new Brigade(){ Name="Бригада 1", NumberOfWorkers = 3 },
            new Brigade(){ Name="Бригада 2", NumberOfWorkers = 15 },
            new Brigade(){ Name="Бригада 3", NumberOfWorkers = 10 }
        };
        
        foreach (var brigade in brigades)
            await unitOfWork.BrigadeRepository.AddAsync(brigade);
        
        await unitOfWork.SaveAllAsync();
        
        //Add works
        Random rand = new Random();

        int k = 1;
        foreach (var brigade in brigades)
            for (int j = 0; j < 10; j++)
            {
                await unitOfWork.WorkRepository.AddAsync(new Work()
                {
                    Name = $"Work {k++}",
                    Quality = rand.Next(0, 100) / 10,
                    BrigadeId = brigade.Id,
                    Duration = rand.Next(0, 100) * 5,
                    Description = brigade.Name + " work",
                    Payment = rand.Next(0, 100) * 10,
                    ImagePath = $"pic{k - 1}.jpg"
                });
            }

        await unitOfWork.SaveAllAsync();
    }
}
