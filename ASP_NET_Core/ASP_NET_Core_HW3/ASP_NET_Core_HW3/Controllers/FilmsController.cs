using ASP_NET_Core_HW3.Database.Context.Factory;
using ASP_NET_Core_HW3.Domain.Entities;
using ASP_NET_Core_HW3.Extensions.Models;
using ASP_NET_Core_HW3.Models.Films;
using ASP_NET_Core_HW3.Models.Sessions;
using Microsoft.AspNetCore.Mvc;

namespace ASP_NET_Core_HW3.Controllers;

public class FilmsController : Controller
{
    private readonly IApplicationContextFactory _applicationContextFactory;
    private readonly ILogger<FilmsController> _logger;

    public FilmsController(
        IApplicationContextFactory applicationContextFactory,
        ILogger<FilmsController> logger)
    {
        _applicationContextFactory = applicationContextFactory;
        _logger = logger;
    }

    public IActionResult Index()
    {
        var context = _applicationContextFactory.Create();

        var films = context.Films
            .Where(f => !f.IsDeleted)
            .Select(f => f.ToModel())
            .ToArray();

        return View(new FilmsIndexModel { Films = films });
    }

    [HttpGet("[controller]/[action]/{id:int}")]
    public IActionResult Details([FromRoute] int id)
    {
        var context = _applicationContextFactory.Create();
        var film = context.Films
            .FirstOrDefault(f => f.Id == id && !f.IsDeleted);

        if (film == null)
            return NotFound();

        return View(film.ToDetailsModel());
    }

    [HttpGet]
    public IActionResult Create()
    {
        return View();
    }

    [HttpPost]
    public IActionResult Create([FromForm] ChangeFilmModel model)
    {
        if (!ModelState.IsValid)
            return View(model);

        var context = _applicationContextFactory.Create();

        var newFilm = new Film
        {
            Id = context.Films.Max(f => f.Id) + 1,
            Title = model.FilmTitle,
            Style = model.Style,
            Director = model.Director,
            Description = model.Description
        };

        context.Films.Add(newFilm);

        return RedirectToAction("Index", "Films");
    }

    [HttpGet("[controller]/[action]/{id:int}")]
    public IActionResult Edit([FromRoute] int id)
    {
        var context = _applicationContextFactory.Create();
        var film = context.Films
            .FirstOrDefault(f => f.Id == id && !f.IsDeleted);

        if (film == null)
            return NotFound();

        return View(film.ToChangeModel());
    }

    [HttpPost("[controller]/[action]/{id:int}")]
    public IActionResult Edit([FromRoute] int id, [FromForm] ChangeFilmModel model)
    {
        if (!ModelState.IsValid)
            return View(model);

        var context = _applicationContextFactory.Create();
        var film = context.Films
            .FirstOrDefault(f => f.Id == id && !f.IsDeleted);

        if (film == null)
            return NotFound();

        film.Title = model.FilmTitle;
        film.Style = model.Style;
        film.Director = model.Director;
        film.Description = model.Description;

        return RedirectToAction("Index", "Films");
    }

    [HttpGet("[controller]/[action]/{id:int}")]
    public IActionResult Delete([FromRoute] int id)
    {
        var context = _applicationContextFactory.Create();
        var film = context.Films
            .FirstOrDefault(f => f.Id == id && !f.IsDeleted);

        if (film == null)
            return NotFound();

        return View(film.ToChangeModel());
    }

    [HttpPost("[controller]/[action]/{id:int}")]
    public IActionResult DeleteConfirmed([FromRoute] int id)
    {
        var context = _applicationContextFactory.Create();
        var film = context.Films
            .FirstOrDefault(f => f.Id == id && !f.IsDeleted);

        if (film == null)
            return NotFound();

        film.IsDeleted = true;

        return RedirectToAction("Index", "Films");
    }

