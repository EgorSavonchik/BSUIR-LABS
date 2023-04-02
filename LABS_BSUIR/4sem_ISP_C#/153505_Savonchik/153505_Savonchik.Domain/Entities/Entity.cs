using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153505_Savonchik.Domain.Entities
{
    public abstract class Entity
    {
        public int Id { get; set; }
        public string Name { get; set; }
    }
}
