using ASP_NET_Core_HW2.Models.Sessions;
using System.ComponentModel;

#pragma warning disable CS8618

namespace ASP_NET_Core_HW2.Models.Films;

public class FilmModel
{
    [DisplayName("Id")]
    public int Id { get; set; }

    [DisplayName("Название")]
    public string Title { get; set; }

    [DisplayName("Сеансы")]
    public ICollection<SessionModel> Sessions { get; set; }
}