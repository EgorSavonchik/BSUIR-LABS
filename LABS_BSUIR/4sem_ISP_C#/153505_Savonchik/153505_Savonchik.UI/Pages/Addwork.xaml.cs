using _153505_Savonchik.Domain.Entities;
using _153505_Savonchik.UI.ViewModels;

namespace _153505_Savonchik.UI.Pages;

public partial class AddWork : ContentPage
{
	public AddWork(BrigadesManagerViewModel brigadesManagerViewModel)
	{
		InitializeComponent();

		BindingContext = brigadesManagerViewModel;
	}

	public async void OnAddClicked(object sender, EventArgs e)
	{
		this.alertLabel.Text = "";

        Work work = new Work();

        work.Name = this.nameEntry.Text;
        work.Quality = Convert.ToInt32(this.qualityEntry.Text);
        work.Duration = Convert.ToInt32(this.durationEntry.Text);
		work.Description = this.descriptionEntry.Text;
		work.Payment = Convert.ToInt32(this.paymentEntry.Text);
		work.ImagePath = "blank.png";

		try
		{
			work.BrigadeId = ((BrigadesManagerViewModel)BindingContext).Brigades.ToList().First(el => el.Name == this.brigadeEntry.Text).Id;
		}
		catch 
		{
			this.alertLabel.Text = "Brigade not found";

			return;
		}
		
        await ((BrigadesManagerViewModel)BindingContext).AddWorkAsync(work);
    }
}