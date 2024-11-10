namespace ActualHomework;

public class WorkerOptionsCommand : IMenuCommand
{
    private IMenu menu;

    public WorkerOptionsCommand()
    {
        menu = new ConsoleMenu("\"Опции строителя\"");
        menu.AddComand(new PartBuildingCommand());
        menu.AddComand(new ViewWhatBeenBuiltCommand());
    }

    public string GetDiscription()
    {
        return "Опции строителя";
    }

    public void Execute(Team team)
    {
        menu.Start(team);
    }
}