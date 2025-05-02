using ASP_NET_Core_HW3.Domain.Entities;
using ASP_NET_Core_HW3.Models.Sessions;

namespace ASP_NET_Core_HW3.Extensions.Models;

public static class SessionExtensions
{
    public static SessionModel ToModel(this Session session)
    {
        return new SessionModel
        {
            Id = session.Id,
            Begin = session.Begin,
            End = session.End,
            FilmId = session.FilmId,
            FilmTitle = session.Film.Title
        };
    }
}