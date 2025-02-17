using C_Sharp_SQL_HW4.Domain.Entities;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;

namespace C_Sharp_SQL_HW4.Database.Context;

public class ApplicationContext : DbContext
{
	private static readonly string LogFileName = $"logs\\log-{DateTime.Now:yyyy-MM-dd_HH-mm-ss}.txt";

	public DbSet<City> Cities => Set<City>();
    public DbSet<Country> Countries => Set<Country>();
    public DbSet<Game> Games => Set<Game>();
    public DbSet<Genre> Genres => Set<Genre>();
    public DbSet<Studio> Studios => Set<Studio>();
    public DbSet<CityStudio> CitiesStudios => Set<CityStudio>();

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
        #region Country

        modelBuilder.Entity<Country>()
            .HasIndex(c => c.Name)
            .IsUnique();

        modelBuilder.Entity<Country>()
			.ToTable(t => t.HasCheckConstraint(
				"CK_Country_Name", 
				"LEN(Name) > 0"));

        #endregion

        #region City

        modelBuilder.Entity<City>()
            .HasOne(c => c.Country)
            .WithMany(c => c.Cities)
            .HasForeignKey(c => c.CountryId)
            .OnDelete(DeleteBehavior.Cascade);

        modelBuilder.Entity<City>()
            .HasIndex(c => c.Name)
            .IsUnique();

        modelBuilder.Entity<City>()
            .ToTable(t => t.HasCheckConstraint(
                "CK_City_Name",
                "LEN(Name) > 0"));

        #endregion

        #region Game

        modelBuilder.Entity<Game>()
            .HasOne(g => g.Studio)
            .WithMany(s => s.Games)
            .HasForeignKey(g => g.StudioId)
            .OnDelete(DeleteBehavior.Cascade);

        modelBuilder.Entity<Game>()
            .HasOne(g => g.Genre)
            .WithMany(g => g.Games)
            .HasForeignKey(g => g.GenreId)
            .OnDelete(DeleteBehavior.Cascade);

        modelBuilder.Entity<Game>()
            .HasIndex(g => g.Name)
            .IsUnique();

        modelBuilder.Entity<Game>()
            .ToTable(t => t.HasCheckConstraint(
                "CK_Game_Name",
                "LEN(Name) > 0"));

        modelBuilder.Entity<Game>()
            .ToTable(t => t.HasCheckConstraint(
                "CK_Game_SoldCopies",
                "SoldCopies >= 0"))
            .Property(g => g.SoldCopies)
            .HasDefaultValue(0);

        #endregion

        #region Genre

        modelBuilder.Entity<Genre>()
           .HasIndex(g => g.Name)
           .IsUnique();

        modelBuilder.Entity<Genre>()
            .ToTable(t => t.HasCheckConstraint(
                "CK_Genre_Name",
                "LEN(Name) > 0"));

        #endregion

        #region Studio

        modelBuilder.Entity<Studio>()
            .HasIndex(s => s.Name)
            .IsUnique();

        modelBuilder.Entity<Studio>()
            .ToTable(t => t.HasCheckConstraint(
                "CK_Studio_Name",
                "LEN(Name) > 0"));

        #endregion

        #region StudioCity

        modelBuilder.Entity<CityStudio>()
            .HasKey(c => new { c.CityId, c.StudioId });

        modelBuilder.Entity<CityStudio>()
            .HasOne(c => c.City)
            .WithMany(c => c.CitiesStudios)
            .HasForeignKey(c => c.CityId);

        modelBuilder.Entity<CityStudio>()
            .HasOne(c => c.Studio)
            .WithMany(s => s.CitiesStudios)
            .HasForeignKey(c => c.StudioId);

        #endregion
    }
}