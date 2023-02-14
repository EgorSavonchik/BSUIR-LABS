using SQLite;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_1.Entities
{
    [Table("Brigades")]
    public class Brigada
    {
        [PrimaryKey, Indexed, AutoIncrement]
        public int Id { get; set; }
        public string Name { get; set; }
        public int Workers { get; set; }

        public Brigada() 
        {
        
        }

        public Brigada(string name, int workers)
        {
            Name = name;
            Workers = workers;
        }
    }
}
