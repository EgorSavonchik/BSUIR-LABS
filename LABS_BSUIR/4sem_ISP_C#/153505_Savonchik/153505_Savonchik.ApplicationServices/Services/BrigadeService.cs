using _153505_Savonchik.ApplicationServices.Abstractions;
using _153505_Savonchik.Domain.Abstractions;
using _153505_Savonchik.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153505_Savonchik.ApplicationServices.Services
{
    public class BrigadeService : IBrigadeService
    {
        IUnitOfWork _unitOfWork;

        public BrigadeService(IUnitOfWork unitOfWork) 
        { 
            _unitOfWork = unitOfWork;
        }

        public Task AddAsync(Brigade item)
        {
            return _unitOfWork.BrigadeRepository.AddAsync(item);
        }

        public Task AddWorkByBrigade(int brigadeId, Work work)
        {
            _unitOfWork.BrigadeRepository.GetByIdAsync(brigadeId).Result.Works.Add(work); // правильно ли??

            return Task.CompletedTask;
        }

        public Task DeleteAsync(int id)
        {
            return _unitOfWork.BrigadeRepository.DeleteAsync(this.GetByIdAsync(id).Result);
        }

        public Task DeleteAsync(Brigade item)
        {
            return _unitOfWork.BrigadeRepository.DeleteAsync(item);
        }

        public Task<IReadOnlyList<Brigade>> GetAllAsync()
        {
            return _unitOfWork.BrigadeRepository.ListAllAsync();
        }

        public Task<IReadOnlyList<Work>> GetAllWorksByBrigadeAsync(int id)
        {
            return _unitOfWork.WorkRepository.ListAsync(el => el.Id == id);
        }

        public Task<Brigade> GetByIdAsync(int id)
        {
            return _unitOfWork.BrigadeRepository.GetByIdAsync(id);
        }

        public Task UpdateAsync(Brigade item)
        {
            return _unitOfWork.BrigadeRepository.UpdateAsync(item);
        }
    }
}
