using System.ComponentModel;

#pragma warning disable CS8618

namespace ASP_NET_Core_HW3.Models.Films;

public class FilmDetailsModel
{
    [DisplayName("Фильм")]
    public FilmModel Film { get; set; }

    [DisplayName("Жанр")]
    public string Style { get; set; }

    [DisplayName("Режиссер")]
    public string Director { get; set; }

    [DisplayName("Описание")]
    public string Description { get; set; }
}