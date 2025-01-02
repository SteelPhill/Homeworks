#pragma warning disable CS8618

namespace C_Sharp_SQL_HW2.Entities;

public class Product
{
	public int Id { get; set; }
	public string Name { get; set; }
	public int Count { get; set; }
	public int Price { get; set; }
	public DateTime Date { get; set; }
	public int ProductTypeId { get; set; }
	public ProductType ProductType { get; set; }
	public int ProductSupplierId { get; set; }
	public ProductSupplier ProductSupplier { get; set; }
}