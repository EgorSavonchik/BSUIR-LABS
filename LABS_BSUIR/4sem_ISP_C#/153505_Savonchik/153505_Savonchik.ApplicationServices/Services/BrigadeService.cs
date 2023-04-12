using _153505_Savonchik.ApplicationServices.Abstractions;
using _153505_Savonchik.Domain.Abstractions;
using _153505_Savonchik.Domain.Entities;
using System;
using System.Collections.Generic;
using System.Diagnostics;
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

        public async Task AddAsync(Brigade item)
        {
            await _unitOfWork.BrigadeRepository.AddAsync(item);

            await _unitOfWork.SaveAllAsync();
        }

        public async Task AddWorkByBrigade(int brigadeId, Work work)
        {
            var brigade = await _unitOfWork.BrigadeRepository.GetByIdAsync(brigadeId);
            brigade.Works.Add(work);
        }

        public Task DeleteAsync(int id)
        {
            return _unitOfWork.BrigadeRepository.DeleteAsync(this.GetByIdAsync(id).Result);
        }

        public Task DeleteAsync(Brigade item)
        {
            return _unitOfWork.BrigadeRepository.DeleteAsync(item);
        }

        public async Task<IReadOnlyList<Brigade>> GetAllAsync()
        {
            return await _unitOfWork.BrigadeRepository.ListAllAsync();
        }

        public Task<IReadOnlyList<Work>> GetAllWorksByBrigadeAsync(int id)
        {
            return _unitOfWork.WorkRepository.ListAsync(el => el.BrigadeId == id);
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
