namespace WPFHomework.Helpers;

interface ISerializer
{
    void Serialize(object obj, string path);
    T Deserialize<T>(string path);
}