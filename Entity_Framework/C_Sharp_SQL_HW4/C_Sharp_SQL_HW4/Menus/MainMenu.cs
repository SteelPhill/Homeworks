using C_Sharp_SQL_HW4.Database.Context;
using C_Sharp_SQL_HW4.Domain.Entities;
using C_Sharp_SQL_HW4.Extensions;
using C_Sharp_SQL_HW4.Helpers;
using C_Sharp_SQL_HW4.Menus.Logic;
using Microsoft.EntityFrameworkCore;

namespace C_Sharp_SQL_HW4.Menus;

public static class MainMenu
{
    [StaticConsoleMenuCommand("Показать все игры")]
    public static async Task DisplayGames()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
             .AsNoTracking()
             .Where(g => !g.IsDeleted)
             .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Пересоздать данные в базе данных")]
    public static async Task RecreateDatabaseData()
    {
        await using var context = new ApplicationContext();

        await CreateDatabaseDataHelper.RecreateDatabaseDataAsync(context);
    }

    private static void PrintGame(Game game)
    {
        Console.WriteLine();
        Console.WriteLine($"Id:           {game.Id}");
        Console.WriteLine($"Name:         {game.Name}");
        Console.WriteLine($"Studio:       {game.Studio}");
        Console.WriteLine($"Genre:        {game.Genre}");
        Console.WriteLine($"Release date: {game.ReleaseDate.ToShortDateString()}");
        Console.WriteLine($"Sold copies:  {game.SoldCopies}");
        Console.WriteLine($"Is single:    {(game.IsSingle ? "Yes" : "No")}");
    }
}