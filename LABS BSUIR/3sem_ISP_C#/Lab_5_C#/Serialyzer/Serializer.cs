using Lab_5.Domain;
using System.Xml.Linq;
using System.Xml.Serialization;
using System.Text.Json;

namespace Serialyzer
{
    public class Serializer : ISerializer
    {
        public IEnumerable<Restaurant> DeSerializeByLINQ(string fileName)
        {
            XDocument xdoc;
            xdoc = XDocument.Load(fileName);
            
            List<Restaurant> temp = new List<Restaurant>();

            foreach(XElement elem in xdoc.Root.Elements())
            {
                temp.Add(new Restaurant(elem.Element("Name").Value, 
                    Convert.ToInt32(elem.Element("Income").Value), 
                    new Kitchen(
                        elem.Element("Kitchen").Element("NameOfTheManager").Value,
                        Convert.ToInt32(elem.Element("Kitchen").Element("NumberOfCooks").Value), 
                        Convert.ToBoolean(elem.Element("Kitchen").Element("ReadyToWork").Value))));
                
            }

            //xdoc.Select(obj => temp.Add(new Restaurant(obj.Element("Name").Value, Convert.ToInt32(elem.Element("Income").Value), new Kitchen(elem.Element("Kitchen").Element("NameOfTheManager").Value,
            //        Convert.ToInt32(obj.Element("Kitchen").Element("NumberOfCooks").Value), Convert.ToBoolean(elem.Element("Kitchen").Element("ReadyToWork").Value))))))
           
         
            return temp;
        }

        public IEnumerable<Restaurant> DeSerializeXML(string fileName)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Restaurant>));//НЕ МОЖЕТ РАБОТАТЬ С ИНТЕРФЕЙСОМ, ВЗЯТ ЛИСТ

            using FileStream file = new FileStream(fileName, FileMode.Open);

            return serializer.Deserialize(file) as IEnumerable<Restaurant>;

        }
        public IEnumerable<Restaurant> DeSerializeJSON(string fileName)
        {
            using FileStream file = new FileStream(fileName, FileMode.Open);

            IEnumerable<Restaurant> data = JsonSerializer.Deserialize<IEnumerable<Restaurant>>(file);

            return data;
        }
        public void SerializeByLINQ(IEnumerable<Restaurant> RestaurantList, string fileName)
        {
            XDocument xdoc = new XDocument();
            
            xdoc.Add(new XElement(new XElement("Restaurants", RestaurantList.Select(obj => 
                                        new XElement("Restaurant",
                                            new XElement("Name", obj.name),
                                            new XElement("Income", obj.income),
                                            new XElement("Kitchen",
                                                new XElement("NameOfTheManager", obj.kitchen.nameOfTheManager),
                                                new XElement("NumberOfCooks", obj.kitchen.numberOfCooks),
                                                new XElement("ReadyToWork", obj.kitchen.readyToWork)))))));

            xdoc.Save(fileName);
        }
        
        public void SerializeXML(IEnumerable<Restaurant> RestaurantList, string fileName)
        {
            XmlSerializer serializer = new XmlSerializer(RestaurantList.GetType());

            using FileStream file = new FileStream(fileName, FileMode.OpenOrCreate);

            serializer.Serialize(file, RestaurantList);
        }

        public void SerializeJSON(IEnumerable<Restaurant> RestaurantList, string fileName)
        {
            using FileStream file = new FileStream(fileName, FileMode.OpenOrCreate);

            JsonSerializer.Serialize<IEnumerable<Restaurant>>(file, RestaurantList);
        }
    }
}