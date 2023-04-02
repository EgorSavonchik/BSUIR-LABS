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
            return _unitOfWork.WorkRepository.AddAsync(item); // спросить имеет ли это смысл или убрать аваэйт и ретурт и возвращать просто таск
        }

        public Task DeleteAsync(int id)
        {
            return _unitOfWork.WorkRepository.DeleteAsync(this.GetByIdAsync(id).Result); // имеет ли смысл тут авэйт
        }

        public Task DeleteAsync(Work item)
        {
            return _unitOfWork.WorkRepository.DeleteAsync(item);
        }

        public Task<IReadOnlyList<Work>> GetAllAsync()
        {
            return _unitOfWork.WorkRepository.ListAllAsync(); // имеет ли смысл добавлять асинк и авэйт, в вызываемом методе и так дожидаемся выполнения? или нет
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
