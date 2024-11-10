using System.Collections.Generic;

namespace HomeworkCSharp;

interface IOrdersXmlSerializer
{
    void Serialize(List<Order> orders, string xmlFilePath);
    List<Order> Deserialize(string xmlFilePath);
}