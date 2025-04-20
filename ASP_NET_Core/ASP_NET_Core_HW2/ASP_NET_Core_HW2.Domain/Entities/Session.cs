#pragma warning disable CS8618

namespace ASP_NET_Core_HW2.Domain.Entities;

public class Session
{
    public int Id { get; set; }
    public DateTime Begin { get; set; }
    public DateTime End { get; set; }
    public int FilmId { get; set; }
    public Film Film { get; set; }
    public bool IsDeleted { get; set; }
}