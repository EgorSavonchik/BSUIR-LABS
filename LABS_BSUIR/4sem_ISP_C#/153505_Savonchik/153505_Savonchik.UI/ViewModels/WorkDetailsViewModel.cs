﻿using _153505_Savonchik.ApplicationServices.Abstractions;
using _153505_Savonchik.Domain.Entities;
using CommunityToolkit.Mvvm.Input;

namespace _153505_Savonchik.UI.ViewModels
{
    public partial class WorkDetailsViewModel : IQueryAttributable
    {
        public Work SelectedWork { get; set; }
        private IWorkService workService;
        private BrigadesManagerViewModel brigadesManagerViewModel;
        public WorkDetailsViewModel(IWorkService workService, BrigadesManagerViewModel brigadesManagerViewModel)
        {
            this.workService = workService;
            this.brigadesManagerViewModel = brigadesManagerViewModel;
        }

        public void ApplyQueryAttributes(IDictionary<string, object> query)
        {
            SelectedWork = (Work) query["Work"];
        }

        [RelayCommand]
        public async void EditWork() => await GotoEditWork();

        public async Task GotoEditWork()
        {
            IDictionary<string, object> parameters = new Dictionary<string, object>
            {
                { "selectedWork", SelectedWork }
            };

            await Shell.Current.GoToAsync(nameof(EditWork), parameters);
        }

        [RelayCommand]
        public async void ChangePhoto()
        {
            var result = await FilePicker.Default.PickAsync();

            if (result != null && (result.FileName.EndsWith("png", StringComparison.OrdinalIgnoreCase) 
                || result.FileName.EndsWith("jpg", StringComparison.OrdinalIgnoreCase)))
            {
                SelectedWork.imagePath = result.FileName;

                await brigadesManagerViewModel.UpdateWorkAsync(SelectedWork);
            }
        }
    }
}