using _153505_Malihtorovich.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153505_Malihtorovich.ApplicationServices.Abstractions
{
    public interface IBrigadeService : IBaseService<Brigade>
    {
        public Task<IReadOnlyList<Work>> GetAllWorksByBrigadeAsync(int id);
        public Task AddWorkByBrigade(int brigadeId, Work work);
    }
}
