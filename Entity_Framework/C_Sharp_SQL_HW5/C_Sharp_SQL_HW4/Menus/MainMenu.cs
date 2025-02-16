using C_Sharp_SQL_HW4.Database.Context;
using C_Sharp_SQL_HW4.Domain.Entities;
using C_Sharp_SQL_HW4.Extensions;
using C_Sharp_SQL_HW4.Helpers;
using C_Sharp_SQL_HW4.Menus.Logic;
using Microsoft.EntityFrameworkCore;

namespace C_Sharp_SQL_HW4.Menus;

public static class MainMenu
{
    [StaticConsoleMenuCommand("Поиск информации по названию игры")]
    public static async Task DisplayGameData()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите игру:");
        ConsoleMenuHelper.PrintCommands(games.Select(g => g.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, games.Length);
        if (selector == 0)
            return;

        PrintGame(games[selector - 1]);
    }

    [StaticConsoleMenuCommand("Поиск игр по названию студии")]
    public static async Task DisplayGamesByStudio()
    {
        await using var context = new ApplicationContext();

        var studios = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .Select(g => g.Studio)
            .Distinct()
            .OrderBy(s => s)
            .ToArrayAsync();

        studios = studios.OrderBy(s => s.Length).ToArray();

        Console.WriteLine();
        Console.Write("Выберите студию:");
        ConsoleMenuHelper.PrintCommands(studios);
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, studios.Length);
        if (selector == 0)
            return;

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted && g.Studio == studios[selector - 1])
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Поиск информации по названию студии и игры")]
    public static async Task DisplayGameByStudio()
    {
        await using var context = new ApplicationContext();

        var studios = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .Select(g => g.Studio)
            .Distinct()
            .OrderBy(s => s)
            .ToArrayAsync();

        studios = studios.OrderBy(s => s.Length).ToArray();

        Console.WriteLine();
        Console.Write("Выберите студию:");
        ConsoleMenuHelper.PrintCommands(studios);
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, studios.Length);
        if (selector == 0)
            return;

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted && g.Studio == studios[selector - 1])
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите игру:");
        ConsoleMenuHelper.PrintCommands(games.Select(g => g.Name));
        selector = ConsoleReadHelper.ReadInt(" => ", 0, games.Length);
        if (selector == 0)
            return;

        PrintGame(games[selector - 1]);
    }

    [StaticConsoleMenuCommand("Поиск игр по жанру")]
    public static async Task DisplayGamesByGenre()
    {
        await using var context = new ApplicationContext();

        var genres = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .Select(g => g.Genre)
            .Distinct()
            .OrderBy(s => s)
            .ToArrayAsync();

        genres = genres.OrderBy(s => s.Length).ToArray();

        Console.WriteLine();
        Console.Write("Выберите жанр:");
        ConsoleMenuHelper.PrintCommands(genres);
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, genres.Length);
        if (selector == 0)
            return;

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted && g.Genre == genres[selector - 1])
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Поиск игр по году релиза")]
    public static async Task DisplayGamesByReleaseDate()
    {
        Console.WriteLine();
        Console.WriteLine("Введите год релиза");
        var searchYear = ConsoleReadHelper.ReadInt(" => ", Constants.FirstReleasedGameYear, Constants.CurrentYear);

        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted && g.ReleaseDate.Year == searchYear)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Отобразить информацию обо всех однопользовательских играх")]
    public static async Task DisplaySingleGames()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted && g.IsSingle)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Отобразить информацию обо всех многопользовательских играх")]
    public static async Task DisplayNonSingleGames()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted && !g.IsSingle)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Показать игру с максимальным количеством проданных игр")]
    public static async Task DisplayMostSoldGame()
    {
        await using var context = new ApplicationContext();

        var game = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .OrderByDescending(g => g.SoldCopies)
            .FirstOrDefaultAsync();

        PrintGame(game!);
    }

    [StaticConsoleMenuCommand("Показать игру с минимальным количеством проданных игр")]
    public static async Task DisplayMostNotSoldGame()
    {
        await using var context = new ApplicationContext();

        var game = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .OrderBy(g => g.SoldCopies)
            .FirstOrDefaultAsync();

        PrintGame(game!);
    }

    [StaticConsoleMenuCommand("Отобразить топ-3 самых продаваемых игр")]
    public static async Task DisplayTopThreeMostSoldGames()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .OrderByDescending(g => g.SoldCopies)
            .Take(3)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Отобразить топ-3 самых непродаваемых игр")]
    public static async Task DisplayTopThreeMostNotSoldGames()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .OrderBy(g => g.SoldCopies)
            .Take(3)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Добавить новую игру")]
    public static async Task AddNewGame()
    {
        try
        {
            var name = ConsoleReadHelper.ReadString("Введите название игры => ");

            await using var context = new ApplicationContext();

            var games = await context.Games
                .AsNoTracking()
                .Where(g => !g.IsDeleted && g.Name == name)
                .Select(g => g.Name)
                .ToArrayAsync();

            if (games.Length > 0)
                throw new Exception("Игра с таким название уже есть.");

            Console.WriteLine();
            var genre = ConsoleReadHelper.ReadString("Введите название жанра => ");

            Console.WriteLine();
            var studio = ConsoleReadHelper.ReadString("Введите название студии => ");

            Console.Write("Введите дату релиза => ");
            if (!DateTime.TryParse(Console.ReadLine(), out var releaseDate))
                throw new Exception("Некорректный формат даты релиза.");

            Console.WriteLine("Введите количество проданных копий");
            var soldCopies = ConsoleReadHelper.ReadInt(" => ", 0);

            var isSingle = IsSingleModeSelector();

            var newGame = new Game()
            {
                Name = name,
                Genre = genre,
                Studio = studio,
                ReleaseDate = releaseDate.ToDateOnly(),
                SoldCopies = soldCopies,
                IsSingle = isSingle
            };

            await context.Games.AddAsync(newGame);
            await context.SaveChangesAsync();
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Добавление отменено: {ex.Message}");
        }

        Console.WriteLine();
        Console.WriteLine("Игра добавлена.");
    }

    [StaticConsoleMenuCommand("Изменить данные существующей игры")]
    public static async Task ChangeGameData()
    {
        Dictionary<string, Func<ApplicationContext, Game, Task>> changeDataCommands = new()
        {
            { "Изменить название", ChangeGameName },
            { "Изменить жанр", ChangeGameStudio },
            { "Изменить студию", ChangeGameGenre },
            { "Изменить дату релиза", ChangeGameReleaseDate },
            { "Изменить количество проданных копий", ChangeGameSoldCopies },
            { "Изменить режим игры", ChangeGameMode }
        };

        ConsoleMenuHelper.PrintCommands(changeDataCommands.Keys);
        var menuSelector = ConsoleReadHelper.ReadInt(" => ", 0, changeDataCommands.Keys.Count);
        if (menuSelector == 0)
            return;

        await using var context = new ApplicationContext();

        var games = await context.Games
            .Where(g => !g.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите игру:");
        ConsoleMenuHelper.PrintCommands(games.Select(g => g.Name));
        var gameSelector = ConsoleReadHelper.ReadInt(" => ", 0, games.Length);
        if (gameSelector == 0)
            return;

        Console.WriteLine();
        Console.WriteLine("Выбранная игра:");
        PrintGame(games[gameSelector - 1]);

        try
        {
            var selectedCommand = changeDataCommands.Keys.ElementAt(menuSelector - 1);
            await changeDataCommands[selectedCommand](context, games[gameSelector - 1]);
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Изменение отменено: {ex.Message}");
        }

        Console.WriteLine();
        Console.WriteLine("Информация об игре изменена.");
    }

    [StaticConsoleMenuCommand("Удалить игру")]
    public static async Task RemoveGame()
    {
        await using var context = new ApplicationContext();

        var studios = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .Select(g => g.Studio)
            .Distinct()
            .OrderBy(s => s)
            .ToArrayAsync();

        studios = studios.OrderBy(s => s.Length).ToArray();

        Console.WriteLine();
        Console.Write("Выберите студию:");
        ConsoleMenuHelper.PrintCommands(studios);
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, studios.Length);
        if (selector == 0)
            return;

        var games = await context.Games
            .Where(g => !g.IsDeleted && g.Studio == studios[selector - 1])
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите игру:");
        ConsoleMenuHelper.PrintCommands(games.Select(g => g.Name));
        selector = ConsoleReadHelper.ReadInt(" => ", 0, games.Length);
        if (selector == 0)
            return;

        var selectedGame = games[selector - 1];

        Console.WriteLine();
        Console.Write("Выбранная игра:");
        PrintGame(selectedGame);

        Console.WriteLine();
        Console.Write("Удалить игру?");
        ConsoleMenuHelper.PrintCommands(["Да"]);
        selector = ConsoleReadHelper.ReadInt(" => ", 0, 1);
        if (selector == 0)
            return;

        selectedGame.IsDeleted = true;
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Игра удалена.");
    }

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

    private static async Task ChangeGameName(ApplicationContext context, Game game)
    {
        Console.WriteLine();
        var newName = ConsoleReadHelper.ReadString("Введите название игры => ");

        var games = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted && g.Name == newName)
            .Select(g => g.Name)
            .ToArrayAsync();
        if (games.Count() > 0)
            throw new Exception("Игра с таким название уже есть.");

        game.Name = newName;
        await context.SaveChangesAsync();
    }

    private static async Task ChangeGameStudio(ApplicationContext context, Game game)
    {
        Console.WriteLine();
        game.Studio = ConsoleReadHelper.ReadString("Введите название студии => ");

        await context.SaveChangesAsync();
    }

    private static async Task ChangeGameGenre(ApplicationContext context, Game game)
    {
        Console.WriteLine();
        game.Genre = ConsoleReadHelper.ReadString("Введите название жанра => ");

        await context.SaveChangesAsync();
    }

    private static async Task ChangeGameReleaseDate(ApplicationContext context, Game game)
    {
        Console.Write("Введите дату релиза => ");

        if (!DateTime.TryParse(Console.ReadLine(), out var releaseDate))
            throw new Exception("Некорректный формат даты релиза.");

        game.ReleaseDate = releaseDate.ToDateOnly();
        await context.SaveChangesAsync();
    }

    private static async Task ChangeGameSoldCopies(ApplicationContext context, Game game)
    {
        Console.WriteLine("Введите количество проданных копий");
        game.SoldCopies = ConsoleReadHelper.ReadInt(" => ", 0);

        await context.SaveChangesAsync();
    }

    private static async Task ChangeGameMode(ApplicationContext context, Game game)
    {
        game.IsSingle = IsSingleModeSelector();

        await context.SaveChangesAsync();
    }

    private static bool IsSingleModeSelector()
    {
        var isSingle = true;
        Console.WriteLine();
        Console.Write("Выберите режим игры:");

        ConsoleMenuHelper.PrintCommands(["Однопользовательская", "Многопользовательская"]);
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, 2);
        if (selector == 0)
            throw new Exception("Режим игры не выбран.");
        else if (selector == 2)
            isSingle = false;

        return isSingle;
    }
}