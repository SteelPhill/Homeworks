namespace ActualHomework;

public class TeamLeaderOptionsCommand : IMenuCommand
{
    private IMenu menu;

    public TeamLeaderOptionsCommand()
    {
        menu = new ConsoleMenu("\"Опции бригадира\"");
        menu.AddComand(new GenerateReportCommand());
    }

    public string GetDiscription()
    {
        return "Опции бригадира";
    }

    public void Execute(Team team)
    {
        menu.Start(team);
    }
}