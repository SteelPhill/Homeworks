using System.ComponentModel;

#pragma warning disable CS8618

namespace ASP_NET_Core_HW3.Models.Films;

public class ChangeFilmModel
{
    [DisplayName("Id")]
    public int FilmId { get; set; }

    [DisplayName("Название")]
    public string FilmTitle { get; set; }

    [DisplayName("Жанр")]
    public string Style { get; set; }

    [DisplayName("Режиссер")]
    public string Director { get; set; }

    [DisplayName("Описание")]
    public string Description { get; set; }
}