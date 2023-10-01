using _153505_Malihtorovich.Domain.Entities;
using _153505_Malihtorovich.UI.ViewModels;

namespace _153505_Malihtorovich.UI.Pages;

public partial class AddBrigade : ContentPage
{
	public AddBrigade(BrigadesManagerViewModel brigadesManagerViewModel)
	{
		InitializeComponent();

		BindingContext = brigadesManagerViewModel;
	}

	public async void OnAddClicked(object sender, EventArgs e)
	{
		Brigade br = new Brigade();

		br.Name = this.nameEntry.Text;
		br.NumberOfWorkers = Convert.ToInt32(this.numberOfWorkerEntry.Text);
		br.Works = new List<Work>();

		await ((BrigadesManagerViewModel) BindingContext).AddBrigadeAsync(br);
	}
}