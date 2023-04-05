using _153505_Savonchik.ApplicationServices.Abstractions;
using _153505_Savonchik.Domain.Abstractions;
using _153505_Savonchik.Domain.Entities;

namespace _153505_Savonchik.ApplicationServices.Services
{
    public class WorkService : IWorkService
    {
        IUnitOfWork _unitOfWork;
        public WorkService(IUnitOfWork unitOfWork) 
        {
            _unitOfWork = unitOfWork;
        }

        public Task AddAsync(Work item)
        {
            return _unitOfWork.WorkRepository.AddAsync(item);
        }

        public async Task DeleteAsync(int id)
        {
            var work = await this.GetByIdAsync(id);

            if(work != null)
            {
                await _unitOfWork.WorkRepository.DeleteAsync(work);
            }
        }

        public Task DeleteAsync(Work item)
        {
            return _unitOfWork.WorkRepository.DeleteAsync(item);
        }

        public async Task<IReadOnlyList<Work>> GetAllAsync()
        {
            return await _unitOfWork.WorkRepository.ListAllAsync(); 
        }

        public Task<Work> GetByIdAsync(int id)
        {
            return _unitOfWork.WorkRepository.GetByIdAsync(id);
        }

        public Task UpdateAsync(Work item)
        {
            return _unitOfWork.WorkRepository.UpdateAsync(item);
        }
    }
}
