using _153505_Savonchik.UI.Pages;

namespace _153505_Savonchik.UI;

public partial class AppShell : Shell
{
	public AppShell()
	{
		InitializeComponent();

		Routing.RegisterRoute(nameof(WorkDetails), typeof(WorkDetails));
        Routing.RegisterRoute(nameof(AddWork), typeof(AddWork));
        Routing.RegisterRoute(nameof(AddBrigade), typeof(AddBrigade));
        Routing.RegisterRoute(nameof(BrigadesManager), typeof(BrigadesManager));
        Routing.RegisterRoute(nameof(EditWork), typeof(EditWork));
    }
}
