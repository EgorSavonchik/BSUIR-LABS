using lab_1.Services;
using lab_1.Entities;
using System.Diagnostics;

namespace lab_1;

public partial class APIDemoPage : ContentPage
{
	IRateService rateService;
	List<Rate> rates;
	DateTime dateTime = DateTime.Now;

    public APIDemoPage(IRateService rateService)
	{
		this.rateService = rateService;

		InitializeComponent();
	}

	public void OnLoadedPage(object sender, EventArgs e)
	{
		rates = rateService.GetRates(dateTime).ToList();

        this.TransferPicker.ItemsSource = rates.Select(o => o.Cur_Name).ToList();
        this.TransferPicker.ItemsSource = this.TransferPicker.GetItemsAsArray();

        this.ReverseTransferPicker.ItemsSource = rates.Select(o => o.Cur_Name).ToList();
        this.ReverseTransferPicker.ItemsSource = this.ReverseTransferPicker.GetItemsAsArray();

        this.Calendar.MaximumDate = DateTime.Now;
    }

	public void OnTransferButtonClicked(object sender, EventArgs e)
	{
        this.TransferOutLabel.Text = (Convert.ToInt32(this.EnterTransferEntry.Text) / rates[this.TransferPicker.SelectedIndex].Cur_OfficialRate 
			* rates[this.TransferPicker.SelectedIndex].Cur_Scale).ToString();
	}

	public void OnReverseTransferButtonClicked(object sender, EventArgs e) 
	{
        this.ReverseTransferOutLabel.Text = (Convert.ToInt32(this.EnterReverseTransferEntry.Text) * rates[this.ReverseTransferPicker.SelectedIndex].Cur_OfficialRate
			/ rates[this.ReverseTransferPicker.SelectedIndex].Cur_Scale).ToString();
    }

	public void OnDateSelected(object sender, EventArgs e) 
	{
		dateTime = this.Calendar.Date;

        rates = rateService.GetRates(dateTime).ToList();

        this.TransferPicker.ItemsSource = rates.Select(o => o.Cur_Name).ToList();
        this.TransferPicker.ItemsSource = this.TransferPicker.GetItemsAsArray();

        this.ReverseTransferPicker.ItemsSource = rates.Select(o => o.Cur_Name).ToList();
        this.ReverseTransferPicker.ItemsSource = this.ReverseTransferPicker.GetItemsAsArray();
    }
}