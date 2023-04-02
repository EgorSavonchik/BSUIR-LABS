using _153505_Savonchik.Domain.Abstractions;
using _153505_Savonchik.Domain.Entities;
using System.Linq.Expressions;

namespace _153505_Savonchik.Persistense.Repository
{
    public class FakeWorkRepository : IRepository<Work>
    {
        List<Work> _list = new List<Work>();
        public FakeWorkRepository()
        {
            Random rand = new Random();

            for (int i = 1; i <= 2; i++)
            {
                for (int j = 0, k = 1; j < 10; j++, k++)
                {
                    _list.Add(new Work()
                    {
                        Id = k,
                        Name = $"Work {k}",
                        BrigadeId = i,
                        Quality = rand.Next() % 10,
                        Duration = i * 2,
                        Payment = i * 100
                    });
                }
            }
        }

        public Task AddAsync(Work entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task DeleteAsync(Work entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task<Work> FirstOrDefaultAsync(Expression<Func<Work, bool>> filter, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task<Work> GetByIdAsync(int id, CancellationToken cancellationToken = default, params Expression<Func<Work, object>>[]? includesProperties)
        {
            throw new NotImplementedException();
        }

        public Task<IReadOnlyList<Work>> ListAllAsync(CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public async Task<IReadOnlyList<Work>> ListAsync(Expression<Func<Work, bool>> filter, CancellationToken cancellationToken = default, 
            params Expression<Func<Work, object>>[]? includesProperties)
        {
            var data = _list.AsQueryable();
            return data.Where(filter).ToList();
        }

        public Task UpdateAsync(Work entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
    }
}
