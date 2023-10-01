
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace _153505_Malihtorovich.Domain.Entities
{
    public class Work : Entity
    {

        public int Quality { get; set; } // обязательное свойство
        //[NotNull]
        public int Duration { get; set; }
        public string? Description { get; set; }
        //[NotNull]
        public int Payment { get; set; }
        //[Indexed]
        [ForeignKey(nameof(Id))]
        public int BrigadeId { get; set; }
        public string? ImagePath { get; set; }
    }
}
