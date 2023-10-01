using Microsoft.AspNetCore.Mvc.RazorPages;
using WEB_153501_Savonchik.Domain.Entities;
using WEB_153501_Savonchik.Services.TelephoneService;

namespace WEB_153501_Savonchik.Areas.TelephoneAdmin.Pages
{
    public class IndexModel : PageModel
    {
        private readonly ITelephoneService _telephoneService;
        public IList<Telephone> Telephone { get; set; } = default!;

        public IndexModel(ITelephoneService telephoneService)
        {
            _telephoneService = telephoneService;
        }

        public async Task OnGetAsync()
        {
            if (_telephoneService.GetTelephoneListAsync(null).Result.Data.Items != null)
            {
                Telephone = (await _telephoneService.GetTelephoneListAsync(null)).Data.Items;
            }
        }
    }
}
