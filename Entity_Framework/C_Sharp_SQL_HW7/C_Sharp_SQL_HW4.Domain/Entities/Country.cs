#pragma warning disable CS8618

namespace C_Sharp_SQL_HW4.Domain.Entities;

public class Country
{
    public int Id { get; set; }
    public string Name { get; set; }
    public ICollection<City> Cities { get; set; } = new List<City>();
    public bool IsDeleted { get; set; }
}