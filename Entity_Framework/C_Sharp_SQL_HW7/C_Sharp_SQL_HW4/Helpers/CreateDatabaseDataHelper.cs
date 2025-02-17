using C_Sharp_SQL_HW4.Database.Context;
using C_Sharp_SQL_HW4.Domain.Entities;
using C_Sharp_SQL_HW4.Extensions;
using Microsoft.EntityFrameworkCore;

namespace C_Sharp_SQL_HW4.Helpers;

public static class CreateDatabaseDataHelper
{
    public static async Task RecreateDatabaseDataAsync(ApplicationContext context)
    {
        Random random = new(1);

        await ClearTablesAsync(context);

        var countries = await CreateCountriesAsync(context);
        var genres = await CreateGenresAsync(context);
        var cities = await CreateCitiesAsync(context, random, countries);
        var studios = await CreateStudiosAsync(context);
        var games = await CreateGamesAsync(context, random, genres, studios);
        var citiesStudios = await CreateCitiesStudiosAsync(context, random, cities, studios);
    }

    private static async Task ClearTablesAsync(ApplicationContext context)
    {
        if (!await context.Countries.AnyAsync() &&
            !await context.Cities.AnyAsync() &&
            !await context.Studios.AnyAsync() &&
            !await context.Genres.AnyAsync() &&
            !await context.Games.AnyAsync() &&
            !await context.CitiesStudios.AnyAsync())
            return;

        await context.Countries.ExecuteDeleteAsync();
        await context.Cities.ExecuteDeleteAsync();
        await context.Studios.ExecuteDeleteAsync();
        await context.Genres.ExecuteDeleteAsync();
        await context.Games.ExecuteDeleteAsync();
        await context.CitiesStudios.ExecuteDeleteAsync();

        await context.Database.ExecuteSqlRawAsync("DBCC CHECKIDENT ('Countries', RESEED, 0);");
        await context.Database.ExecuteSqlRawAsync("DBCC CHECKIDENT ('Cities', RESEED, 0);");
        await context.Database.ExecuteSqlRawAsync("DBCC CHECKIDENT ('Studios', RESEED, 0);");
        await context.Database.ExecuteSqlRawAsync("DBCC CHECKIDENT ('Genres', RESEED, 0);");
        await context.Database.ExecuteSqlRawAsync("DBCC CHECKIDENT ('Games', RESEED, 0);");
    }

    private static async Task<Country[]> CreateCountriesAsync(ApplicationContext context)
    {
        var countries = Enumerable.Range(1, 5)
            .Select(index => new Country
            {
                Name = $"Country{index}"
            })
            .ToArray();

        await context.Countries.AddRangeAsync(countries);
        await context.SaveChangesAsync();

        return countries;
    }

    private static async Task<City[]> CreateCitiesAsync(
        ApplicationContext context,
        Random random,
        IReadOnlyList<Country> countries)
    {
        var cities = Enumerable.Range(1, 20)
            .Select(index => new City
            {
                Name = $"City{index}",
                Country = countries[random.Next(0, countries.Count)]
            })
            .ToArray();

        await context.Cities.AddRangeAsync(cities);
        await context.SaveChangesAsync();

        return cities;
    }

    private static async Task<Studio[]> CreateStudiosAsync(ApplicationContext context)
    {
        var studios = Enumerable.Range(1, 10)
            .Select(index => new Studio
            {
                Name = $"Studio{index}"
            })
            .ToArray();

        await context.Studios.AddRangeAsync(studios);
        await context.SaveChangesAsync();

        return studios;
    }

    private static async Task<Genre[]> CreateGenresAsync(ApplicationContext context)
    {
        var genres = Enumerable.Range(1, 10)
            .Select(index => new Genre
            {
                Name = $"Genre{index}"
            })
            .ToArray();

        await context.Genres.AddRangeAsync(genres);
        await context.SaveChangesAsync();

        return genres;
    }

    private static async Task<Game[]> CreateGamesAsync(
        ApplicationContext context,
        Random random,
        IReadOnlyList<Genre> genres,
        IReadOnlyList<Studio> studios)
    {
        var startDate = new DateTime(1980, 01, 01);

        var games = Enumerable.Range(1, 30)
            .Select(index => new Game
            {
                Name = $"Game{index}",
                Genre = genres[random.Next(0, genres.Count)],
                Studio = studios[random.Next(0, studios.Count)],
                ReleaseDate = startDate.AddDays(random.Next((int)(DateTime.Now - startDate).TotalDays)).ToDateOnly(),
                SoldCopies = random.Next(100, 100000000),
                IsSingle = random.Next(0, 3) % 2 == 0
            })
            .ToArray();

        await context.Games.AddRangeAsync(games);
        await context.SaveChangesAsync();

        return games;
    }

    private static async Task<CityStudio[]> CreateCitiesStudiosAsync(
        ApplicationContext context,
        Random random,
        IReadOnlyList<City> cities,
        IReadOnlyList<Studio> studios)
    {
        var citiesStudios = Enumerable.Range(1, 20)
            .Select(index => new CityStudio()
            {
                CityId = cities[index - 1].Id,
                StudioId = studios[random.Next(0, studios.Count)].Id
            })
            .ToArray();

        await context.CitiesStudios.AddRangeAsync(citiesStudios);
        await context.SaveChangesAsync();

        return citiesStudios;
    }
}