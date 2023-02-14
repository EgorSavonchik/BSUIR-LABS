using lab_1.Entities;
using lab_1.Services;
using Microsoft.Maui;

namespace lab_1;

public partial class SQLiteDBpage : ContentPage
{
    IDbService db;

	public SQLiteDBpage(IDbService db)
	{
		this.db = db;

		InitializeComponent();
	}

	public void OnSelectedIndexChanged(object sender, EventArgs e)
	{
        resultBox.ItemsSource = db.GetWorks(this.Picker.SelectedIndex + 1).Select(o => o.Name).ToArray();
	}

    public void OnLoadPage(object sender, EventArgs e)
    {
        //db.Init();

        List<Brigada> brigados = db.GetAllBrigades().ToList();
        List<string> Names = new List<string>();

        for (int i = 0; i < brigados.Count; i++)
        {
            Names.Add(brigados[i].Name);
        }

        this.Picker.ItemsSource = Names;
        this.Picker.ItemsSource = this.Picker.GetItemsAsArray();
    }
}