#pragma warning disable CS8618

namespace C_Sharp_SQL_HW4.Domain.Entities;

public class Game
{
	public int Id { get; set; }
	public string Name { get; set; }
	public string Studio { get; set; }
    public string Genre { get; set; }
    public DateOnly ReleaseDate { get; set; }
    public int SoldCopies { get; set; }
    public bool IsSingle { get; set; }
    public bool IsDeleted { get; set; }
}