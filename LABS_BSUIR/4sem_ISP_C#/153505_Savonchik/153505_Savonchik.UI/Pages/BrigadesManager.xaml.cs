using _153505_Savonchik.UI.ViewModels;

namespace _153505_Savonchik.UI.Pages;

public partial class BrigadesManager : ContentPage
{
	public BrigadesManager(BrigadesManagerViewModel brigadesManagerViewModel)
	{
		InitializeComponent();
		
		this.BindingContext = brigadesManagerViewModel;		
	}

	public void OnLoadPage(object sender, EventArgs e)
	{
		brigadePicker.ItemsSource = ((BrigadesManagerViewModel) BindingContext).Brigades.Select(el => el.Name).ToList();
		this.brigadePicker.ItemsSource = this.brigadePicker.GetItemsAsArray();
    }
}