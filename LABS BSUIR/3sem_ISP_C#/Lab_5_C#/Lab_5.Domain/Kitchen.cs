using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_5.Domain
{
    public class Kitchen
    {
        public string nameOfTheManager;
        public int numberOfCooks;
        public bool readyToWork;

        public string NameOfTheManager { get => nameOfTheManager; set { nameOfTheManager = value; } }
        public int NumberOfCooks { get => numberOfCooks; set { numberOfCooks = value; } }
        public bool ReadyToWork { get => readyToWork; set { readyToWork = value; } }

        public Kitchen()
        {
            numberOfCooks = 0;
            nameOfTheManager = "none";
            readyToWork = false;
        }

        public Kitchen(string name, int quantity, bool readiness)
        {
            nameOfTheManager = name;
            readyToWork = readiness;
            numberOfCooks = quantity;
        }
    }
}
