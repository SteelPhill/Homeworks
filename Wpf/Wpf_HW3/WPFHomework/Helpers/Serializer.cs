using System.IO;
using System.Xml.Serialization;

namespace WPFHomework.Helpers;


public class Serializer : ISerializer
{
    public void Serialize(object obj, string path)
    {
        using (var fs = new FileStream(path, FileMode.Create))
            new XmlSerializer(obj.GetType())?.Serialize(fs, obj);
    }

    public T Deserialize<T>(string path)
    {
        using (var fs = new FileStream(path, FileMode.Open))
            return (T)new XmlSerializer(typeof(T))?.Deserialize(fs);
    }
}