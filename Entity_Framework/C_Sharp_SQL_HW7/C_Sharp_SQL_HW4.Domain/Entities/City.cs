#pragma warning disable CS8618

namespace C_Sharp_SQL_HW4.Domain.Entities;

public class City
{
	public int Id { get; set; }
	public string Name { get; set; }
    public int CountryId { get; set; }
    public Country Country { get; set; }
    public ICollection<CityStudio> CitiesStudios { get; set; } = new List<CityStudio>();
    public bool IsDeleted { get; set; }
}