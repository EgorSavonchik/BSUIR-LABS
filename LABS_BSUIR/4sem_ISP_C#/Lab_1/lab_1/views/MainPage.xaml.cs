using System.Data;
using System.Globalization;

namespace lab_1;

public partial class MainPage : ContentPage
{
	bool clear = false;
	Decimal memory;

	public MainPage()
	{
		InitializeComponent();

		this.memoryRecalButton.IsEnabled = false;
        this.memoryRecalButton.BackgroundColor = Microsoft.Maui.Graphics.Color.Parse("Silver");
    }

	private void OnNumberButtonClicked(object sender, EventArgs e)
	{
		Button button = (Button)sender;

        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;
        }

        if (this.currentLabel.Text == "0")
		{
            this.currentLabel.Text = button.Text;
        }
		else
		{
            this.currentLabel.Text += button.Text;
        }
	}

	private void OnArithmeticButtonClicked(object sender, EventArgs e)
	{
        Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture("en-GB");

        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        Button button = (Button)sender;

        this.memoryLabel.Text += this.currentLabel.Text;

        if (this.memoryLabel.Text.Contains('='))
		{
			this.memoryLabel.Text = this.currentLabel.Text;
		}
		
		if(this.memoryLabel.Text.Contains('+') || this.memoryLabel.Text.Contains('-') || this.memoryLabel.Text.Contains('/')
			|| this.memoryLabel.Text.Contains('*'))
		{
            if (this.memoryLabel.Text.Contains('/') && this.currentLabel.Text == "0")
            {
                this.currentLabel.Text = "divide by zero";

                clear = true;
                return;
            }

            DataTable dataTable = new DataTable();

            this.currentLabel.Text = dataTable.Compute(this.memoryLabel.Text, null).ToString();
            this.memoryLabel.Text = dataTable.Compute(this.memoryLabel.Text, null).ToString();
        }

		this.memoryLabel.Text += button.Text;
		clear = true;
	}

	private void OnEqualsButtonClicked(object sender, EventArgs e)
	{
        Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture("en-GB");

        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        Button button = (Button)sender;
        DataTable dataTable = new DataTable();

		if(this.memoryLabel.Text.Contains('/') && this.currentLabel.Text == "0")
		{
			this.currentLabel.Text = "divide by zero";

			clear = true;
			return;
		}

        if (this.memoryLabel.Text.Contains('=') && this.memoryLabel.Text.Contains('+') || this.memoryLabel.Text.Contains('-') || this.memoryLabel.Text.Contains('/')
            || this.memoryLabel.Text.Contains('*'))
        {
            char sign = ' ';

            if(this.memoryLabel.Text.Contains('+'))
            {
                sign = '+';
            }
            else if(this.memoryLabel.Text.Contains('-'))
            {
                sign = '-';
            }
            else if (this.memoryLabel.Text.Contains('/'))
            {
                sign = '/';
            }
            else if (this.memoryLabel.Text.Contains('*'))
            {
                sign = '*';
            }
            
            if(sign != ' ')
            {
                this.memoryLabel.Text = this.currentLabel.Text + this.memoryLabel.Text.Remove(0, this.memoryLabel.Text.LastIndexOf(sign));
			    this.memoryLabel.Text = this.memoryLabel.Text.Remove(this.memoryLabel.Text.Length - 1);
            }
            
        }
        else if(this.memoryLabel.Text.Contains('=') && !(this.memoryLabel.Text.Contains('+') || this.memoryLabel.Text.Contains('-') || this.memoryLabel.Text.Contains('/')
            || this.memoryLabel.Text.Contains('*')))
        {
            this.currentLabel.Text = this.memoryLabel.Text.Remove(this.memoryLabel.Text.Length - 1, 1);
            clear = true;

            return;
        }
		else
		{
            this.memoryLabel.Text += this.currentLabel.Text;
        }
		
        try
        {
            this.currentLabel.Text = dataTable.Compute(this.memoryLabel.Text, null).ToString();
        }
        catch
        {
            this.currentLabel.Text = "divide by zero";

            clear = true;
            return;
        }
		
        this.memoryLabel.Text += "=";

		clear = false;
	}

	private void OnClearButtonClicked(object sender, EventArgs e)
	{
		this.currentLabel.Text = "0";
		this.memoryLabel.Text = "";
	}

    private void OnChangeSignButtonClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        if (this.currentLabel.Text[0] == '-') 
		{
			this.currentLabel.Text = this.currentLabel.Text.Remove(0, 1);
		}
		else
		{
			this.currentLabel.Text = '-' + this.currentLabel.Text;
		}
    }

    private void OnReverseButtonClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        if(this.currentLabel.Text == "0")
        {
            this.currentLabel.Text = "divide by zero";

            clear = true;
            return;
        }

        this.currentLabel.Text = (1 / Convert.ToDouble(this.currentLabel.Text)).ToString();

        if(this.currentLabel.Text == "∞")
        {
            this.currentLabel.Text = "divide by zero";

            clear = true;
        }
    }

    private void OnSqrtButtonClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        if (Convert.ToDouble(this.currentLabel.Text) < 0)
		{
			this.currentLabel.Text = "uncorrect";
			clear= true;

			return;
		}

        this.currentLabel.Text = Math.Sqrt(Convert.ToDouble(this.currentLabel.Text)).ToString();
    }

    private void OnSqrButtonClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        decimal val = Convert.ToDecimal(this.currentLabel.Text);
        this.currentLabel.Text = (val * val).ToString();
    }

    private void OnSinButtonClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        this.currentLabel.Text = Convert.ToDecimal(Math.Sin(Convert.ToDouble(this.currentLabel.Text) / 180 * Math.PI)).ToString();
    }

    private void OnPercentButtonClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        this.currentLabel.Text = (Convert.ToDouble(this.currentLabel.Text) / 100).ToString();
    }

    private void OnClearCashButtonClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        this.currentLabel.Text = this.currentLabel.Text.Remove(this.currentLabel.Text.Length - 1);

		if(this.currentLabel.Text.Length == 0)
		{
			this.currentLabel.Text = "0";
		}
    }

    private void OnFractionalButtonClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        if (this.currentLabel.Text.Contains('.'))
		{
			return;
		}
		else
		{
			this.currentLabel.Text += ".";
		}
    }

    private void OnMemorySaveButtonClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        memory = Convert.ToDecimal(this.currentLabel.Text);

		this.memoryRecalButton.IsEnabled = true;
        this.memoryRecalButton.BackgroundColor = Microsoft.Maui.Graphics.Color.Parse("White");
    }

    private void OnMemoryClearClicked(object sender, EventArgs e)
    {
        memory = 0;

        this.memoryRecalButton.IsEnabled = false;
		this.memoryRecalButton.BackgroundColor = Microsoft.Maui.Graphics.Color.Parse("Silver");
    }

    private void OnMemoryRecalClicked(object sender, EventArgs e)
    {
        if (clear == true)
        {
            this.currentLabel.Text = "0";

            clear = false;

            return;
        }

        this.currentLabel.Text = memory.ToString();
    }
}



