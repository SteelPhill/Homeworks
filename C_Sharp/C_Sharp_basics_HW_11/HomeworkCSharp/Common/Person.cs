namespace HomeworkCSharp;

[AgeValidation(18)]
public class Person
{
    [Params("Name.ini")]
    public string Name { get; set; }

    [Params("Age.ini")]
    public int Age { get; set; }

    [Params("Height.ini")]
    public int Height { get; set; }

    [Params("Weight.ini")]
    public int Weight { get; set; }
}