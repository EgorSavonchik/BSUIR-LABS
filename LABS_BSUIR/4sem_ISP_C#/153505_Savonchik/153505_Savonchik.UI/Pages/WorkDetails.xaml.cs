using _153505_Savonchik.UI.ViewModels;

namespace _153505_Savonchik.UI.Pages;



public partial class WorkDetails : ContentPage
{
    public WorkDetails(WorkDetailsViewModel workDetailsViewModel)
    {
        InitializeComponent();

        this.BindingContext = workDetailsViewModel;
    }

    public void OnLoadPage(object sender, EventArgs e)
    {
        this.nameLabel.Text = "Name: " + ((WorkDetailsViewModel)BindingContext).SelectedWork.Name;
        this.desriptionLabel.Text = "Description: " + ((WorkDetailsViewModel)BindingContext).SelectedWork.Description;
        this.paymentLabel.Text = "Payment: " + ((WorkDetailsViewModel)BindingContext).SelectedWork.Payment.ToString();
        this.qualityLabel.Text = "Quality: " + ((WorkDetailsViewModel)BindingContext).SelectedWork.Quality.ToString();
        this.image.Source = ((WorkDetailsViewModel)BindingContext).SelectedWork.ImagePath; //ImageSource.FromFile(((WorkDetailsViewModel)BindingContext).SelectedWork.imagePath);
        this.durationLabel.Text = ((WorkDetailsViewModel)BindingContext).SelectedWork.Duration.ToString();
    }
}