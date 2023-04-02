using _153505_Savonchik.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153505_Savonchik.Domain.Abstractions
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
