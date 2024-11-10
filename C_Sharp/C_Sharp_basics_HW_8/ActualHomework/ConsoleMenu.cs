using System;
using System.Collections.Generic;

namespace ActualHomework;

public class ConsoleMenu : IMenu
{
    private List<IMenuCommand> commands;
    private static IMenuSelector consoleSelector;
    private string programName;

    public ConsoleMenu(string programName)
    {
        commands = new List<IMenuCommand>();
        consoleSelector = new MenuSelector();
        this.programName = programName;
    }

    public void AddComand(IMenuCommand command)
    {
        commands.Add(command);
    }

    public void Start(Team team)
    {
        int selector = 0;

        while (true)
        {
            selector =
                consoleSelector.Select(
                    programName, commands, selector);
            if (selector == commands.Count)
                break;

            Console.Clear();
            ExecuteCommand(selector, team);
        }
    }

    private void ExecuteCommand(int selector, Team team)
    {
        try
        {
            commands[selector].Execute(team);
        }
        catch (Exception ex)
        {
            if (ex is HouseIsBuiltExeption)
                throw (HouseIsBuiltExeption)ex;

            Console.Clear();
            Console.WriteLine(
                $"\nПроизошла ошибка: {ex.Message}");
            Console.ReadKey();
        }

        Console.WriteLine();
        Console.Clear();
    }
}