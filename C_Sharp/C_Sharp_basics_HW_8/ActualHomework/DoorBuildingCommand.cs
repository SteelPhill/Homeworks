using System;

namespace ActualHomework;

public class DoorBuildingCommand : IMenuCommand
{
    private IWorker worker = new Worker();
    private IPart door = new Door();

    public string GetDiscription()
    {
        return "Установить дверь";
    }

    public void Execute(Team team)
    {
        team.Build(worker, door);

        Console.WriteLine(
            $"\n\t {door.GetTitle} установлена");
        Console.ReadKey();

        if (team.House.IsBuilt())
            throw new HouseIsBuiltExeption();
    }
}