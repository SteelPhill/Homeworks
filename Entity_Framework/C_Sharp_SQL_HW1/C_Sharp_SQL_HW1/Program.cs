using C_Sharp_SQL_HW1.Menus.Logic;
using C_Sharp_SQL_HW1.Menus;
using C_Sharp_SQL_HW1.Context;
using C_Sharp_SQL_HW1.Entities;
using C_Sharp_SQL_HW1.Enums;

namespace C_Sharp_SQL_HW1;

/*          Модуль №1
 *
 *          Задание №1
 * Создайте однотабличную базу данных «Овощи и фрукты». 
 * Нужно хранить такую информацию:
 * - Название;
 * - Тип (овощ или фрукт);
 * - Цвет;
 * - Калорийность.
 *          
 *          Задание №2
 * Создайте приложение, которое позволит пользователю подключиться и отключиться от базы данных «Овощи и фрукты».
 * Приложение может быть консольным или с UI интерфейсом.
 *          
 *          Задание №3
 * Добавьте к приложению из второго задания следующую функциональность:
 * - Отображение всей информации из таблицы с овощами и фруктами;
 * - Отображение всех названий овощей и фруктов;
 * - Отображение всех цветов;
 * - Показать максимальную калорийность;
 * - Показать минимальную калорийность;
 * - Показать среднюю калорийность.
 * 
 *          Задание №4
 * Добавьте к приложению из второго задания следующую функциональность:
 * - Показать количество овощей;
 * - Показать количество фруктов;
 * - Показать количество овощей и фруктов заданного цвета;
 * - Показать количество овощей фруктов каждого цвета;
 * - Показать овощи и фрукты с калорийностью ниже указанной;
 * - Показать овощи и фрукты с калорийностью выше указанной;
 * - Показать овощи и фрукты с калорийностью в указанном диапазоне;
 * - Показать все овощи и фрукты, у которых цвет желтый или красный.
 * 
*/

public static class Program
{
    public static async Task Main()
    {
        await StaticConsoleMenu.RunAsync(typeof(MainMenu));

        //await using var context = new ApplicationContext();
        //await context.AddAsync(new Fruit() { Name = "Banana", Color = "Yellow", Calories = 150, Type = FruitType.Fruit });
        //await context.AddAsync(new Fruit() { Name = "Tomato", Color = "Red", Calories = 80, Type = FruitType.Vegetable });
        //await context.AddAsync(new Fruit() { Name = "Cucumber", Color = "Green", Calories = 60, Type = FruitType.Vegetable });
        //await context.AddAsync(new Fruit() { Name = "Melon", Color = "Yellow", Calories = 300, Type = FruitType.Fruit });
        //await context.AddAsync(new Fruit() { Name = "Potato", Color = "Brown", Calories = 100, Type = FruitType.Vegetable });
        //await context.AddAsync(new Fruit() { Name = "Pear", Color = "Green", Calories = 120, Type = FruitType.Fruit });
        //await context.AddAsync(new Fruit() { Name = "ChiliPepper", Color = "Red", Calories = 50, Type = FruitType.Vegetable });
        //await context.AddAsync(new Fruit() { Name = "Peach", Color = "Orange", Calories = 120, Type = FruitType.Fruit });
        //await context.AddAsync(new Fruit() { Name = "Apple", Color = "Green", Calories = 60, Type = FruitType.Fruit });
        //await context.AddAsync(new Fruit() { Name = "Apple", Color = "Red", Calories = 80, Type = FruitType.Fruit });
        //await context.SaveChangesAsync();
    }
}