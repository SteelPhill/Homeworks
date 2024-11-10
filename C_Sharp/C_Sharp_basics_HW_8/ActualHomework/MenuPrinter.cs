using System;
using System.Collections.Generic;

namespace ActualHomework;

public class MenuPrinter : IMenuPrinter
{
    private static ITextBlackOnWhiteWriter textWriter;

    public MenuPrinter()
    {
        textWriter = new ConsoleTextBlackOnWhiteWriter();
    }

    public void Print(
        string programName,
        List<IMenuCommand> commands,
        int selector)
    {
        Console.WriteLine($"{programName}\n");
        Console.WriteLine("\tМеню\n");

        for (int i = 0; i < commands.Count; i++)
        {
            if (selector == i)
                textWriter.WriteLine(commands[i].GetDiscription());

            else
                Console.WriteLine(commands[i].GetDiscription());
        }

        if (selector == commands.Count)
            textWriter.WriteLine("Выход");
        else
            Console.WriteLine("Выход");
    }
}