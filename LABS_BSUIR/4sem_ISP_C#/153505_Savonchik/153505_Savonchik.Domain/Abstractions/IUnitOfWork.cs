using _153505_Malihtorovich.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153505_Malihtorovich.Domain.Abstractions
{
    public interface IUnitOfWork
    {
        IRepository<Brigade> BrigadeRepository { get; }
        IRepository<Work> WorkRepository { get; }
        public Task RemoveDatbaseAsync();
        public Task CreateDatabaseAsync();
        public Task SaveAllAsync();
    }

}
