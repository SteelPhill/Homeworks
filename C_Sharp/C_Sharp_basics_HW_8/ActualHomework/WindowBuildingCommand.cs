using System;

namespace ActualHomework;

public class WindowBuildingCommand : IMenuCommand
{
    private IWorker worker = new Worker();
    private IPart window = new Window();

    public string GetDiscription()
    {
        return "Установить окно";
    }

    public void Execute(Team team)
    {
        team.Build(worker, window);

        Console.WriteLine(
            $"\n\t {window.GetTitle} установлено");
        Console.ReadKey();

        if (team.House.IsBuilt())
            throw new HouseIsBuiltExeption();
    }
}