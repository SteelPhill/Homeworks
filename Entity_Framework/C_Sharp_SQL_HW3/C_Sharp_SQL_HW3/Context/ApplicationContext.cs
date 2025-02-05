using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;
using C_Sharp_SQL_HW3.Entities;

namespace C_Sharp_SQL_HW3.Context;

public class ApplicationContext : DbContext
{
	private static readonly string LogFileName = $"logs\\log-{DateTime.Now:yyyy-MM-dd_HH-mm-ss}.txt";

	public DbSet<Company> Companies => Set<Company>();
	public DbSet<Manager> Managers => Set<Manager>();
	public DbSet<Stationery> Stationeries => Set<Stationery>();
	public DbSet<StationeryType> StationeryTypes => Set<StationeryType>();

	protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
	{
		optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=StationeryCompany;Integrated Security=True;Connect Timeout=30;Encrypt=False;Trust Server Certificate=False;Application Intent=ReadWrite;Multi Subnet Failover=False");
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

		modelBuilder.Entity<Stationery>()
			.HasOne(s => s.BuyerCompany)
			.WithMany(c => c.Stationeries)
			.HasForeignKey(s => s.BuyerCompanyId)
			.OnDelete(DeleteBehavior.Cascade);

		modelBuilder.Entity<Stationery>()
			.HasOne(s => s.SellingManager)
			.WithMany(m => m.Stationeries)
			.HasForeignKey(s => s.SellingManagerId)
			.OnDelete(DeleteBehavior.Cascade);

		modelBuilder.Entity<Stationery>()
			.HasOne(s => s.StationeryType)
			.WithMany(t => t.Stationeries)
			.HasForeignKey(s => s.StationeryTypeId)
			.OnDelete(DeleteBehavior.Cascade);

		modelBuilder.Entity<Stationery>()
			.HasIndex(s => s.Name)
			.IsUnique();

		modelBuilder.Entity<Stationery>()
			.ToTable(t => t.HasCheckConstraint(
				"CK_Stationeries_Name",
				"LEN(Name) > 0"));

		modelBuilder.Entity<Stationery>()
			.ToTable(t => t.HasCheckConstraint(
				"CK_Stationeries_Count",
				"Count > 0"));

		modelBuilder.Entity<Stationery>()
			.ToTable(t => t.HasCheckConstraint(
				"CK_Stationeries_Price",
				"Price > 0"));

		modelBuilder.Entity<Stationery>()
			.ToTable(t => t.HasCheckConstraint(
				"CK_Stationeries_SellingCount", 
				"SellingCount IS NULL OR SellingCount > 0"));

		modelBuilder.Entity<Stationery>()
			.ToTable(t => t.HasCheckConstraint(
				"CK_Stationeries_SellingPrice",
				"SellingPrice IS NULL OR SellingPrice > 0"));

		modelBuilder.Entity<Company>()
			.HasIndex(c => c.Name)
			.IsUnique();

		modelBuilder.Entity<Company>()
			.ToTable(t => t.HasCheckConstraint(
				"CK_Companies_Name", 
				"LEN(Name) > 0"));

		modelBuilder.Entity<Manager>()
			.HasIndex(m => m.Name)
			.IsUnique();

		modelBuilder.Entity<Manager>()
			.ToTable(t => t.HasCheckConstraint(
				"CK_Managers_Name", 
				"LEN(Name) > 0"));

		modelBuilder.Entity<StationeryType>()
			.HasIndex(s => s.Name)
			.IsUnique();

		modelBuilder.Entity<StationeryType>()
			.ToTable(t => t.HasCheckConstraint(
				"CK_StationeryTypes_Name",
				"LEN(Name) > 0"));

        modelBuilder.Entity<Company>()
			.Property(c => c.IsDeleted)
			.IsRequired()
			.HasColumnType("bit");

        modelBuilder.Entity<Manager>()
            .Property(m => m.IsDeleted)
            .IsRequired()
            .HasColumnType("bit");

		modelBuilder.Entity<Stationery>()
		   .Property(s => s.IsDeleted)
		   .IsRequired()
		   .HasColumnType("bit");

        modelBuilder.Entity<StationeryType>()
           .Property(t => t.IsDeleted)
           .IsRequired()
           .HasColumnType("bit");
    }
}