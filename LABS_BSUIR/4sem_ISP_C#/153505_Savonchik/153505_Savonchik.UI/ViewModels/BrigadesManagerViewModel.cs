using _153505_Savonchik.ApplicationServices.Abstractions;
using _153505_Savonchik.ApplicationServices.Services;
using _153505_Savonchik.Domain.Entities;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.Collections.ObjectModel;
using System.Diagnostics;

namespace _153505_Savonchik.UI.ViewModels
{
    public partial class BrigadesManagerViewModel : ObservableObject
    {
        private IBrigadeService _brigadeService;
        private IWorkService _workService;

        public BrigadesManagerViewModel(IBrigadeService brigadeService, IWorkService workService) 
        {
            _brigadeService = brigadeService;
            _workService = workService;
        }

        public ObservableCollection<Brigade> Brigades { get; set; } = new();
        public ObservableCollection<Work> Works { get; set; } = new(); 

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
