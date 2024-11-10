using System;

namespace ActualHomework;

public class ViewWhatBeenBuiltCommand : IMenuCommand
{
    public string GetDiscription()
    {
        return "Показать список выполненных работ";
    }

    public void Execute(Team team)
    {
        team.PrintWhatBeenBuild();
        Console.ReadKey();
    }
}