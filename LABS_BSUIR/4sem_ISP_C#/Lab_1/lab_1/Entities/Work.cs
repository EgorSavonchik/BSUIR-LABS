using SQLite;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_1.Entities
{
    [Table("Works")]
    public class Work
    {
        [PrimaryKey, Indexed, AutoIncrement]
        [Column("Id")]
        public int WorkId { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        [Indexed]
        public int BrigadaId { get; set; }
        public int  Duration { get; set; }

        public Work() 
        {
        
        }

        public Work(string name, string description, int brigadaId, int duration)
        {
            Name = name;
            Description = description;
            BrigadaId = brigadaId;
            Duration = duration;
        }
    }
}
