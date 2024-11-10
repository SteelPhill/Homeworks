namespace ActualHomework;

public class ViewReportCommand : IMenuCommand
{
    public string GetDiscription()
    {
        return "Посмотреть отчёт";
    }

    public void Execute(Team team)
    {
        team.PrintWhatBeenBuild();
    }
}