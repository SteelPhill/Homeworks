using C_Sharp_SQL_HW4.Database.Context;
using C_Sharp_SQL_HW4.Domain.Entities;
using C_Sharp_SQL_HW4.Extensions;
using C_Sharp_SQL_HW4.Helpers;
using C_Sharp_SQL_HW4.Menus.Logic;
using Microsoft.EntityFrameworkCore;

namespace C_Sharp_SQL_HW4.Menus;

public static class MainMenu
{
    #region DisplayCommands

    [StaticConsoleMenuCommand("Поиск информации по названию игры")]
    public static async Task DisplayGameInfo()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => !g.IsDeleted && !g.Studio.IsDeleted)
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
    public static async Task DisplayStudioGames()
    {
        await using var context = new ApplicationContext();

        var studios = await context.Studios
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .Include(s => s.Games
                .Where(g => !g.IsDeleted && !g.Genre.IsDeleted))
            .ThenInclude(g => g.Genre)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите студию:");
        ConsoleMenuHelper.PrintCommands(studios.Select(s => s.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, studios.Length);
        if (selector == 0)
            return;

        studios[selector - 1].Games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Поиск информации по названию студии и игры")]
    public static async Task DisplayGameByStudio()
    {
        await using var context = new ApplicationContext();

        var studios = await context.Studios
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .Include(s => s.Games
                .Where(g => !g.IsDeleted && !g.Genre.IsDeleted))
            .ThenInclude(g => g.Genre)
            .ToArrayAsync();
        
        Console.WriteLine();
        Console.Write("Выберите студию:");
        ConsoleMenuHelper.PrintCommands(studios.Select(s => s.Name));
        var studioSelector = ConsoleReadHelper.ReadInt(" => ", 0, studios.Length);
        if (studioSelector == 0)
            return;

        var studioGames = studios[studioSelector - 1].Games.ToArray();

        Console.WriteLine();
        Console.Write("Выберите игру:");
        ConsoleMenuHelper.PrintCommands(studioGames.Select(g => g.Name));
        var gameSelector = ConsoleReadHelper.ReadInt(" => ", 0, studioGames.Length);
        if (gameSelector == 0)
            return;

        PrintGame(studioGames[gameSelector - 1]);
    }

    [StaticConsoleMenuCommand("Поиск игр по жанру")]
    public static async Task DisplayGamesByGenre()
    {
        await using var context = new ApplicationContext();

        var genres = await context.Genres
            .AsNoTracking()
            .Include(g => g.Games
                .Where(g => !g.IsDeleted && !g.Studio.IsDeleted))
            .ThenInclude(g => g.Studio)
            .Where(g => !g.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите жанр:");
        ConsoleMenuHelper.PrintCommands(genres.Select(g => g.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, genres.Length);
        if (selector == 0)
            return;

        genres[selector - 1].Games.ForEach(PrintGame);
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
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => 
                !g.IsDeleted && 
                !g.Studio.IsDeleted && 
                !g.Genre.IsDeleted && 
                g.ReleaseDate.Year == searchYear)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Отобразить информацию обо всех однопользовательских играх")]
    public static async Task DisplaySingleGames()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => 
                !g.IsDeleted &&
                !g.Studio.IsDeleted && 
                !g.Genre.IsDeleted && 
                g.IsSingle)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Отобразить информацию обо всех многопользовательских играх")]
    public static async Task DisplayNonSingleGames()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => 
                !g.IsDeleted &&
                !g.Studio.IsDeleted &&
                !g.Genre.IsDeleted &&
                !g.IsSingle)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Показать игру с максимальным количеством проданных игр")]
    public static async Task DisplayMostSoldGame()
    {
        await using var context = new ApplicationContext();

        var game = await context.Games
            .AsNoTracking()
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => !g.IsDeleted && !g.Studio.IsDeleted && !g.Genre.IsDeleted)
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
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => !g.IsDeleted && !g.Studio.IsDeleted && !g.Genre.IsDeleted)
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
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => !g.IsDeleted && !g.Studio.IsDeleted && !g.Genre.IsDeleted)
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
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => !g.IsDeleted && !g.Studio.IsDeleted && !g.Genre.IsDeleted)
            .OrderBy(g => g.SoldCopies)
            .Take(3)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Отобразить количество однопользовательских игр")]
    public static async Task DisplaySingleGamesCount()
    {
        await using var context = new ApplicationContext();

        var count = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted && g.IsSingle)
            .CountAsync();

        Console.WriteLine();
        Console.WriteLine($"Количество однопользовательских игр: {count}");
    }

    [StaticConsoleMenuCommand("Отобразить количество многопользовательских игр")]
    public static async Task DisplayNonSingleGamesCount()
    {
        await using var context = new ApplicationContext();

        var count = await context.Games
            .AsNoTracking()
            .Where(g => !g.IsDeleted && !g.IsSingle)
            .CountAsync();

        Console.WriteLine();
        Console.WriteLine($"Количество многопользовательских игр: {count}");
    }

    [StaticConsoleMenuCommand("Показать игру с максимальным количеством проданных игр конкретного жанра")]
    public static async Task DisplayGameWithMostSoldByGenre()
    {
        await using var context = new ApplicationContext();

        var genres = await context.Genres
            .AsNoTracking()
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите жанр:");
        ConsoleMenuHelper.PrintCommands(genres.Select(g => g.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, genres.Length);
        if (selector == 0)
            return;

        var game = await context.Games
            .AsNoTracking()
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => 
                !g.IsDeleted &&
                !g.Studio.IsDeleted && 
                !g.Genre.IsDeleted &&
                g.Genre.Name == genres[selector - 1].Name)
            .OrderByDescending(g => g.SoldCopies)
            .FirstOrDefaultAsync();

        PrintGame(game!);
    }

    [StaticConsoleMenuCommand("Отобразить топ-5 самых продаваемых игр конкретного стиля")]
    public static async Task DisplayTopFiveGameWithMostSoldByGenre()
    {
        await using var context = new ApplicationContext();

        var genres = await context.Genres
            .AsNoTracking()
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите жанр:");
        ConsoleMenuHelper.PrintCommands(genres.Select(g => g.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, genres.Length);
        if (selector == 0)
            return;

        var games = await context.Games
            .AsNoTracking()
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => 
                !g.IsDeleted && 
                !g.Studio.IsDeleted && 
                !g.Genre.IsDeleted &&
                g.Genre.Name == genres[selector - 1].Name)
            .OrderByDescending(g => g.SoldCopies)
            .Take(5)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Отобразить топ-5 самых непродаваемых игр конкретного стиля")]
    public static async Task DisplayTopFiveGameWithMostNonSoldByGenre()
    {
        await using var context = new ApplicationContext();

        var genres = await context.Genres
            .AsNoTracking()
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите жанр:");
        ConsoleMenuHelper.PrintCommands(genres.Select(g => g.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, genres.Length);
        if (selector == 0)
            return;

        var games = await context.Games
            .AsNoTracking()
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => 
                !g.IsDeleted && 
                !g.Studio.IsDeleted &&
                !g.Genre.IsDeleted &&
                g.Genre.Name == genres[selector - 1].Name)
            .OrderBy(g => g.SoldCopies)
            .Take(5)
            .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Отобразить полную информацию об игре")]
    public static async Task DisplayAllGameInfo()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
            .AsNoTracking()
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .ThenInclude(s => s.CitiesStudios
                .Where(c => 
                    !c.City.IsDeleted && 
                    !c.City.Country.IsDeleted))
            .ThenInclude(c => c.City)
            .ThenInclude(c => c.Country)
            .Where(g => 
                !g.IsDeleted && 
                !g.Studio.IsDeleted && 
                !g.Genre.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите игру:");
        ConsoleMenuHelper.PrintCommands(games.Select(g => g.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, games.Length);
        if (selector == 0)
            return;

        var selectedGame = games[selector - 1];

        PrintGame(selectedGame);

        Console.WriteLine();
        Console.WriteLine("Location of studio branches:");
        selectedGame.Studio.CitiesStudios.ForEach(c => Console.WriteLine($"- City: {c.City.Name} -> Country: {c.City.Country.Name}"));
    }

    [StaticConsoleMenuCommand("Отобразить название каждой студии и жанр, по которому у студии максимальное количество игр")]
    public static async Task DisplayAllStudiosAndGenreWithMaxGames()
    {
        await using var context = new ApplicationContext();

        var studiosAndGenresInfo = await context.Studios
            .AsNoTracking()
            .Include(s => s.Games
                .Where(g => !g.IsDeleted && !g.Genre.IsDeleted))
            .ThenInclude(g => g.Genre)
            .Where(s => !s.IsDeleted)
            .Select(s => new
            {
                StudioName = s.Name,
                MaxGenre = s.Games
                    .GroupBy(g => g.Genre.Name)
                    .Select(i => new
                    {
                        GenreName = i.Key,
                        GameCount = i.Count()
                    })
                    .OrderByDescending(x => x.GameCount)
                    .FirstOrDefault()
            })
            .ToArrayAsync();

        Console.WriteLine();
        studiosAndGenresInfo.ForEach(x => Console.WriteLine($"- Studio: {x.StudioName} -> genre: {x.MaxGenre!.GenreName}"));
    }

    #endregion

    #region AddCommands

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
                .ToArrayAsync();

            if (games.Length > 0)
                throw new Exception("Игра с таким названием уже есть.");

            Console.WriteLine();
            Console.Write("Выберите жанр:");
            var genres = await context.Genres
                .AsNoTracking()
                .Where(g => !g.IsDeleted)
                .ToArrayAsync();

            ConsoleMenuHelper.PrintCommands(genres.Select(g => g.Name));
            var selector = ConsoleReadHelper.ReadInt(" => ", 0, genres.Length);
            if (selector == 0)
                return;
            var genre = genres[selector - 1];

            Console.WriteLine();
            Console.Write("Выберите студию:");
            var studios = await context.Studios
                .AsNoTracking()
                .Where(s => !s.IsDeleted)
                .ToArrayAsync();

            ConsoleMenuHelper.PrintCommands(studios.Select(s => s.Name));
            selector = ConsoleReadHelper.ReadInt(" => ", 0, studios.Length);
            if (selector == 0)
                return;
            var studio = studios[selector - 1];

            Console.WriteLine();
            Console.Write("Введите дату релиза => ");
            if (!DateTime.TryParse(Console.ReadLine(), out var releaseDate))
                throw new Exception("Некорректный формат даты релиза.");

            var soldCopies = ConsoleReadHelper.ReadInt("Введите количество проданных копий => ", 0);

            var isSingle = IsSingleModeSelector();

            var newGame = new Game()
            {
                Name = name,
                GenreId = genre.Id,
                StudioId = studio.Id,
                ReleaseDate = releaseDate.ToDateOnly(),
                SoldCopies = soldCopies,
                IsSingle = isSingle
            };

            await context.Games.AddAsync(newGame);
            await context.SaveChangesAsync();

            Console.WriteLine();
            Console.WriteLine("Игра добавлена.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Добавление отменено: {ex.Message}");
        }
    }

    [StaticConsoleMenuCommand("Добавить новую студию")]
    public static async Task AddNewStudio()
    {
        try
        {
            var name = ConsoleReadHelper.ReadString("Введите название студии => ");

            await using var context = new ApplicationContext();

            var studios = await context.Studios
                .AsNoTracking()
                .Where(s => !s.IsDeleted && s.Name == name)
                .ToArrayAsync();

            if (studios.Length > 0)
                throw new Exception("Студия с таким названием уже есть.");

            var newStudio = new Studio { Name = name };

            await context.Studios.AddAsync(newStudio);
            await context.SaveChangesAsync();

            Console.WriteLine();
            Console.Write("Выберите город:");
            var cities = await context.Cities
                .AsNoTracking()
                .Where(c => !c.IsDeleted)
                .ToArrayAsync();

            ConsoleMenuHelper.PrintCommands(cities.Select(c => c.Name));
            var selector = ConsoleReadHelper.ReadInt(" => ", 0, cities.Length);
            if (selector == 0)
                return;
            var city = cities[selector - 1];

            var cityStudio = new CityStudio()
            {
                CityId = city.Id,
                StudioId = newStudio.Id
            };

            await context.CitiesStudios.AddAsync(cityStudio);
            await context.SaveChangesAsync();

            Console.WriteLine();
            Console.WriteLine("Студия добавлена.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Добавление отменено: {ex.Message}");
        }
    }

    [StaticConsoleMenuCommand("Добавить новый жанр")]
    public static async Task AddNewGenre()
    {
        try
        {
            var name = ConsoleReadHelper.ReadString("Введите название жанра => ");

            await using var context = new ApplicationContext();

            var genres = await context.Genres
                .AsNoTracking()
                .Where(g => !g.IsDeleted && g.Name == name)
                .ToArrayAsync();

            if (genres.Length > 0)
                throw new Exception("Жанр с таким названием уже есть.");

            await context.Genres.AddAsync(new Genre { Name = name });
            await context.SaveChangesAsync();

            Console.WriteLine();
            Console.WriteLine("Жанр добавлен.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Добавление отменено: {ex.Message}");
        }
    }

    [StaticConsoleMenuCommand("Добавить новый город")]
    public static async Task AddNewCity()
    {
        try
        {
            var name = ConsoleReadHelper.ReadString("Введите название города => ");

            await using var context = new ApplicationContext();

            var cities = await context.Cities
                .AsNoTracking()
                .Where(c => !c.IsDeleted && c.Name == name)
                .ToArrayAsync();

            if (cities.Length > 0)
                throw new Exception("Город с таким названием уже есть.");

            Console.WriteLine();
            Console.Write("Выберите страну:");
            var countries = await context.Countries
                .AsNoTracking()
                .Where(c => !c.IsDeleted)
                .ToArrayAsync();

            ConsoleMenuHelper.PrintCommands(countries.Select(c => c.Name));
            var selector = ConsoleReadHelper.ReadInt(" => ", 0, countries.Length);
            if (selector == 0)
                return;
            var country = countries[selector - 1];           

            await context.Cities.AddAsync(new City { Name = name, CountryId = country.Id});
            await context.SaveChangesAsync();

            Console.WriteLine();
            Console.WriteLine("Город добавлен.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Добавление отменено: {ex.Message}");
        }
    }

    [StaticConsoleMenuCommand("Добавить новую страну")]
    public static async Task AddNewCountry()
    {
        try
        {
            var name = ConsoleReadHelper.ReadString("Введите название страны => ");

            await using var context = new ApplicationContext();

            var countries = await context.Countries
                .AsNoTracking()
                .Where(c => !c.IsDeleted && c.Name == name)
                .ToArrayAsync();

            if (countries.Length > 0)
                throw new Exception("Страна с таким названием уже есть.");

            await context.Countries.AddAsync(new Country { Name = name });
            await context.SaveChangesAsync();

            Console.WriteLine();
            Console.WriteLine("Страна добавлена.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Добавление отменено: {ex.Message}");
        }
    }

    #endregion

    #region ChangeCommands

    [StaticConsoleMenuCommand("Изменить данные существующей игры")]
    public static async Task ChangeGameData()
    {
        Dictionary<string, Func<ApplicationContext, Game, Task>> changeDataCommands = new()
        {
            { "Изменить название", ChangeGameName },
            { "Изменить жанр", ChangeGameGenre },
            { "Изменить студию", ChangeGameStudio },
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
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => 
                !g.IsDeleted && 
                !g.Studio.IsDeleted &&
                !g.Genre.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите игру:");
        ConsoleMenuHelper.PrintCommands(games.Select(g => g.Name));
        var gameSelector = ConsoleReadHelper.ReadInt(" => ", 0, games.Length);
        if (gameSelector == 0)
            return;

        Console.WriteLine();
        Console.Write("Выбранная игра:");
        PrintGame(games[gameSelector - 1]);

        try
        {
            var selectedCommand = changeDataCommands.Keys.ElementAt(menuSelector - 1);
            await changeDataCommands[selectedCommand](context, games[gameSelector - 1]);

            Console.WriteLine();
            Console.WriteLine("Информация об игре изменена.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Изменение отменено: {ex.Message}");
        }
    }

    [StaticConsoleMenuCommand("Изменить данные существующей студии")]
    public static async Task ChangeStudioData()
    {
        Dictionary<string, Func<ApplicationContext, Studio, Task>> changeDataCommands = new()
        {
            { "Изменить название", ChangeStudioName },
            { "Изменить город", ChangeCityOfStudio }
        };

        ConsoleMenuHelper.PrintCommands(changeDataCommands.Keys);
        var menuSelector = ConsoleReadHelper.ReadInt(" => ", 0, changeDataCommands.Keys.Count);
        if (menuSelector == 0)
            return;

        await using var context = new ApplicationContext();

        var studios = await context.Studios
            .Include(s => s.CitiesStudios
                .Where(c => !c.City.IsDeleted && !c.City.Country.IsDeleted))
            .ThenInclude(c => c.City)
            .ThenInclude(c => c.Country)
            .Where(s => !s.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите студию:");
        ConsoleMenuHelper.PrintCommands(studios.Select(s => s.Name));
        var studioSelector = ConsoleReadHelper.ReadInt(" => ", 0, studios.Length);
        if (studioSelector == 0)
            return;

        var selectedStudio = studios[studioSelector - 1];

        Console.WriteLine();
        Console.WriteLine("Выбранная студия:");
        Console.WriteLine($"Id:   {selectedStudio.Id}");
        Console.WriteLine($"Name: {selectedStudio.Name}");
        Console.WriteLine("Location of studio branches:");
        selectedStudio.CitiesStudios.ForEach(c => Console.WriteLine($"- City: {c.City.Name} -> Country: {c.City.Country.Name}"));

        try
        {
            var selectedCommand = changeDataCommands.Keys.ElementAt(menuSelector - 1);
            await changeDataCommands[selectedCommand](context, selectedStudio);

            Console.WriteLine();
            Console.WriteLine("Информация о студии изменена.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Изменение отменено: {ex.Message}");
        }
    }

    [StaticConsoleMenuCommand("Изменить данные существующего жанра")]
    public static async Task ChangeGenreData()
    {
        ConsoleMenuHelper.PrintCommands(["Изменить название"]);
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, 1);
        if (selector == 0)
            return;

        await using var context = new ApplicationContext();

        var genres = await context.Genres
            .Where(g => !g.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите жанр:");
        ConsoleMenuHelper.PrintCommands(genres.Select(s => s.Name));
        selector = ConsoleReadHelper.ReadInt(" => ", 0, genres.Length);
        if (selector == 0)
            return;

        var selectedGenre = genres[selector - 1];

        Console.WriteLine();
        Console.WriteLine("Выбранный жанр:");
        Console.WriteLine($"Id:   {selectedGenre.Id}");
        Console.WriteLine($"Name: {selectedGenre.Name}");
        
        try
        {
            var newName = ConsoleReadHelper.ReadString("Введите название жанра => ");          

            var genresNames = await context.Genres
                .AsNoTracking()
                .Where(g => !g.IsDeleted && g.Name == newName)
                .Select(g => g.Name)
                .ToArrayAsync();
            if (genresNames.Length > 0)
                throw new Exception("Жанр с таким название уже есть.");            

            selectedGenre.Name = newName;

            await context.SaveChangesAsync();

            Console.WriteLine();
            Console.WriteLine("Информация о жанре изменена.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Изменение отменено: {ex.Message}");
        }
    }

    [StaticConsoleMenuCommand("Изменить данные существующего города")]
    public static async Task ChangeCityData()
    {
        Dictionary<string, Func<ApplicationContext, City, Task>> changeDataCommands = new()
        {
            { "Изменить название", ChangeCityName },
            { "Изменить страну", ChangeCountryOfCity }
        };

        ConsoleMenuHelper.PrintCommands(changeDataCommands.Keys);
        var menuSelector = ConsoleReadHelper.ReadInt(" => ", 0, changeDataCommands.Keys.Count);
        if (menuSelector == 0)
            return;

        await using var context = new ApplicationContext();

        var cities = await context.Cities
            .Include(c => c.Country)
            .Where(c => !c.IsDeleted && !c.Country.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите город:");
        ConsoleMenuHelper.PrintCommands(cities.Select(c => c.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, cities.Length);
        if (selector == 0)
            return;

        var selectedCity = cities[selector - 1];

        Console.WriteLine();
        Console.WriteLine("Выбранный город:");
        Console.WriteLine($"Id:      {selectedCity.Id}");
        Console.WriteLine($"Name:    {selectedCity.Name}");
        Console.WriteLine($"Country: {selectedCity.Country.Name}");

        try
        {
            var selectedCommand = changeDataCommands.Keys.ElementAt(menuSelector - 1);
            await changeDataCommands[selectedCommand](context, selectedCity);

            Console.WriteLine();
            Console.WriteLine("Информация о городе изменена.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Изменение отменено: {ex.Message}");
        }
    }

    [StaticConsoleMenuCommand("Изменить данные существующей страны")]
    public static async Task ChangeCountryData()
    {
        ConsoleMenuHelper.PrintCommands(["Изменить название"]);
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, 1);
        if (selector == 0)
            return;

        await using var context = new ApplicationContext();

        var countries = await context.Countries
            .Where(c => !c.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите страну:");
        ConsoleMenuHelper.PrintCommands(countries.Select(c => c.Name));
        selector = ConsoleReadHelper.ReadInt(" => ", 0, countries.Length);
        if (selector == 0)
            return;

        var selectedCountry = countries[selector - 1];

        Console.WriteLine();
        Console.WriteLine("Выбранная страна:");
        Console.WriteLine($"Id:   {selectedCountry.Id}");
        Console.WriteLine($"Name: {selectedCountry.Name}");

        try
        {
            var newName = ConsoleReadHelper.ReadString("Введите название страны => ");

            var countriesNames = await context.Countries
                .AsNoTracking()
                .Where(c => !c.IsDeleted && c.Name == newName)
                .Select(c => c.Name)
                .ToArrayAsync();
            if (countriesNames.Length > 0)
                throw new Exception("Страна с таким название уже есть.");

            selectedCountry.Name = newName;

            await context.SaveChangesAsync();

            Console.WriteLine();
            Console.WriteLine("Информация о стране изменена.");
        }
        catch (Exception ex)
        {
            Console.WriteLine();
            Console.WriteLine($"Изменение отменено: {ex.Message}");
        }
    }

    #endregion

    #region DeleteCommands

    [StaticConsoleMenuCommand("Удалить игру выбранной студии")]
    public static async Task DeleteGameByStudio()
    {
        await using var context = new ApplicationContext();

        var studiosNames = await context.Studios
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .Select(s => s.Name)
            .Distinct()
            .OrderBy(s => s)
            .ToArrayAsync();

        studiosNames = studiosNames.OrderBy(s => s.Length).ToArray();

        Console.WriteLine();
        Console.Write("Выберите студию:");
        ConsoleMenuHelper.PrintCommands(studiosNames);
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, studiosNames.Length);
        if (selector == 0)
            return;

        var games = await context.Games
            .Include(g => g.Genre)
            .Include(g => g.Studio)
            .Where(g => 
                !g.IsDeleted && 
                !g.Studio.IsDeleted &&
                !g.Genre.IsDeleted &&
                g.Studio.Name == studiosNames[selector - 1])
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

    [StaticConsoleMenuCommand("Удалить студию")]
    public static async Task DeleteStudio()
    {
        await using var context = new ApplicationContext();

        var studios = await context.Studios
            .Include(s => s.Games
                .Where(g => !g.IsDeleted))
            .Where(s => !s.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите студию:");
        ConsoleMenuHelper.PrintCommands(studios.Select(s => s.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, studios.Length);
        if (selector == 0)
            return;

        var selectedStudio = studios[selector - 1];

        Console.WriteLine();
        Console.WriteLine($"Выбранная студия: {selectedStudio.Name}");

        Console.WriteLine();
        Console.Write("Удалить студию?");
        ConsoleMenuHelper.PrintCommands(["Да"]);
        selector = ConsoleReadHelper.ReadInt(" => ", 0, 1);
        if (selector == 0)
            return;

        selectedStudio.IsDeleted = true;
        selectedStudio.Games.ForEach(g => g.IsDeleted = true);
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Студия удалена.");
    }

    [StaticConsoleMenuCommand("Удалить жанр")]
    public static async Task DeleteGenre()
    {
        await using var context = new ApplicationContext();

        var genres = await context.Genres
            .Include(g => g.Games
                .Where(g => !g.IsDeleted))
            .Where(g => !g.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите жанр:");
        ConsoleMenuHelper.PrintCommands(genres.Select(g => g.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, genres.Length);
        if (selector == 0)
            return;

        var selectedGenre = genres[selector - 1];

        Console.WriteLine();
        Console.WriteLine($"Выбранный жанр: {selectedGenre.Name}");

        Console.WriteLine();
        Console.Write("Удалить жанр?");
        ConsoleMenuHelper.PrintCommands(["Да"]);
        selector = ConsoleReadHelper.ReadInt(" => ", 0, 1);
        if (selector == 0)
            return;

        selectedGenre.IsDeleted = true;
        selectedGenre.Games.ForEach(g => g.IsDeleted = true);
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Жанр удален.");
    }

    [StaticConsoleMenuCommand("Удалить город")]
    public static async Task DeleteCity()
    {
        await using var context = new ApplicationContext();

        var cities = await context.Cities
            .Include(c => c.CitiesStudios
                .Where(c => !c.Studio.IsDeleted))
            .ThenInclude(c => c.Studio)
            .ThenInclude(s => s.Games
                .Where(g => !g.IsDeleted))
            .Where(c => !c.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите город:");
        ConsoleMenuHelper.PrintCommands(cities.Select(s => s.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, cities.Length);
        if (selector == 0)
            return;

        var selectedCity = cities[selector - 1];

        Console.WriteLine();
        Console.WriteLine($"Выбранный город: {selectedCity.Name}");

        Console.WriteLine();
        Console.Write("Удалить город?");
        ConsoleMenuHelper.PrintCommands(["Да"]);
        selector = ConsoleReadHelper.ReadInt(" => ", 0, 1);
        if (selector == 0)
            return;

        selectedCity.IsDeleted = true;
        selectedCity.CitiesStudios.Select(c => c.Studio).ForEach(s => s.IsDeleted = true);
        selectedCity.CitiesStudios.SelectMany(c => c.Studio.Games).ForEach(g => g.IsDeleted = true);
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Город удален.");
    }

    [StaticConsoleMenuCommand("Удалить страну")]
    public static async Task DeleteCountry()
    {
        await using var context = new ApplicationContext();

        var countries = await context.Countries
            .Include(c => c.Cities
                .Where(c => !c.IsDeleted))
            .ThenInclude(c => c.CitiesStudios
                .Where(c => !c.Studio.IsDeleted))
            .ThenInclude(c => c.Studio)
            .ThenInclude(s => s.Games
                .Where(g => !g.IsDeleted))
            .Where(c => !c.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите страну:");
        ConsoleMenuHelper.PrintCommands(countries.Select(c => c.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, countries.Length);
        if (selector == 0)
            return;

        var selectedCountry = countries[selector - 1];

        Console.WriteLine();
        Console.WriteLine($"Выбранная страна: {selectedCountry.Name}");

        Console.WriteLine();
        Console.Write("Удалить страну?");
        ConsoleMenuHelper.PrintCommands(["Да"]);
        selector = ConsoleReadHelper.ReadInt(" => ", 0, 1);
        if (selector == 0)
            return;

        selectedCountry.IsDeleted = true;
        selectedCountry.Cities.ForEach(c => c.IsDeleted = true);
        selectedCountry.Cities.SelectMany(c => c.CitiesStudios).ForEach(c => c.Studio.IsDeleted = true);
        selectedCountry.Cities.SelectMany(c => c.CitiesStudios).SelectMany(c => c.Studio.Games).ForEach(g => g.IsDeleted = true);
        await context.SaveChangesAsync();

        Console.WriteLine();
        Console.WriteLine("Страна удалена.");
    }

    #endregion

    #region InitialCommands

    [StaticConsoleMenuCommand("Показать все игры")]
    public static async Task DisplayGames()
    {
        await using var context = new ApplicationContext();

        var games = await context.Games
             .AsNoTracking()
             .Include(g => g.Genre)
             .Include(g => g.Studio)
             .Where(g => 
                !g.IsDeleted && 
                !g.Studio.IsDeleted &&
                !g.Genre.IsDeleted)
             .ToArrayAsync();

        games.ForEach(PrintGame);
    }

    [StaticConsoleMenuCommand("Пересоздать данные в базе данных")]
    public static async Task RecreateDatabaseData()
    {
        await using var context = new ApplicationContext();

        await CreateDatabaseDataHelper.RecreateDatabaseDataAsync(context);

        Console.WriteLine();
        Console.WriteLine("База данных обновлена.");
    }

    #endregion

    #region HelperMethods

    private static void PrintGame(Game game)
    {
        Console.WriteLine();
        Console.WriteLine($"Id:           {game.Id}");
        Console.WriteLine($"Name:         {game.Name}");
        Console.WriteLine($"Genre:        {game.Genre.Name}");
        Console.WriteLine($"Studio:       {game.Studio.Name}");
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
        if (games.Length > 0)
            throw new Exception("Игра с таким название уже есть.");

        game.Name = newName;
        await context.SaveChangesAsync();
    }

    private static async Task ChangeGameStudio(ApplicationContext context, Game game)
    {
        var studios = await context.Studios
            .AsNoTracking()
            .Where(s => !s.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите студию:");
        ConsoleMenuHelper.PrintCommands(studios.Select(g => g.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, studios.Length);
        if (selector == 0)
            return;

        game.StudioId = studios[selector - 1].Id;

        await context.SaveChangesAsync();
    }

    private static async Task ChangeGameGenre(ApplicationContext context, Game game)
    {
        var genres = await context.Genres
            .AsNoTracking()
            .Where(g => !g.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите жанр:");
        ConsoleMenuHelper.PrintCommands(genres.Select(g => g.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, genres.Length);
        if (selector == 0)
            return;

        game.GenreId = genres[selector - 1].Id;

        await context.SaveChangesAsync();
    }

    private static async Task ChangeGameReleaseDate(ApplicationContext context, Game game)
    {
        Console.WriteLine();
        Console.Write("Введите дату релиза => ");

        if (!DateTime.TryParse(Console.ReadLine(), out var releaseDate))
            throw new Exception("Некорректный формат даты релиза.");

        game.ReleaseDate = releaseDate.ToDateOnly();
        await context.SaveChangesAsync();
    }

    private static async Task ChangeGameSoldCopies(ApplicationContext context, Game game)
    {
        Console.WriteLine();
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

    private static async Task ChangeStudioName(ApplicationContext context, Studio studio)
    {
        var newName = ConsoleReadHelper.ReadString("Введите название студии => ");

        var studios = await context.Studios
            .AsNoTracking()
            .Where(s => !s.IsDeleted && s.Name == newName)
            .Select(s => s.Name)
            .ToArrayAsync();
        if (studios.Length > 0)
            throw new Exception("Студия с таким название уже есть.");

        studio.Name = newName;
        await context.SaveChangesAsync();
    }

    private static async Task ChangeCityOfStudio(ApplicationContext context, Studio studio)
    {
        Console.WriteLine();
        Console.Write("Выберите город, который будет изменен:");
        ConsoleMenuHelper.PrintCommands(studio.CitiesStudios.Select(c => c.City.Name));
        var oldCitySelector = ConsoleReadHelper.ReadInt(" => ", 0, studio.CitiesStudios.Count);
        if (oldCitySelector == 0)
            return;

        var cities = await context.Cities
            .AsNoTracking()
            .Where(c => !c.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите новый город студии:");
        ConsoleMenuHelper.PrintCommands(cities.Select(g => g.Name));
        var newCitySelector = ConsoleReadHelper.ReadInt(" => ", 0, cities.Length);
        if (newCitySelector == 0)
            return;

        var cityStudioToDelete = studio.CitiesStudios.ElementAt(oldCitySelector - 1);
        context.CitiesStudios.Remove(cityStudioToDelete);
        await context.SaveChangesAsync();

        await context.CitiesStudios.AddAsync(new CityStudio 
        { 
            CityId = cities[newCitySelector - 1].Id, StudioId = studio.Id 
        });

        await context.SaveChangesAsync();
    }

    private static async Task ChangeCityName(ApplicationContext context, City city)
    {
        var newName = ConsoleReadHelper.ReadString("Введите название города => ");

        var citiesNames = await context.Cities
            .AsNoTracking()
            .Where(s => !s.IsDeleted && s.Name == newName)
            .Select(s => s.Name)
            .ToArrayAsync();
        if (citiesNames.Length > 0)
            throw new Exception("Город с таким название уже есть.");

        city.Name = newName;
        await context.SaveChangesAsync();
    }

    private static async Task ChangeCountryOfCity(ApplicationContext context, City city)
    {
        var countries = await context.Countries
            .AsNoTracking()
            .Where(c => !c.IsDeleted)
            .ToArrayAsync();

        Console.WriteLine();
        Console.Write("Выберите страну:");
        ConsoleMenuHelper.PrintCommands(countries.Select(с => с.Name));
        var selector = ConsoleReadHelper.ReadInt(" => ", 0, countries.Length);
        if (selector == 0)
            return;

        city.CountryId = countries[selector - 1].Id;

        await context.SaveChangesAsync();
    }

    #endregion
}