using lab_1.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_1.Services
{
    public interface IRateService
    {
        IEnumerable<Rate> GetRates(DateTime date);
    }
}
