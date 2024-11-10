using System;
using System.Text;
using System.Collections.Generic;

namespace ActualHomework;

public class C_Sharp_basics_HW_8
{
    public static void Main()
    {
        try
        {
            Task1();
        }
        catch (Exception ex)
        {
            Console.Clear();
            Console.WriteLine($"\nОшибка: {ex.Message}");
        }
    }

    private static void Task1()
    {
        House house = new House();
        Team team = new Team(house);
        IMenu mainMenu = 
            new ConsoleMenu("\"Строительство дома\"");
        mainMenu.AddComand(new WorkerOptionsCommand());
        mainMenu.AddComand(new TeamLeaderOptionsCommand());
        mainMenu.AddComand(new ViewConstructionPlanCommand());

        try
        {
            mainMenu.Start(team);
        }
        catch (HouseIsBuiltExeption)
        {
            Console.Clear();
            Console.WriteLine("\t   Дом построен!\n");
            house.PrintFinishedHouse();
            Console.ReadKey();
        }
    }
}

/*     
*          ЗАДАНИЕ №1
* Реализовать программу “Строительство дома”.
* Реализовать:
* Классы:
* - House (Дом), Basement (Фундамент), Walls (Стены),
*   Door (Дверь), Window (Окно), Roof (Крыша);
* - Team (Бригада строителей), Worker (Строитель), 
*   TeamLeader (Бригадир).
* Интерфейсы:
* - IWorker, IPart.
* Все части дома должны реализовать интерфейс IPart (Часть дома), 
* для рабочих и бригадира предоставляется базовый интерфейс IWorker (Рабочий). 
* Бригада строителей (Team) строит дом (House). 
* Дом состоит из фундамента (Basement), стен (Wall), окон (Window), 
* дверей (Door), крыши (Roof). 
* Согласно проекту, в доме должно быть 1 фундамент, 4 стены, 1 дверь,
* 4 окна, 1 крыша.
* Бригада начинает работу, и строители последовательно “строят” дом, 
* начиная с фундамента. Каждый строитель не знает заранее, 
* на чём завершился предыдущий этап строительства, поэтому он “проверяет”, 
* что уже построено и продолжает работу. Если в игру вступает бригадир (TeamLeader), 
* он не строит, а формирует отчёт, что уже построено и какая часть работы выполнена. 
* В конечном итоге на консоль выводится сообщение, что строительство дома завершено
* и отображается “рисунок дома” (вариант отображения выбрать самостоятельно).
*/

public interface IPart
{
    string GetTitle { get; }
}

public class Basement : IPart
{
    public string GetTitle => "Фундамент";
}

public class Wall : IPart
{
    public string GetTitle => "Стена";
}

public class Roof : IPart
{
    public string GetTitle => "Крыша";
}

public class Door : IPart
{
    public string GetTitle => "Дверь";
}

public class Window : IPart
{
    public string GetTitle => "Окно";
}

public class House
{
    private List<IPart> parts = new List<IPart>();
    private const int MaxPartsNumber = 11;
    private const decimal OnePercentBuilding = 0.11m;

    private bool IsMustBeBasement()
    {
        return parts.Count == 0;
    }

    private bool IsMustBeWall()
    {
        return parts.Count >= 1 && parts.Count <= 4;
    }

    private bool IsMustBeRoof()
    {
        return parts.Count == 5;
    }

    private bool IsMustBeDoor()
    {
        return parts.Count == 6;
    }

    private bool IsMustBeWindow()
    {
        return parts.Count >= 7 && parts.Count <= 10;
    }

    public void Build(IPart part)
    {
        bool isPartCanBeBuild = false;

        if (part is Basement && IsMustBeBasement())
            isPartCanBeBuild = true;
        else if (part is Wall && IsMustBeWall())
            isPartCanBeBuild = true;
        else if (part is Roof && IsMustBeRoof())
            isPartCanBeBuild = true;
        else if (part is Door && IsMustBeDoor())
            isPartCanBeBuild = true;
        else if (part is Window && IsMustBeWindow())
            isPartCanBeBuild = true;

        if (isPartCanBeBuild)
            parts.Add(part);
        else
            throw new Exception(
                "Попытка нарушить порядок строительства!");
    }

    public int ElementsNumberBuilt()
    {
        return parts.Count;
    }

    public bool IsBuilt()
    {
        return parts.Count == MaxPartsNumber;
    }

    public string GetReport()
    {
        var sb = new StringBuilder();
        sb.Append(GetBeenBuilt());
        sb.AppendLine($"\nПроцент застройки: " +
            $"{(ElementsNumberBuilt() != 0
            ? Math.Round(
                ElementsNumberBuilt() / OnePercentBuilding, 1)
            : 0)}"); 

        return sb.ToString();
    }

    public string GetBeenBuilt()
    {
        var sb = new StringBuilder();
        sb.AppendLine("Построенно:\n");
        foreach (var part in parts)
            sb.AppendLine($"-{part.GetTitle}");

        return sb.ToString();
    }

    public void PrintFinishedHouse()
    {
        const int RoofHeight = 10;
        const int WallWidth = 17;
        const int WallHeight = 9;

        var wallRow = new string('*', WallWidth);
        var wallRowWithWindow = "*    *     *    *";
        var wallRowWithDoor = "******     ******";

        for (var i = 0; i < RoofHeight; i++)
        {
            Console.Write(
                $"\t{new string(' ', RoofHeight - i - 1)}");
            Console.WriteLine(new string('*', i * 2 + 1));
        }

        for (var i = 0; i < WallHeight / 3; i++)
            Console.WriteLine($"\t {wallRow}");

        for (var i = 0; i < WallHeight / 3; i++)
            Console.WriteLine($"\t {wallRowWithWindow}");

        for (var i = 0; i < WallHeight / 3; i++)
            Console.WriteLine($"\t {wallRowWithDoor}");

        Console.WriteLine($"\t*{wallRow}*");
    }
}

public interface IWorker
{
    string GetProfession { get; }
}

public class TeamLeader : IWorker
{
    public string GetProfession => "Бригадир";
}

public class Worker : IWorker
{
    public string GetProfession => "Строитель";
}

public class Team
{
    private House house;

    public Team(House house)
    {
        this.house = house;
    }

    public House House => house;

    public void Build(IWorker employee, IPart part)
    {
        if (employee is Worker)
            house.Build(part);
        else if (employee is TeamLeader)
            Console.WriteLine(house.GetReport());
        else
            throw new Exception(
                "Доступ к строительству дома есть " +
                "только у строителей и бригадира!");
    }

    public void PrintWhatBeenBuild()
    {
        Console.WriteLine(house.GetBeenBuilt());
    }
}