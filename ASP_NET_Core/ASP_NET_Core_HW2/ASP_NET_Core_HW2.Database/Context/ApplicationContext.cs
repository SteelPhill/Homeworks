using ASP_NET_Core_HW2.Database.Extensions;
using ASP_NET_Core_HW2.Domain.Entities;

namespace ASP_NET_Core_HW2.Database.Context;

public class ApplicationContext
{
    private readonly string LogFileName = $"logs\\log-{DateTime.Now:yyyy-MM-dd_HH-mm-ss}.txt";

    public IList<Film> Films = new List<Film>();
    public IList<Session> Sessions = new List<Session>();

    public ApplicationContext()
    {
        Films.Add(new Film
        { 
            Id = 1, 
            Title = "Фильм1",
            Style = "Жанр1",
            Director = "Режиссер1", 
            Description = "Описание1"
        });
        Films.Add(new Film
        {
            Id = 2,
            Title = "Фильм2",
            Style = "Жанр2",
            Director = "Режиссер2",
            Description = "Описание2"
        });
        Films.Add(new Film
        {
            Id = 3,
            Title = "Фильм3",
            Style = "Жанр3",
            Director = "Режиссер3",
            Description = "Описание3"
        });
        Films.Add(new Film
        {
            Id = 4,
            Title = "Фильм4",
            Style = "Жанр4",
            Director = "Режиссер4",
            Description = "Описание4"
        });
        Films.Add(new Film
        {
            Id = 5,
            Title = "Фильм5",
            Style = "Жанр3",
            Director = "Режиссер5",
            Description = "Описание5"
        });
        Films.Add(new Film
        {
            Id = 6,
            Title = "Фильм6",
            Style = "Жанр6",
            Director = "Режиссер1",
            Description = "Описание6"
        });

        Sessions.Add(new Session
        { 
            Id = 1, 
            Begin = DateTime.Now, 
            End = DateTime.Now.AddHours(2), 
            FilmId = Films[0].Id, 
            Film = Films[0]
        });
        Sessions.Add(new Session
        { 
            Id = 2, 
            Begin = DateTime.Now.AddHours(1), 
            End = DateTime.Now.AddHours(3), 
            FilmId = Films[0].Id, 
            Film = Films[0]
        });
        Sessions.Add(new Session 
        { 
            Id = 3, 
            Begin = DateTime.Now.AddHours(2),
            End = DateTime.Now.AddHours(4),
            FilmId = Films[2].Id,
            Film = Films[2] 
        });
        Sessions.Add(new Session
        { 
            Id = 4,
            Begin = DateTime.Now.AddHours(3),
            End = DateTime.Now.AddHours(5), 
            FilmId = Films[3].Id,
            Film = Films[3]
        });
        Sessions.Add(new Session
        { 
            Id = 5, 
            Begin = DateTime.Now.AddHours(4), 
            End = DateTime.Now.AddHours(6), 
            FilmId = Films[4].Id, 
            Film = Films[4] 
        });
        Sessions.Add(new Session
        { 
            Id = 6,
            Begin = DateTime.Now.AddHours(5), 
            End = DateTime.Now.AddHours(7),
            FilmId = Films[5].Id, 
            Film = Films[5] 
        });
        Sessions.Add(new Session
        {
            Id = 7,
            Begin = DateTime.Now,
            End = DateTime.Now.AddHours(2),
            FilmId = Films[0].Id,
            Film = Films[0]
        });
        Sessions.Add(new Session
        {
            Id = 8,
            Begin = DateTime.Now.AddHours(1),
            End = DateTime.Now.AddHours(3),
            FilmId = Films[2].Id,
            Film = Films[2]
        });
        Sessions.Add(new Session
        {
            Id = 9,
            Begin = DateTime.Now.AddHours(2),
            End = DateTime.Now.AddHours(4),
            FilmId = Films[3].Id,
            Film = Films[3]
        });
        Sessions.Add(new Session
        {
            Id = 10,
            Begin = DateTime.Now.AddHours(3),
            End = DateTime.Now.AddHours(5),
            FilmId = Films[5].Id,
            Film = Films[5]
        });
        Sessions.Add(new Session
        {
            Id = 11,
            Begin = DateTime.Now.AddHours(4),
            End = DateTime.Now.AddHours(6),
            FilmId = Films[5].Id,
            Film = Films[5]
        });
        Sessions.Add(new Session
        {
            Id = 12,
            Begin = DateTime.Now.AddHours(5),
            End = DateTime.Now.AddHours(7),
            FilmId = Films[0].Id,
            Film = Films[0]
        });

        Films[0].Sessions = Sessions.Where(s => s.FilmId == 1).ToList();
        Films[1].Sessions = Sessions.Where(s => s.FilmId == 2).ToList();
        Films[2].Sessions = Sessions.Where(s => s.FilmId == 3).ToList();
        Films[3].Sessions = Sessions.Where(s => s.FilmId == 4).ToList();
        Films[4].Sessions = Sessions.Where(s => s.FilmId == 5).ToList();
        Films[5].Sessions = Sessions.Where(s => s.FilmId == 6).ToList();
    }

    public void LogMessage(string message)
    {
        LogMessageAsync(message).FireAndForgetSafeAsync();
    }

    private async Task LogMessageAsync(string message)
    {
        var logFileDirectory = Path.GetDirectoryName(LogFileName);
        if (!string.IsNullOrEmpty(logFileDirectory))
            Directory.CreateDirectory(logFileDirectory);

        await File.AppendAllTextAsync(LogFileName, message);
    }
}