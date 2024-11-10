using System;
using System.Collections.Generic;

namespace HomeworkCSharp;

public class ConsoleMenuSelector : IMenuSelector
{
    private IMenuPrinter menuPrinter = new ConsoleMenuPrinter();

    public int Select(
        string title,
        List<IMenuCommand> commands,
        ref int selector)
    {
        var elementsNumber = commands.Count;

        do
        {
            Console.Clear();
            menuPrinter.Print(title, commands, ref selector);

            var key = Console.ReadKey().Key;

            if (key == ConsoleKey.DownArrow && 
                selector < elementsNumber)
                selector++;
            else if (key == ConsoleKey.UpArrow && selector > 0)
                selector--;
            else if (key == ConsoleKey.Enter)
                return selector;
            else if (key == ConsoleKey.Escape)
                return elementsNumber;

        } while (true);
    }
}