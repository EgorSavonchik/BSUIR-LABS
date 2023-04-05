using _153505_Savonchik.Domain.Abstractions;
using _153505_Savonchik.Domain.Entities;
using _153505_Savonchik.Persistense.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153505_Savonchik.Persistense.Repository
{
    public class FakeUnitOfWork : IUnitOfWork
    {
        private readonly AppDbContext _context;
        private readonly Lazy<IRepository<Brigade>> _brigadeRepository;
        private readonly Lazy<IRepository<Work>> _workRepository;

        public FakeUnitOfWork(AppDbContext context)
        {
            _context = context;
            _brigadeRepository = new Lazy<IRepository<Brigade>>(() => new FakeBrigadeRepository());
            _workRepository = new Lazy<IRepository<Work>>(() => new FakeWorkRepository());
        }

        IRepository<Brigade> IUnitOfWork.BrigadeRepository => _brigadeRepository.Value;
        IRepository<Work> IUnitOfWork.WorkRepository => _workRepository.Value;
        public async Task CreateDatabaseAsync()
        {
            await _context.Database.EnsureCreatedAsync();
        }
        public async Task RemoveDatbaseAsync()
        {
            await _context.Database.EnsureDeletedAsync();
        }
        public async Task SaveAllAsync()
        {
            await _context.SaveChangesAsync();
        }
    }
}
