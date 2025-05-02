using System.ComponentModel.DataAnnotations;
using System.ComponentModel;

#pragma warning disable CS8618

namespace ASP_NET_Core_HW3.Models.Sessions;

public class SessionManagementModel
{
    [DisplayName("Начало сеанса")]
    [DataType(DataType.DateTime)]
    [Required(ErrorMessage = "Укажите время начала сеанса")]
    public DateTime? Begin { get; set; }

    [DisplayName("Конец сеанса")]
    [DataType(DataType.DateTime)]
    [Required(ErrorMessage = "Укажите время окончания сеанса")]
    [CustomValidation(typeof(SessionManagementModel), "ValidateEndTime")]
    public DateTime? End { get; set; }

    [DisplayName("Фильм")]
    public int? FilmId { get; set; }

    [DisplayName("Фильм")]
    public string? FilmTitle { get; set; }

    [DisplayName("Сеансы")]
    public ICollection<SessionModel>? Sessions { get; set; }

    public static ValidationResult ValidateEndTime(DateTime? end, ValidationContext context)
    {
        var model = (SessionManagementModel)context.ObjectInstance;

        if (end <= model.Begin)
            return new ValidationResult("Время окончания должно быть позже времени начала");
 
        return ValidationResult.Success!;
    }
}