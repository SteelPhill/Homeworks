using System;
using System.Collections.Generic;

namespace HomeworkCSharp;

public class ConsoleMenu : IMenu
{
    private List<IMenuCommand> commands;
    private static IMenuSelector menuSelector;
    private string title;

    public ConsoleMenu(string title)
    {
        commands = new List<IMenuCommand>();
        menuSelector = new ConsoleMenuSelector();
        this.title = title;
    }

    public void AddCommand(IMenuCommand command)
    {
        commands.Add(command);
    }

    public void Start()
    {
        var selector = 0;

        while (true)
        {
            selector = 
                menuSelector.Select(title, commands, ref selector);

            if (selector == commands.Count)
                break;

            Console.Clear();
            ExecuteCommand(selector);
        }
    }

    private void ExecuteCommand(int selector)
    {
        try
        {
            commands[selector].Execute();
        }
        catch (EndRaceException)
        {
            throw new EndRaceException();
        }
        catch (Exception ex)
        {     
            Console.Clear();
            Console.WriteLine($"\nПроизошла ошибка: {ex.Message}");
            Console.ReadKey();
        }

        Console.WriteLine();
        Console.Clear();
    }
}