using lab_1.Entities;
using SQLite;


namespace lab_1.Services
{
    public class SQLiteService : IDbService
    {
        SQLiteConnection Brigades = new SQLiteConnection("C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\4sem_ISP_C#\\Lab_1\\Brigades.db");
        SQLiteConnection Works = new SQLiteConnection("C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\4sem_ISP_C#\\Lab_1\\Works.db");

        public IEnumerable<Brigada> GetAllBrigades()
        {
            return Brigades.Table<Brigada>();
        }

        public IEnumerable<Work> GetWorks(int id)
        {
            return Works.Query<Work>("SELECT * FROM Works WHERE Works.BrigadaId = ?", id);
        }

        public void Init()
        {
            /*using (var conn = new SQLiteConnection("Storage.db"))
            {
                conn.Execute("CREATE TABLE Brigades " +
                    "(" +
                        "Id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," +
                        "Name VARCHAR(50)," +
                        "Workers INTEGER" +
                    ");");

                conn.Execute("CREATE TABLE Works " +
                    "(" +
                        "Id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," +
                        "Name VARCHAR(50)," +
                        "Description VARCHAR(50)," +
                        "Duration INTEGER," +
                        "BrigadaId INTEGER FOREIGN KEY" +
                    ");");

                
            }*/
            Brigades.CreateTable<Brigada>();
            Works.CreateTable<Work>();

            Brigades.Insert(new Brigada("FirstBrigada", 30));
            Brigades.Insert(new Brigada("SecondBrigada", 50));
            Brigades.Insert(new Brigada("ThirdBrigada", 10));


            Works.Insert(new Work("FirstWork", "bad", 1, 10));
            Works.Insert(new Work("SecondWork", "good", 1, 100));
            Works.Insert(new Work("ThirdWork", "neutral", 1, 23));
            Works.Insert(new Work("Rabota", "bad", 2, 50));
            Works.Insert(new Work("Trud", "normal", 2, 20));
        }
    }
}
