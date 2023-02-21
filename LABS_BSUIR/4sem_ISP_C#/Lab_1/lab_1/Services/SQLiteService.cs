using lab_1.Entities;
using SQLite;


namespace lab_1.Services
{
    public class SQLiteService : IDbService
    {
        SQLiteConnection db = new SQLiteConnection(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), @"database.db"));
        
        
        public IEnumerable<Brigada> GetAllBrigades()
        {
            return db.Table<Brigada>();
        }

        public IEnumerable<Work> GetWorks(int id)
        {
            return db.Query<Work>("SELECT * FROM Works WHERE Works.BrigadaId = ?", id);
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
            db.DropTable<Brigada>();
            db.DropTable<Work>();

            db.CreateTable<Brigada>();
            db.CreateTable<Work>();

            db.Insert(new Brigada("FirstBrigada", 30));
            db.Insert(new Brigada("SecondBrigada", 50));
            db.Insert(new Brigada("ThirdBrigada", 10));


            db.Insert(new Work("FirstWork", "bad", 1, 10));
            db.Insert(new Work("SecondWork", "good", 1, 100));
            db.Insert(new Work("ThirdWork", "neutral", 1, 23));
            db.Insert(new Work("Rabota", "bad", 2, 50));
            db.Insert(new Work("Trud", "normal", 2, 20));
        }
    }
}
