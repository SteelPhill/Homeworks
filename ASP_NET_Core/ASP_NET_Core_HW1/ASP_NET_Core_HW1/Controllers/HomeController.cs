using System.Diagnostics;
using ASP_NET_Core_HW1.Models;
using Microsoft.AspNetCore.Mvc;

namespace ASP_NET_Core_HW1.Controllers;

public class HomeController : Controller
{
    private readonly ILogger<HomeController> _logger;

    private static readonly string Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static readonly Random random = new();

    public HomeController(ILogger<HomeController> logger)
    {
        _logger = logger;
    }

    public IActionResult Privacy()
    {
        return View();
    }

    public IActionResult Task1()
    {
        return View(new Task1Model { CurrentDayNumber = DateTime.Now.DayOfYear });
    }

    public IActionResult Task2()
    {
        return View(new Task2Model { Letter = Letters[random.Next(Letters.Length)] });
    }

    public IActionResult Task3()
    {
        return View();
    }

    public IActionResult Task4()
    {
        return View();
    }

    public IActionResult Task5()
    {
        return View();
    }

    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    }
}