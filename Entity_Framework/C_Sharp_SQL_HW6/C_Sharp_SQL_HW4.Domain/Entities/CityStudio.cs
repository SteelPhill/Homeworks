#pragma warning disable CS8618

namespace C_Sharp_SQL_HW4.Domain.Entities;

public class CityStudio
{
    public int CityId { get; set; }
    public City City { get; set; }
    public int StudioId { get; set; }
    public Studio Studio { get; set; }
}