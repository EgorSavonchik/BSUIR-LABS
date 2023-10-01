using _153505_Savonchik.ApplicationServices.Abstractions;
using _153505_Savonchik.Domain.Entities;
using CommunityToolkit.Mvvm.Input;
using System.Diagnostics;

namespace _153505_Savonchik.UI.ViewModels
{
    public partial class WorkEditViewModel : IQueryAttributable
    {
        public IBrigadeService brigadeService; 
        public Work SelectedWork { get; set; }
        public WorkEditViewModel(IBrigadeService brigadeService) 
        { 
            this.brigadeService = brigadeService;
        }

        public void ApplyQueryAttributes(IDictionary<string, object> query)
        {
            SelectedWork = (Work)query["selectedWork"];
        }
    }
}
