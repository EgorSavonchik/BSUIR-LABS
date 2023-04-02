using _153505_Savonchik.ApplicationServices.Services;
using _153505_Savonchik.Domain.Entities;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.Collections.ObjectModel;

namespace _153505_Savonchik.UI.ViewModels
{
    public partial class BrigadesManagerViewModel : ObservableObject
    {
        private BrigadeService _brigadeService;
        private WorkService _workService;

        public BrigadesManagerViewModel(BrigadeService brigadeService, WorkService workService) 
        {
            _brigadeService = brigadeService;
            _workService = workService;
        }

        public ObservableCollection<Brigade> Brigades { get; set; } = new();
        public ObservableCollection<Work> Works { get; set; } = new(); // зачем нью елси можно сослать на лист из сервиса

        [ObservableProperty]
        Brigade selectedBrigade;

        [RelayCommand]
        public async void UpdateGroupList() => await GetBrigades();
        [RelayCommand]
        public async void UpdateMembersList() => await GetWorks();

        public async Task GetBrigades()
        {
            var brigades = await _brigadeService.GetAllAsync();

            await MainThread.InvokeOnMainThreadAsync(() =>
            {
                Brigades.Clear();
                foreach (Brigade brigade in brigades)
                    Brigades.Add(brigade);
            });
        }
        public async Task GetWorks()
        {
            var works = await _brigadeService.GetAllWorksByBrigadeAsync(SelectedBrigade.Id);

            await MainThread.InvokeOnMainThreadAsync(() =>
            {
                Works.Clear();
                foreach (Work work in works)
                    Works.Add(work);
            });
        }
    }
}
