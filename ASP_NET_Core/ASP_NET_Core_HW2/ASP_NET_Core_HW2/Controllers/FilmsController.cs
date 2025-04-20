using ASP_NET_Core_HW2.Database.Context.Factory;
using ASP_NET_Core_HW2.Domain.Entities;
using ASP_NET_Core_HW2.Extensions.Models;
using ASP_NET_Core_HW2.Models.Films;
using Microsoft.AspNetCore.Mvc;

namespace ASP_NET_Core_HW2.Controllers;

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
            .Select(f => f.ToModel())
            .ToArray();

        return View(new FilmsIndexModel { Films = films });
    }

    [HttpGet("[controller]/[action]/{id:int}")]
    public IActionResult Details([FromRoute] int id)
    {
        var context = _applicationContextFactory.Create();

        var film = context.Films
            .FirstOrDefault(f => f.Id == id);

        if (film == null)
            return NotFound();

        return View(film.ToDetailsModel());
    }
}