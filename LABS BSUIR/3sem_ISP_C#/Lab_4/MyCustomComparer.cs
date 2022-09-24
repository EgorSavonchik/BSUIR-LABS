using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_4
{
    internal class MyCustomComparer : IComparer<Picture>
    {
        public int Compare(Picture? first, Picture? second)
        {
            return first.Name.CompareTo(second.Name);
        }
    }
}
