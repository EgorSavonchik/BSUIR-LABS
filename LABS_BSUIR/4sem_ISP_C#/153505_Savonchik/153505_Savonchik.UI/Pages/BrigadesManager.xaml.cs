using _153505_Malihtorovich.UI.ViewModels;

namespace _153505_Malihtorovich.UI.Pages;

public partial class BrigadesManager : ContentPage
{
	public BrigadesManager(BrigadesManagerViewModel brigadesManagerViewModel)
	{
		InitializeComponent();

        this.BindingContext = brigadesManagerViewModel;		
	}
}