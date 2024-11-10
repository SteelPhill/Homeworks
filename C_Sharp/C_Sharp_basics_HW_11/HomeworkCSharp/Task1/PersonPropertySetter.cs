using System.IO;
using System.Reflection;

namespace HomeworkCSharp;

public class PersonPropertySetter : IPersonPropertySetter
{
    public void Set(PropertyInfo propertyInfo, out string property)
    {
        property = default;

        var attributes = propertyInfo.GetCustomAttributes(false);

        foreach (var attribute in attributes)
            if (attribute is ParamsAttribute paramsAttribute)
                using (var reader = new StreamReader(paramsAttribute.PropertyIniPath))
                    property = reader.ReadToEnd();
    }

    public void Set(PropertyInfo propertyInfo, out int property)
    {
        property = default;

        var attributes = propertyInfo.GetCustomAttributes(false);

        foreach (var attribute in attributes)
            if (attribute is ParamsAttribute paramsAttribute)
                using (var reader = new StreamReader(paramsAttribute.PropertyIniPath))
                    int.TryParse(reader.ReadToEnd(), out property);
    }
}