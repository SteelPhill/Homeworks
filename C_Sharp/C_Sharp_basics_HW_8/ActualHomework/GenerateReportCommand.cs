using System;

namespace ActualHomework;

public class GenerateReportCommand : IMenuCommand
{
    private IWorker teamLeader = new TeamLeader();

    public string GetDiscription()
    {
        return "Сформировать отчёт";
    }

    public void Execute(Team team)
    {
        team.Build(teamLeader, null);
        Console.ReadKey();
    }
}