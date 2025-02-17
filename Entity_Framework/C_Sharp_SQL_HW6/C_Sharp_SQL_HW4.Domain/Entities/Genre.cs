#pragma warning disable CS8618

namespace C_Sharp_SQL_HW4.Domain.Entities;

public class Genre
{
    public int Id { get; set; }
    public string Name { get; set; }
    public ICollection<Game> Games { get; set; } = new List<Game>();
    public bool IsDeleted { get; set; }
}