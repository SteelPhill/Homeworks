using System;

namespace ActualHomework;

public class RoofBuildingCommand : IMenuCommand
{
    private IWorker worker = new Worker();
    private IPart roof = new Roof();

    public string GetDiscription()
    {
        return "Установить крышу";
    }

    public void Execute(Team team)
    {
        team.Build(worker, roof);

        Console.WriteLine(
            $"\n\t{roof.GetTitle} установлена");
        Console.ReadKey();

        if (team.House.IsBuilt())
            throw new HouseIsBuiltExeption();
    }
}