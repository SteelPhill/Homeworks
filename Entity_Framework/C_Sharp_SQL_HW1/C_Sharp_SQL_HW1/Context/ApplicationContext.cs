using C_Sharp_SQL_HW1.Entities;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;

namespace C_Sharp_SQL_HW1.Context;

public class ApplicationContext : DbContext
{
    private static readonly string LogFileName = $"logs\\log-{DateTime.Now:yyyy-MM-dd_HH-mm-ss}.txt";

    public DbSet<Fruit> Fruits => Set<Fruit>();

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=VegetablesAndFruits;Integrated Security=True;Connect Timeout=30;Encrypt=False;Trust Server Certificate=False;Application Intent=ReadWrite;Multi Subnet Failover=False");
        optionsBuilder.LogTo(LogMessage, LogLevel.Information);
    }

    private static void LogMessage(string message)
    {
        var oldColor = Console.ForegroundColor;
        Console.ForegroundColor = ConsoleColor.DarkGray;
        Console.WriteLine(message);
        Console.ForegroundColor = oldColor;

        var logFileDirectory = Path.GetDirectoryName(LogFileName);
        if (!string.IsNullOrEmpty(logFileDirectory))
            Directory.CreateDirectory(logFileDirectory);

        File.AppendAllText(LogFileName, message);
    }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        base.OnModelCreating(modelBuilder);

        modelBuilder.Entity<Fruit>()
            .ToTable(t => t.HasCheckConstraint("CK_Fruits_Name", "LEN(Name) > 0"));

        modelBuilder.Entity<Fruit>()
            .ToTable(t => t.HasCheckConstraint("CK_Fruits_Color", "LEN(Color) > 0"));

        modelBuilder.Entity<Fruit>()
            .ToTable(t => t.HasCheckConstraint("CK_Fruits_Calories", "Calories > 0"));

        modelBuilder.Entity<Fruit>()
            .ToTable(t => t.HasCheckConstraint("CK_Fruits_Type", "Type = 0 OR Type = 1"));
    }
}