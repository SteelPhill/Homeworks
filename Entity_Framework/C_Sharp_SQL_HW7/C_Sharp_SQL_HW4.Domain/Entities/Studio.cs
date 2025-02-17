#pragma warning disable CS8618

namespace C_Sharp_SQL_HW4.Domain.Entities;

public class Studio
{
	public int Id { get; set; }
	public string Name { get; set; }
    public ICollection<Game> Games { get; set; } = new List<Game>();
    public ICollection<CityStudio> CitiesStudios { get; set; } = new List<CityStudio>();
    public bool IsDeleted { get; set; }
}