using _153505_Malihtorovich.UI.ViewModels;

namespace _153505_Malihtorovich.UI.Pages;

public partial class EditWork : ContentPage
{
	BrigadesManagerViewModel brigadesManagerViewModel;

	public EditWork(WorkEditViewModel workEditViewModel, BrigadesManagerViewModel brigadesManagerViewModel)
	{
		InitializeComponent();

		this.brigadesManagerViewModel = brigadesManagerViewModel;
		BindingContext = workEditViewModel;
	}

	public async void OnLoadedPage(object sender, EventArgs e)
	{
		this.nameEntry.Text = ((WorkEditViewModel) BindingContext).SelectedWork.Name;
		this.qualityEntry.Text = ((WorkEditViewModel)BindingContext).SelectedWork.Quality.ToString();
		this.paymentEntry.Text = ((WorkEditViewModel)BindingContext).SelectedWork.Payment.ToString();
		this.descriptionEntry.Text = ((WorkEditViewModel)BindingContext).SelectedWork.Description.ToString();
		this.durationEntry.Text = ((WorkEditViewModel)BindingContext).SelectedWork.Duration.ToString();
		this.brigadeEntry.Text = (await ((WorkEditViewModel)BindingContext).brigadeService
			.GetByIdAsync(((WorkEditViewModel)BindingContext).SelectedWork.BrigadeId)).Name;
    }

	public async void OnUpdateClicked(object sender, EventArgs e)
	{
		this.alertLabel.Text = "";

        ((WorkEditViewModel)BindingContext).SelectedWork.Name = this.nameEntry.Text;
        ((WorkEditViewModel)BindingContext).SelectedWork.Quality = Convert.ToInt32(this.qualityEntry.Text);
        ((WorkEditViewModel)BindingContext).SelectedWork.Payment = Convert.ToInt32(this.paymentEntry.Text);
        ((WorkEditViewModel)BindingContext).SelectedWork.Description = this.descriptionEntry.Text;
        ((WorkEditViewModel)BindingContext).SelectedWork.Duration = Convert.ToInt32(this.durationEntry.Text);
		
		try
		{
			((WorkEditViewModel)BindingContext).SelectedWork.BrigadeId = (await ((WorkEditViewModel)BindingContext)
				.brigadeService.GetAllAsync()).Where(el => el.Name == this.brigadeEntry.Text).First().Id;
		}
		catch 
		{
            this.alertLabel.Text = "Brigade not found";

            return;
        }
		
        await brigadesManagerViewModel.UpdateWorkAsync(((WorkEditViewModel)BindingContext).SelectedWork);
    }
}