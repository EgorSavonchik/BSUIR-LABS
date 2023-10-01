using _153505_Malihtorovich.ApplicationServices.Abstractions;
using _153505_Malihtorovich.Domain.Abstractions;
using _153505_Malihtorovich.Domain.Entities;

namespace _153505_Malihtorovich.ApplicationServices.Services
{
    public class WorkService : IWorkService
    {
        IUnitOfWork _unitOfWork;
        public WorkService(IUnitOfWork unitOfWork) 
        {
            _unitOfWork = unitOfWork;
        }

        public async Task AddAsync(Work item)
        {
            await _unitOfWork.WorkRepository.AddAsync(item);
            await _unitOfWork.SaveAllAsync();
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

        public async Task UpdateAsync(Work item)
        {
            await _unitOfWork.WorkRepository.UpdateAsync(item);

            await _unitOfWork.SaveAllAsync();
        }
    }
}
