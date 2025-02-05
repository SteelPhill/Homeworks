using System;

namespace SystemProgramming_HW_2.Helpers;

public static class ConsoleReadHelper
{
    public static int ReadInt(string message, int from = int.MinValue, int to = int.MaxValue)
    {
        while (true)
        {
            Console.Write(message);

            if (!int.TryParse(Console.ReadLine(), out var value))
            {
                Console.WriteLine("Введено некорректное число, повторите ввод");
                continue;
            }

            if (from > value || value > to)
            {
                Console.WriteLine($"Введенное число должно быть в диапазоне от {from} до {to}, повторите ввод");
                continue;
            }

            return value;
        }
    }

    public static DateTime ReadDateTime(string message)
    {
        while (true)
        {
            Console.Write(message);

            if (!DateTime.TryParse(Console.ReadLine(), out var value))
            {
                Console.WriteLine("Введено некорректная дата, повторите ввод");
                continue;
            }

            return value;
        }
    }
}