    [HttpGet]
    public IActionResult Search(
        [FromQuery] string searchTitle,
        [FromQuery] string searchStyle,
        [FromQuery] string searchDirector,
        [FromQuery] string searchSession)
    {
        if (string.IsNullOrWhiteSpace(searchTitle) &&
            string.IsNullOrWhiteSpace(searchStyle) &&
            string.IsNullOrWhiteSpace(searchDirector) &&
            string.IsNullOrWhiteSpace(searchSession))
        {
            return View("Index", "Films");
        }

        var context = _applicationContextFactory.Create();

        var filmsQuire = context.Films
            .Where(f => !f.IsDeleted)
            .AsQueryable();

        if (!string.IsNullOrWhiteSpace(searchTitle))
            filmsQuire = filmsQuire.Where(f => f.Title.Contains(searchTitle, StringComparison.OrdinalIgnoreCase));
        if (!string.IsNullOrWhiteSpace(searchStyle))
            filmsQuire = filmsQuire.Where(f => f.Style.Contains(searchStyle, StringComparison.OrdinalIgnoreCase));
        if (!string.IsNullOrWhiteSpace(searchDirector))
            filmsQuire = filmsQuire.Where(f => f.Director.Contains(searchDirector, StringComparison.OrdinalIgnoreCase));
        if (!string.IsNullOrWhiteSpace(searchSession))
            filmsQuire = filmsQuire.Where(f => f.Sessions.Any(s =>
                s.Begin.ToString().Contains(searchSession, StringComparison.OrdinalIgnoreCase) ||
                s.End.ToString().Contains(searchSession, StringComparison.OrdinalIgnoreCase)));

        var films = filmsQuire.Select(f => f.ToModel()).ToArray();

        return View("Index", new FilmsIndexModel
        {
            SearchTitle = searchTitle,
            SearchStyle = searchStyle,
            SearchDirector = searchDirector,
            SearchSession = searchSession,
            Films = films
        });
    }

    [HttpGet("[controller]/[action]/{id:int}")]
    public IActionResult SessionsManagement([FromRoute] int id)
    {
        var context = _applicationContextFactory.Create();

        var film = context.Films
            .FirstOrDefault(f => f.Id == id && !f.IsDeleted);

        if (film == null)
            return NotFound();

        return View(new SessionManagementModel
        { 
            FilmId = id,
            FilmTitle = film.Title,
            Sessions = film.Sessions
                .Where(s => !s.IsDeleted)
                .Select(s => s.ToModel())
                .ToList()
        });
    }

    [HttpPost("[controller]/[action]/{id:int}")]
    public IActionResult CreateSession([FromRoute] int id, [FromForm] SessionManagementModel model)
    {
        var context = _applicationContextFactory.Create();
        var film = context.Films.FirstOrDefault(f => f.Id == id && !f.IsDeleted);

        if (film == null)
            return NotFound();

        if (!ModelState.IsValid)
        {
            return View("SessionsManagement", new SessionManagementModel
            {
                FilmId = id,
                FilmTitle = film.Title,
                Sessions = film.Sessions
                    .Where(s => !s.IsDeleted)
                    .Select(s => s.ToModel())
                    .ToList(),
                Begin = model.Begin,
                End = model.End
            });
        }

        var session = new Session
        {
            Id = context.Sessions.Max(f => f.Id) + 1,
            Begin = model.Begin!.Value,
            End = model.End!.Value,
            FilmId = id,
            Film = film
        };

        context.Sessions.Add(session);
        film.Sessions.Add(session);

        return RedirectToAction("SessionsManagement", new { id });
    }

    [HttpPost("[controller]/[action]/{filmId:int}/{sessionId:int}")]
    public IActionResult DeleteSession([FromRoute] int filmId, [FromRoute] int sessionId)
    {
        var context = _applicationContextFactory.Create();

        var film = context.Films
            .FirstOrDefault(f => f.Id == filmId && !f.IsDeleted);

        if (film == null)
            return NotFound();

        var session = context.Sessions
            .FirstOrDefault(s => s.Id == sessionId && !s.IsDeleted);

        if (session == null)
            return NotFound();

        session.IsDeleted = true;

        return RedirectToAction("SessionsManagement", new { id = filmId });
    }
}