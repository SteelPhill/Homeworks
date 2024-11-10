using System.Reflection;

namespace HomeworkCSharp;

interface IPersonPropertySetter
{
    void Set(PropertyInfo propertyInfo, out string property);
    void Set(PropertyInfo propertyInfo, out int property);
}