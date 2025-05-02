using ASP_NET_Core_HW3.Domain.Entities;
using ASP_NET_Core_HW3.Models.Films;

namespace ASP_NET_Core_HW3.Extensions.Models;

public static class FilmExtensions
{
    public static FilmModel ToModel(this Film film)
    {
        return new FilmModel
        {
            Id = film.Id,
            Title = film.Title,
            Sessions = film.Sessions
                .Where(s => !s.IsDeleted)
                .Select(s => s.ToModel())
                .ToArray()
        };
    }

    public static FilmDetailsModel ToDetailsModel(this Film film)
    {
        return new FilmDetailsModel
        {
            Film = film.ToModel(),
            Style = film.Style,
            Director = film.Director,
            Description = film.Description
        };
    }

    public static ChangeFilmModel ToChangeModel(this Film film)
    {
        return new ChangeFilmModel
        {
            FilmId = film.Id,
            FilmTitle = film.Title,
            Style = film.Style,
            Director = film.Director,
            Description = film.Description
        };
    }
}