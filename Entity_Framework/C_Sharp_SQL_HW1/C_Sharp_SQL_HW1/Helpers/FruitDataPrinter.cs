using C_Sharp_SQL_HW1.Entities;

namespace C_Sharp_SQL_HW1.Helpers;

public class FruitDataPrinter
{
    public static void Print(Fruit fruit)
    {
        Console.WriteLine($"Id:       {fruit.Id}");
        Console.WriteLine($"Name:     {fruit.Name}");
        Console.WriteLine($"Color:    {fruit.Color}");
        Console.WriteLine($"Calories: {fruit.Calories}");
        Console.WriteLine($"Type:     {fruit.Type}");
        Console.WriteLine();
    }
}