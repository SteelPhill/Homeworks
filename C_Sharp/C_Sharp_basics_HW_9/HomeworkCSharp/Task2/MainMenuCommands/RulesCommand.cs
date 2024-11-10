using System;

namespace HomeworkCSharp;

public class RulesCommand : IMenuCommand
{
    public string Description()
    {
        return "Правила";
    }

    public void Execute()
    {
        Console.WriteLine("Правила игры \"Пьяница\"\n");

        Console.WriteLine(
            "- Колода, состоящая из 36 карт, раздаётся поровну на двух игроков.");

        Console.WriteLine("- Ход игры:");
        Console.WriteLine("  1) игроки одновременно открывают верхнюю карту " +
            "своих колод;");
        Console.WriteLine("  2) игрок, чья карта оказывается старше, " +
            "кладёт обе карты под низ своей колоды;");
        Console.WriteLine("  3) если карты одинаковые (спор), " +
            "то карты забирает первый игрок.");

        Console.WriteLine(
            "- Игра заканчивается победой игрока, который собрал все карты.");

        Console.WriteLine("- Туз считается старше шестёрки.");
        
        Console.WriteLine("\nНажмите любую клавишу...");
        Console.ReadKey();
    }
}