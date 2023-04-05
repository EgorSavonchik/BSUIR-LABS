using _153505_Savonchik.Domain.Entities;
using _153505_Savonchik.UI.ValueConverters;
using _153505_Savonchik.UI.ViewModels;
using System.Diagnostics;

namespace _153505_Savonchik.UI.Pages;

public partial class BrigadesManager : ContentPage
{
	BrigadesManagerViewModel _viewModel;
	public BrigadesManager(BrigadesManagerViewModel brigadesManagerViewModel)
	{
		InitializeComponent();

        _viewModel = brigadesManagerViewModel;
        
        //brigadeStateLabel.BindingContext = _viewModel.SelectedBrigade;
        //brigadeStateLabel.SetBinding(Label.TextProperty, "NumberOfWorkers");

        //this.worksView.ItemTemplate = new DataTemplate(() =>
        //{
        //    var nameLabel = new Label { FontSize = 20, TextColor = Color.FromArgb("#006064"), Margin = 10 };
        //    nameLabel.SetBinding(Label.TextProperty, "Name");
        //    nameLabel.SetBinding(Label.BackgroundColorProperty, "Quality", converter: new QualityToColorValueConverter());

        //    return new StackLayout
        //    {
        //        Children = { nameLabel },
        //        Margin = new Thickness(15, 10)
        //    };
        //});

        this.BindingContext = brigadesManagerViewModel;		
	}

	public void OnBrigadeIndexChanged(object sender, EventArgs e)
	{
		//_viewModel.SelectedBrigade = (Brigade) brigadePicker.SelectedItem;
	}
}