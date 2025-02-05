using System;
using System.Collections.Generic;
using System.Linq;
using SystemProgramming_HW_1.Extensions;

namespace SystemProgramming_HW_1.Helpers;

public static class ConsoleMenuHelper
{
    public static void PrintCommands(
        IEnumerable<string> commands,
        string backCommand = "Назад",
        bool isSkipFirstEmptyLine = false)
    {
        if (!isSkipFirstEmptyLine)
            Console.WriteLine();

        commands
            .Select((command, i) => $"{i + 1}: {command}")
            .Concat($"0: {backCommand}".AsEnumerable())
            .ForEach(Console.WriteLine);
    }
}