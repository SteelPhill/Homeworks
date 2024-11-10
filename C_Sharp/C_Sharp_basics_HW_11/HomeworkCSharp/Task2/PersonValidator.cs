using System;

namespace HomeworkCSharp;

public class PersonValidator : IPersonValidator
{
    public bool AgeValidate(Person person)
    {
        var attributes = typeof(Person).GetCustomAttributes(false);

        foreach (var attribute in attributes)
            if (attribute is AgeValidationAttribute ageAttribute)
                return person.Age >= ageAttribute.Age;

        throw new Exception("Age validation failed");
    }
}