using ASP_NET_Core_HW2.Domain.Entities;
using ASP_NET_Core_HW2.Models.Films;

namespace ASP_NET_Core_HW2.Extensions.Models;

public static class FilmExtensions
{
    public static FilmModel ToModel(this Film film)
    {
        return new FilmModel
        {
            Id = film.Id,
            Title = film.Title,
            Sessions = film.Sessions.Select(s => s.ToModel()).ToArray()
        };
    }

    public static FilmDetailsModel ToDetailsModel(this Film film)
    {
        return new FilmDetailsModel
        {
            Id = film.Id,
            Film = film.ToModel(),
            Style = film.Style,
            Director = film.Director,
            Description = film.Description
        };
    }
}