using System;
using System.Collections.Generic;

namespace HomeworkCSharp;

public class ConsoleMenuPrinter : IMenuPrinter
{
    private static IColorTextWriter blackOnWhiteTextWriter;

    public ConsoleMenuPrinter()
    {
        blackOnWhiteTextWriter = 
            new ConsoleColorTextWriter(ConsoleColor.White, ConsoleColor.Black);
    }

    public void Print(
        string title,
        List<IMenuCommand> commands,
        ref int selector)
    {
        Console.WriteLine($"{title}\n");
        Console.WriteLine("\tМеню\n");

        for (var i = 0; i < commands.Count; i++)
        {
            if (selector == i)
                blackOnWhiteTextWriter.WriteLine(commands[i].Description());
            else
                Console.WriteLine(commands[i].Description());
        }

        Console.WriteLine();

        if (selector == commands.Count)
            blackOnWhiteTextWriter.WriteLine("Выход");
        else
            Console.WriteLine("Выход");
    }
}