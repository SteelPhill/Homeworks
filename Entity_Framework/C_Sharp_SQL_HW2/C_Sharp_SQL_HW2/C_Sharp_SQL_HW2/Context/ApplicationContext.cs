using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;
using C_Sharp_SQL_HW2.Entities;

namespace C_Sharp_SQL_HW2.Context;

public class ApplicationContext : DbContext
{
	private static readonly string LogFileName = $"logs\\log-{DateTime.Now:yyyy-MM-dd_HH-mm-ss}.txt";

	public DbSet<Product> Products => Set<Product>();
	public DbSet<ProductType> ProductTypes => Set<ProductType>();
	public DbSet<ProductSupplier> ProductSuppliers => Set<ProductSupplier>();

	protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
	{
		optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Storage;Integrated Security=True;Connect Timeout=30;Encrypt=False;Trust Server Certificate=False;Application Intent=ReadWrite;Multi Subnet Failover=False");
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

		modelBuilder.Entity<Product>()
			.Property(t => t.Date)
			.HasColumnType("date");

		modelBuilder.Entity<Product>()
			.HasOne(s => s.ProductType)
			.WithMany(g => g.Products)
			.HasForeignKey(s => s.ProductTypeId)
			.OnDelete(DeleteBehavior.Cascade);

		modelBuilder.Entity<Product>()
			.HasOne(s => s.ProductSupplier)
			.WithMany(g => g.Products)
			.HasForeignKey(s => s.ProductSupplierId)
			.OnDelete(DeleteBehavior.Cascade);

        modelBuilder.Entity<Product>()
			.ToTable(t => t.HasCheckConstraint("CK_Products_Name", "LEN(Name) > 0"));

		modelBuilder.Entity<Product>()
			.ToTable(t => t.HasCheckConstraint("CK_Products_Count", "Count > 0"));

		modelBuilder.Entity<Product>()
			.ToTable(t => t.HasCheckConstraint("CK_Products_Price", "Price > 0"));

		modelBuilder.Entity<ProductType>()
			.ToTable(t => t.HasCheckConstraint("CK_ProductTypes_Name", "LEN(Name) > 0"));

		modelBuilder.Entity<ProductSupplier>()
			.ToTable(t => t.HasCheckConstraint("CK_ProductSuppliers_Name", "LEN(Name) > 0"));
	}
}