using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

namespace HomeworkCSharp;

public class OrdersXmlSerializer : IOrdersXmlSerializer
{
    public void Serialize(List<Order> orders, string xmlFilePath)
    {
        var xmlSerializer = new XmlSerializer(typeof(List<Order>));

        using (var fs = new FileStream(xmlFilePath, FileMode.OpenOrCreate))
        {
            xmlSerializer?.Serialize(fs, orders);
        }
    }

    public List<Order> Deserialize(string xmlFilePath)
    {
        var xmlSerializer = new XmlSerializer(typeof(List<Order>));

        using (var fs = new FileStream(xmlFilePath, FileMode.Open))
        {
            return (List<Order>)xmlSerializer?.Deserialize(fs);
        }
    }
}