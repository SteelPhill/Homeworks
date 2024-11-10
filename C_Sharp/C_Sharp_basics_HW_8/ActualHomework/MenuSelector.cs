using System;
using System.Collections.Generic;

namespace ActualHomework;

public class MenuSelector : IMenuSelector
{
    private IMenuPrinter menuPrinter = new MenuPrinter();

    public int Select(
        string programName,
        List<IMenuCommand> commands,
        int selector)
    {
        int elementsNumber = commands.Count + 1;
        ConsoleKey key;

        do
        {
            Console.Clear();
            menuPrinter.Print(programName, commands, selector);

            key = Console.ReadKey().Key;
            if (key == ConsoleKey.DownArrow &&
                selector < elementsNumber - 1)
                selector++;
            else if (key == ConsoleKey.UpArrow && selector > 0)
                selector--;
            else if (key == ConsoleKey.Enter)
                return selector;

        } while (true);
    }
}