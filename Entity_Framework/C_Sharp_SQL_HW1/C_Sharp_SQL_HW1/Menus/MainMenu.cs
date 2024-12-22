using C_Sharp_SQL_HW1.Context;
using C_Sharp_SQL_HW1.Enums;
using C_Sharp_SQL_HW1.Helpers;
using C_Sharp_SQL_HW1.Menus.Logic;
using Microsoft.EntityFrameworkCore;

namespace C_Sharp_SQL_HW1.Menus;

public static class MainMenu
{
	[StaticConsoleMenuCommand("Отображение всей информации о овощах и фруктах")]
	public static async Task DisplayVegetablesAndFruits()
	{
        await using var context = new ApplicationContext();

		var fruits = await context.Fruits.ToListAsync();

        Console.WriteLine();
        Console.WriteLine("Список овощей и фруктов:");
		Console.WriteLine();

        fruits.ForEach(f => FruitDataPrinter.Print(f));
    }

	[StaticConsoleMenuCommand("Отображение всех названий овощей и фруктов")]
	public static async Task DisplayAllVegetablesAndFruitsNames()
	{
        await using var context = new ApplicationContext();

        var fruits = await context.Fruits.GroupBy(x => x.Name).ToListAsync();

        Console.WriteLine();
        Console.WriteLine("Названия овощей и фруктов:");
        Console.WriteLine();

        fruits.ForEach(x => Console.WriteLine(x.Key));
    }

	[StaticConsoleMenuCommand("Отображение всех цветов")]
	public static async Task DisplayAllVegetablesAndFruitsColors()
	{
        await using var context = new ApplicationContext();

        var fruits = await context.Fruits.GroupBy(x => x.Color).ToListAsync();

        Console.WriteLine();
        Console.WriteLine("Цвета овощей и фруктов:");
        Console.WriteLine();

        fruits.ForEach(x => Console.WriteLine(x.Key));
    }

	[StaticConsoleMenuCommand("Показать максимальную калорийность")]
	public static async Task DisplayVegetablesAndFruitsWithMaxCalories()
	{
        await using var context = new ApplicationContext();

        var calories = await context.Fruits.MaxAsync(f => f.Calories);

        Console.WriteLine();
        Console.WriteLine($"Максимальная калорийность: {calories}");
    }

	[StaticConsoleMenuCommand("Показать минимальную калорийность")]
    public static async Task DisplayVegetablesAndFruitsWithMinCalories()
	{
        await using var context = new ApplicationContext();

        var calories = await context.Fruits.MinAsync(f => f.Calories);

        Console.WriteLine();
        Console.WriteLine($"Минимальная калорийность: {calories}");
    }

	[StaticConsoleMenuCommand("Показать среднюю калорийность")]
	public static async Task DisplayVegetablesAndFruitsWithAvgCalories()
	{
        await using var context = new ApplicationContext();

        var calories = await context.Fruits.AverageAsync(f => f.Calories);

        Console.WriteLine();
        Console.WriteLine($"Средняя калорийность: {calories}");
    }

    [StaticConsoleMenuCommand("Показать количество овощей")]
	public static async Task DisplayVegetablesQuantity()
	{
        await using var context = new ApplicationContext();

        var quantity = await context.Fruits.Where(f => f.Type == FruitType.Vegetable).CountAsync();

        Console.WriteLine();
        Console.WriteLine($"Количество овощей: {quantity}");
    }

	[StaticConsoleMenuCommand("Показать количество фруктов")]
	public static async Task DisplayFruitsQuantity()
	{
        await using var context = new ApplicationContext();

        var quantity = await context.Fruits.Where(f => f.Type == FruitType.Fruit).CountAsync();

        Console.WriteLine();
        Console.WriteLine($"Количество фруктов: {quantity}");
    }

	[StaticConsoleMenuCommand("Показать количество овощей и фруктов заданного цвета")]
	public static async Task DisplayVegetablesAndFruitsQuantityWithSpecifiedColors()
	{
        Console.WriteLine();
        Console.Write("Введите цвет => ");
        var color = Console.ReadLine();

        await using var context = new ApplicationContext();

        var quantity = await context.Fruits.Where(f => f.Color == color).CountAsync();

        Console.WriteLine();
        Console.WriteLine($"Количество овощей и фруктов заданного цвета: {quantity}");
    }

	[StaticConsoleMenuCommand("Показать количество овощей и фруктов каждого цвета")]
	public static async Task DisplayEachColorVegetablesAndFruitsNumber()
	{
        await using var context = new ApplicationContext();

        var fruits = await context.Fruits.GroupBy(f => f.Color).ToListAsync();

        Console.WriteLine();
        Console.WriteLine("Количество овощей и фруктов каждого цвета:");
        Console.WriteLine();

        fruits.ForEach(x => Console.WriteLine($"{x.Key} - {x.Count()}"));
    }

	[StaticConsoleMenuCommand("Показать овощи и фрукты с калорийностью ниже указанной")]
	public static async Task DisplayVegetablesAndFruitsWithLowerCalories()
	{
        Console.WriteLine();
        var calories = ConsoleReadHelper.ReadInt("Введите калорийность => ");

        await using var context = new ApplicationContext();

        var fruits = await context.Fruits.Where(f => f.Calories < calories).ToListAsync();

        Console.WriteLine();
        Console.WriteLine("Овощи и фрукты с калорийностью ниже указанной:");
        Console.WriteLine();

        fruits.ForEach(f => FruitDataPrinter.Print(f));
    }

    [StaticConsoleMenuCommand("Показать овощи и фрукты с калорийностью выше указанной")]
    public static async Task DisplayVegetablesAndFruitsWithLotsCalories()
    {
        Console.WriteLine();
        var calories = ConsoleReadHelper.ReadInt("Введите калорийность => ");

        await using var context = new ApplicationContext();

        var fruits = await context.Fruits.Where(f => f.Calories > calories).ToListAsync();

        Console.WriteLine();
        Console.WriteLine("Овощи и фрукты с калорийностью выше указанной:");
        Console.WriteLine();

        fruits.ForEach(f => FruitDataPrinter.Print(f));
    }

    [StaticConsoleMenuCommand("Показать овощи и фрукты с калорийностью в указанном диапазоне")]
    public static async Task DisplayVegetablesAndFruitsWithSpecifiedRangeCalories()
    {
        Console.WriteLine();
        var minCalories = ConsoleReadHelper.ReadInt("Введите минимальную калорийность =>  ");

        Console.WriteLine();
        var maxCalories = ConsoleReadHelper.ReadInt("Введите максимальную калорийность => ");

        if (minCalories > maxCalories)
            (minCalories, maxCalories) = (maxCalories, minCalories);

        await using var context = new ApplicationContext();

        var fruits = await context.Fruits.Where(f => f.Calories > minCalories && f.Calories < maxCalories).ToListAsync();

        Console.WriteLine();
        Console.WriteLine("Овощи и фрукты с калорийностью в указанном диапазоне:");
        Console.WriteLine();

        fruits.ForEach(f => FruitDataPrinter.Print(f));
    }

    [StaticConsoleMenuCommand("Показать все овощи и фрукты, у которых цвет желтый или красный")]
    public static async Task DisplayVegetablesAndFruitsWithYellowOrRedColor()
    {
        await using var context = new ApplicationContext();

        var fruits = await context.Fruits.Where(f => f.Color == "Red" || f.Color == "Yellow").ToListAsync();

        Console.WriteLine();
        Console.WriteLine("Список жёлтых или красных овощей и фруктов:");
        Console.WriteLine();

        fruits.ForEach(f => FruitDataPrinter.Print(f));
    }
}