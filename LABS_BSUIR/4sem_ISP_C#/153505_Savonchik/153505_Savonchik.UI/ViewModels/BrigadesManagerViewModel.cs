using _153505_Savonchik.ApplicationServices.Abstractions;
using _153505_Savonchik.Domain.Entities;
using _153505_Savonchik.UI.Pages;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System.Collections.ObjectModel;

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

        [RelayCommand]
        public async void ShowDetails(Work work) => await GotoDetailsPage(work);

        private async Task GotoDetailsPage(Work work)
        {
            IDictionary<string, object> parameters = new Dictionary<string, object>
            {
                { "Work", work }
            };

            await Shell.Current.GoToAsync(nameof(WorkDetails), parameters);//($"{nameof(WorkDetails)}?Work={work}");
        }

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

        [RelayCommand]
        public async void AddWork() => await GotoAddWork();

        public async Task GotoAddWork()
        {
            await Shell.Current.GoToAsync(nameof(AddWork));
        }

        [RelayCommand]
        public async void AddBrigade() => await GotoAddBrigade();

        public async Task GotoAddBrigade()
        {
            await Shell.Current.GoToAsync(nameof(AddBrigade));
        }

        public async Task AddBrigadeAsync(Brigade br)
        {
            await _brigadeService.AddAsync(br);

            SelectedBrigade ??= new Brigade();
            
            UpdateGroupList();

            await Shell.Current.GoToAsync(nameof(BrigadesManager));
        }
        
        public async Task AddWorkAsync(Work work)
        {
            await _workService.AddAsync(work);

            SelectedBrigade ??= new Brigade();

            UpdateMembersList();

            await Shell.Current.GoToAsync(nameof(BrigadesManager));
        }

        public async Task UpdateWorkAsync(Work work)
        {
            await _workService.UpdateAsync(work);

            SelectedBrigade ??= new Brigade();

            UpdateMembersList();

            await Shell.Current.GoToAsync(nameof(BrigadesManager));
        }
    }
}
