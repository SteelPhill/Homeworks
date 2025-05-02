#pragma warning disable CS8618

namespace ASP_NET_Core_HW3.Domain.Entities;

public class Film
{
    public int Id { get; set; }
    public string Title { get; set; }
    public string Style { get; set; }
    public string Director { get; set; }
    public string Description { get; set; }
    public ICollection<Session> Sessions { get; set; } = new List<Session>();
    public bool IsDeleted { get; set; }
}