using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bank
{
    public class contribution
    {
        static int contribution_size;

        contribution()
        {

        }

        public contribution(int size)
        {
            contribution_size = size;
        }

        public void size_up(int up)
        {
            contribution_size += up;
        }

        public void size_down(int down)
        {
            contribution_size -= down;
        }

        public int getSize()
        {
            return contribution_size;
        }
    }
}
