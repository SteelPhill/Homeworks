using System.ComponentModel.DataAnnotations;
using System.ComponentModel;

#pragma warning disable CS8618

namespace ASP_NET_Core_HW2.Models.Sessions;

public class SessionModel
{
    [DisplayName("Id")]
    public int Id { get; set; }

    [DisplayName("Начало сеанса")]
    [DataType(DataType.Date)]
    public DateTime Begin { get; set; }

    [DisplayName("Конец сеанса")]
    [DataType(DataType.Date)]
    public DateTime End { get; set; }

    [DisplayName("Фильм")]
    public int FilmId { get; set; }

    [DisplayName("Фильм")]
    public string FilmTitle { get; set; }
}