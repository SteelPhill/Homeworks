#pragma warning disable CS8618

namespace C_Sharp_SQL_HW3.Entities;

public class Company
{
	public int Id { get; set; }
	public string Name { get; set; }
	public ICollection<Stationery> Stationeries { get; set; } = new List<Stationery>();
    public bool IsDeleted { get; set; }
}