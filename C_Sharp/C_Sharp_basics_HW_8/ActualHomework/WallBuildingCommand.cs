using System;

namespace ActualHomework;

public class WallBuildingCommand : IMenuCommand
{
    private IWorker worker = new Worker();
    private IPart wall = new Wall();

    public string GetDiscription()
    {
        return "Возвести стену";
    }

    public void Execute(Team team)
    {
        team.Build(worker, wall);

        Console.WriteLine(
            $"\n\t{wall.GetTitle} возведена");
        Console.ReadKey();

        if (team.House.IsBuilt())
            throw new HouseIsBuiltExeption();
    }
}