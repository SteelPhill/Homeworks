using System;

namespace ActualHomework;

public class ViewConstructionPlanCommand : IMenuCommand
{
    public string GetDiscription()
    {
        return "Посмотреть план строительства";
    }

    public void Execute(Team team)
    {
        Console.WriteLine("\"План строительства\"\n");
        Console.WriteLine("Этап 1 - залить фундамент.");
        Console.WriteLine(
            "Этап 2 - возвести стены. Кол-во: 4шт.");
        Console.WriteLine("Этап 3 - монтаж крыши.");
        Console.WriteLine("Этап 4 - установка двери.");
        Console.WriteLine(
            "Этап 5 - установка окон. Кол-во: 4шт.");
        Console.ReadKey();
    }
}