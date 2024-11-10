using System;

namespace ActualHomework;

public class BasementBuildingCommand : IMenuCommand
{
    private IWorker worker = new Worker();
    private IPart basement = new Basement();

    public string GetDiscription()
    {
        return "Залить фундамент";
    }

    public void Execute(Team team)
    {
        team.Build(worker, basement);

        Console.WriteLine($"\n\t{basement.GetTitle} залит");
        Console.ReadKey();

        if (team.House.IsBuilt())
            throw new HouseIsBuiltExeption();
    }
}