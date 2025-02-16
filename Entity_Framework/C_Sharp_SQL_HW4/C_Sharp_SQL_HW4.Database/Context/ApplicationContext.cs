using C_Sharp_SQL_HW4.Domain.Entities;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;

namespace C_Sharp_SQL_HW4.Database.Context;

public class ApplicationContext : DbContext
{
	private static readonly string LogFileName = $"logs\\log-{DateTime.Now:yyyy-MM-dd_HH-mm-ss}.txt";

    public DbSet<Game> Games => Set<Game>();

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
	{
		optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=GameDB;Integrated Security=True;Connect Timeout=30;Encrypt=False;Trust Server Certificate=False;Application Intent=ReadWrite;Multi Subnet Failover=False");
		optionsBuilder.LogTo(LogMessage, LogLevel.Information);
	}

	private static void LogMessage(string message)
	{
		//var oldColor = Console.ForegroundColor;
		//Console.ForegroundColor = ConsoleColor.DarkGray;
		//Console.WriteLine(message);
		//Console.ForegroundColor = oldColor;

		var logFileDirectory = Path.GetDirectoryName(LogFileName);
		if (!string.IsNullOrEmpty(logFileDirectory))
			Directory.CreateDirectory(logFileDirectory);

		File.AppendAllText(LogFileName, message);
	}

	protected override void OnModelCreating(ModelBuilder modelBuilder)
	{
        #region Game

        modelBuilder.Entity<Game>()
            .HasIndex(g => g.Name)
            .IsUnique();

        modelBuilder.Entity<Game>()
            .ToTable(t => t.HasCheckConstraint(
                "CK_Game_Name",
                "LEN(Name) > 0"));

        modelBuilder.Entity<Game>()
           .ToTable(t => t.HasCheckConstraint(
               "CK_Game_Studio",
               "LEN(Studio) > 0"));

        modelBuilder.Entity<Game>()
           .ToTable(t => t.HasCheckConstraint(
               "CK_Game_Genre",
               "LEN(Genre) > 0"));

        modelBuilder.Entity<Game>()
            .ToTable(t => t.HasCheckConstraint(
                "CK_Game_SoldCopies",
                "SoldCopies >= 0"))
            .Property(g => g.SoldCopies)
            .HasDefaultValue(0);

        #endregion
    }
}