using System;

namespace HomeworkCSharp;

public class CardsFieldWriter : ICardsFieldWriter
{
    char cardBorder;

    public CardsFieldWriter(char cardBorder)
    {
        this.cardBorder = cardBorder;
    }

    public void Write(Player first, Player second)
    {
        Console.Write($" {first.Name}");
        Console.Write($"\t  {second.Name}");
        Console.WriteLine("\n");

        Console.Write("колода   карта   карта   колода");
        Console.WriteLine();

        for (var i = 0; i < Constants.CardsOnField; i++)
            Console.Write($"{new string(cardBorder, Constants.CardWidth)} ");
        Console.WriteLine();

        for (var i = 0; i < Constants.CardEmptyRowsNumber / 2; i++)
        {
            for (var j = 0; j < Constants.CardsOnField; j++)
                Console.Write($"{cardBorder}" +
                    $"{new string(' ', Constants.CardWidth - 2)}{cardBorder} ");
            Console.WriteLine();
        }

        Console.Write(cardBorder);
        if (first.CardsNumber() < 10)
            Console.Write(' ');
        Console.Write($"{first.CardsNumber()}шт.{cardBorder} ");

        Console.Write($"{cardBorder} {first.Cards[0].RankToString()}" +
            $"{first.Cards[0].SuitToString()} {cardBorder} ");

        Console.Write($"{cardBorder} {second.Cards[0].RankToString()}" +
            $"{second.Cards[0].SuitToString()} {cardBorder} ");

        Console.Write(cardBorder);
        if (second.CardsNumber() < 10)
            Console.Write(' ');
        Console.Write($"{second.CardsNumber()}шт.{cardBorder}\n");

        for (var i = 0; i < Constants.CardEmptyRowsNumber / 2; i++)
        {
            for (var j = 0; j < Constants.CardsOnField; j++)
                Console.Write($"{cardBorder}" +
                    $"{new string(' ', Constants.CardWidth - 2)}{cardBorder} ");
            Console.WriteLine();
        }

        for (var i = 0; i < Constants.CardsOnField; i++)
            Console.Write($"{new string(cardBorder, Constants.CardWidth)} ");
        Console.WriteLine();
    }
}