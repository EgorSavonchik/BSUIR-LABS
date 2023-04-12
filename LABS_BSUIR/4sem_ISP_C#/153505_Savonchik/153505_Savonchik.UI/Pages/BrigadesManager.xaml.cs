using _153505_Savonchik.UI.ViewModels;

namespace _153505_Savonchik.UI.Pages;

public partial class BrigadesManager : ContentPage
{
	public BrigadesManager(BrigadesManagerViewModel brigadesManagerViewModel)
	{
		InitializeComponent();

        this.BindingContext = brigadesManagerViewModel;		
	}
}