using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153505_Savonchik.Domain.Entities
{
    //[Table("Brigades")]
    public class Brigade : Entity
    {
        //[PrimaryKey, AutoIncrement, Indexed]
        //public int Id { get; set; }
        //public string Name { get; set; }
        public int NumberOfWorkers { get; set; }
        public List<Work> Works { get; set; }
    }
}
