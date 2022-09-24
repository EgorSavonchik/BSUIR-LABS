using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_6
{
    public class milkFromSoligorsk : milk
    {
        public new void setBrand(string newBrand)
        {
            brand = "Soligorsk " + newBrand;
        }
    }
}
