#pragma warning disable CS8618

namespace C_Sharp_SQL_HW2.Entities;

public class ProductType
{
	public int Id { get; set; }
	public string Name { get; set; }
	public ICollection<Product> Products { get; set; } = new List<Product>();
}