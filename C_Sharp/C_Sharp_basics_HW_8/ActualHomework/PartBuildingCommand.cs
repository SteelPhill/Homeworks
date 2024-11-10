namespace ActualHomework;

public class PartBuildingCommand : IMenuCommand
{
    private IMenu buildingMenu;

    public PartBuildingCommand()
    {
        buildingMenu = new ConsoleMenu("\"Варианты работ\"");
        buildingMenu.AddComand(new BasementBuildingCommand());
        buildingMenu.AddComand(new WallBuildingCommand());
        buildingMenu.AddComand(new RoofBuildingCommand());
        buildingMenu.AddComand(new DoorBuildingCommand());
        buildingMenu.AddComand(new WindowBuildingCommand());        
    }

    public string GetDiscription()
    {
        return "Выполнить строительные работы";
    }

    public void Execute(Team team)
    {
        buildingMenu.Start(team);
    }
}