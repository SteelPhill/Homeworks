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

        var games = await CreateGamesAsync(context, random);
    }

	private static async Task ClearTablesAsync(ApplicationContext context)
	{
        if (!await context.Games.AnyAsync())
            return;

        await context.Games.ExecuteDeleteAsync();

        await context.Database.ExecuteSqlRawAsync("DBCC CHECKIDENT ('Games', RESEED, 0);");
	}

    private static async Task<Game[]> CreateGamesAsync(ApplicationContext context, Random random)
	{
        var startDate = new DateTime(1980, 01, 01);
        var gameNumber = 30;
        var studioNumber = 20;
        var genreNumber = 10;

        var games = Enumerable.Range(1, gameNumber)
            .Select(index => new Game
            {
                Name = $"Game{index}",
                Studio = $"Studio{random.Next(1, studioNumber + 1)}",
                Genre = $"Genre{random.Next(1, genreNumber + 1)}",
                ReleaseDate = startDate.AddDays(random.Next((int)(DateTime.Now - startDate).TotalDays)).ToDateOnly(),
                SoldCopies = random.Next(100, 100000000),
                IsSingle = random.Next(0, 3) % 2 == 0
            })
            .ToArray();

        await context.Games.AddRangeAsync(games);
        await context.SaveChangesAsync();

        return games;
    }
}