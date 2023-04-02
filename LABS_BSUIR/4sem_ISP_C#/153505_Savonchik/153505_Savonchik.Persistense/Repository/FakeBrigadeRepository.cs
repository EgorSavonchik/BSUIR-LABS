using _153505_Savonchik.Domain.Abstractions;
using _153505_Savonchik.Domain.Entities;
using System.Linq.Expressions;

namespace _153505_Savonchik.Persistense.Repository
{
    public class FakeBrigadeRepository : IRepository<Brigade>
    {
        List<Brigade> _brigades;
        public FakeBrigadeRepository()
        {
            _brigades = new List<Brigade>() 
            { 
                new Brigade()
                { 
                    Id=1, Name="Бригада Савончика", NumberOfWorkers = 3, Works = new List<Work>()
                }, 
                new Brigade() 
                {
                    Id=2, Name="<Бригада Косьмина", NumberOfWorkers = 5, Works = new List<Work>() 
                }
            };
        }
        public Task AddAsync(Brigade entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task DeleteAsync(Brigade entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task<Brigade> FirstOrDefaultAsync(Expression<Func<Brigade, bool>> filter, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task<Brigade> GetByIdAsync(int id, CancellationToken cancellationToken = default, params Expression<Func<Brigade, object>>[]? includesProperties)
        {
            throw new NotImplementedException();
        }

        public async Task<IReadOnlyList<Brigade>> ListAllAsync(CancellationToken cancellationToken = default)
        {
            return await Task.Run(() => _brigades);
        }

        public Task<IReadOnlyList<Brigade>> ListAsync(Expression<Func<Brigade, bool>> filter, CancellationToken cancellationToken = default, params Expression<Func<Brigade, object>>[]? includesProperties)
        {
            throw new NotImplementedException();
        }

        public Task UpdateAsync(Brigade entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
    }
}
