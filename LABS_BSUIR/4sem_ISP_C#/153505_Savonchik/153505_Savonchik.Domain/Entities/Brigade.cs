

using Microsoft.EntityFrameworkCore.Storage.ValueConversion;
using System.Runtime.CompilerServices;

namespace _153505_Malihtorovich.Domain.Entities
{
    //[Table("Brigades")]
    public class Brigade : Entity
    {
        //[PrimaryKey, AutoIncrement, Indexed]
        //public int Id { get; set; }
        //public string Name { get; set; }
        public int NumberOfWorkers { get; set; }
        public List<Work>? Works { get; set; }
    }
}
