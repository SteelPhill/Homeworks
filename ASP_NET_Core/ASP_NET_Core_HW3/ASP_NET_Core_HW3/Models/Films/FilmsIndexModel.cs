#pragma warning disable CS8618

namespace ASP_NET_Core_HW3.Models.Films;

public class FilmsIndexModel
{
    public string? SearchTitle { get; set; }
    public string? SearchStyle { get; set; }
    public string? SearchDirector { get; set; }
    public string? SearchSession { get; set; }
    public FilmModel[] Films { get; set; }
}