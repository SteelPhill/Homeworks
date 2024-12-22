#pragma warning disable CS8618

using C_Sharp_SQL_HW1.Enums;

namespace C_Sharp_SQL_HW1.Entities;

public class Fruit
{
    public int Id { get; set; }
    public string Name { get; set; }
    public string Color { get; set; }
    public int Calories { get; set; }
    public FruitType Type { get; set; }
}