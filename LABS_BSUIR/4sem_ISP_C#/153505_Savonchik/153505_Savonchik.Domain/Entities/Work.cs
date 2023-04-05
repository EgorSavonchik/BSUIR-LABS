using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153505_Savonchik.Domain.Entities
{
    //[Table("Works")]
    public class Work : Entity
    {
        //[PrimaryKey, AutoIncrement, Indexed]
        //[Column("Id")]
        //public int WorkId { get; set; }
        //public string Name { get; set; }
        //[NotNull]
        public int Quality { get; set; } // обязательное свойство
        //[NotNull]
        public int Duration { get; set; }
        public string Description { get; set; }
        //[NotNull]
        public int Payment { get; set; }
        //[Indexed]
        public int BrigadeId { get; set; }
    }
}
