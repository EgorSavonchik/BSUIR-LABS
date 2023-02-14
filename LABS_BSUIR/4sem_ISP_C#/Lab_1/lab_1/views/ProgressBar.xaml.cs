using System.Threading;

namespace lab_1;

public partial class ProgressBar : ContentPage
{
    static CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();

	public ProgressBar()
	{
		InitializeComponent();
	}

    private async void OnStartButtonClicked(object sender, EventArgs e)
    {
        if(!cancellationTokenSource.IsCancellationRequested)
        {
            cancellationTokenSource.Cancel();
        }
        
        cancellationTokenSource = new CancellationTokenSource();
        this.StateHeadLabel.Text = "Computing";

        Task task = Task.Run(() => {
            CalculateIntegral(cancellationTokenSource.Token);
            });

        await task;
    }

    private void OnCancelButtonClicked(object sender, EventArgs e)
    {
        if(this.StateHeadLabel.Text != "Computing")
        {
            return;
        }
        
        cancellationTokenSource.Cancel();

        this.PercentLabel.Text = "0%";
        this.StateHeadLabel.Text = "Job canceled";
    }

    private void CalculateIntegral(CancellationToken token)
    {
        double integral = 0;
        int temp;

        for(double i = 0; i <= 1; i += 0.00001) // убрал 3 ноля
        {
            integral += Math.Sin(i) * 0.00001;

            Device.BeginInvokeOnMainThread(() =>
            {
                this.ProgressBarIndicator.Progress = i;
                this.PercentLabel.Text = (Math.Round(i * 100)).ToString() + "%";
            });

            if(token.IsCancellationRequested)
            {
                return;
            }

            for (int j = 0; j < 100; j++) //  убрал 3 нуля
            {
                temp = 5 * 7;
            }
        }

        Device.BeginInvokeOnMainThread(() =>
        {
            this.StateHeadLabel.Text = integral.ToString();
        });
    }
}