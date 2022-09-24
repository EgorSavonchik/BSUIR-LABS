using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace bank
{
    public class bank
    {
        private static bank instance = null;

        contribution contr;
        string bank_name;
        int number_contribution;
        double contribution_procent;

        public bank() { }

        public static bank getInstance(string name = "bank", int number = 5, double procent = 10, int contribut = 50)
        {
            if (instance == null)
                instance = new bank(name, number, procent, contribut);
            return instance;
        }

        public void create(string name = "bank", int number = 5, double procent = 10, int contribut = 50)
        {
            instance = getInstance(name, number, procent, contribut);
        }

        private bank(string name = "bank", int number = 5, double procent = 10, int contribut = 50)
        {
            this.bank_name = name;
            this.number_contribution = number;
            this.contribution_procent = procent / 100;
            this.contr = new contribution(contribut);
        }

        public void up_contribution(int up)
        {
            instance.contr.size_up(up);
        }

        public void down_contribution(int down)
        {
            instance.contr.size_down(down);
        }

        public double payment()
        {
            return instance.number_contribution * instance.contribution_procent * instance.contr.getSize();
        }

        public int getContribituonSize()
        {
            return instance.contr.getSize();
        }

        public int getContribituonNumber()
        {
            return instance.number_contribution;
        }

        public double getContribituonProcent()
        {
            return instance.contribution_procent * 100;
        }

        public string getName()
        {
            return instance.bank_name;
        }

    }
}
