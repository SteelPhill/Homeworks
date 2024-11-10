using System;
using System.Collections.Generic;
using System.Linq;

namespace HomeworkCSharp;

public class Game
{
    static Random random = new Random();
    static CardsFieldWriter fieldWriter = new CardsFieldWriter('*');

    private List<Card> cardsDeck;

    public Player FirstPlayer { get; }
    public Player SecondPlayer { get; }

    public Game(
        Player firstPlayer, 
        Player secondPlayer, 
        CardsDeck cardsDeck)
    {
        this.cardsDeck = cardsDeck.Deck;

        FirstPlayer = firstPlayer;
        SecondPlayer = secondPlayer;
    }

    public void ShuffleCardsDeck()
    {
        cardsDeck = cardsDeck.OrderBy(c => random.Next()).ToList();
    }

    public void HandOutCards()
    {
        for (var i = 0; i < Constants.CardsInDeck / 2; i++)
        {
            FirstPlayer.AddCard(cardsDeck[0]);
            cardsDeck.Remove(cardsDeck[0]);
        }

        for (var i = 0; cardsDeck.Count != 0; i++)
        {
            SecondPlayer.AddCard(cardsDeck[0]);
            cardsDeck.Remove(cardsDeck[0]);
        }
    }

    private bool IsGameOver()
    {
        return FirstPlayer.CardsNumber() == 0 
            || SecondPlayer.CardsNumber() == 0;
    }

    private void GameOver()
    {
        Console.WriteLine("\tИгра окончена\n");
        Console.Write("Победитель: ");

        if (SecondPlayer.CardsNumber() == 0)
            Console.WriteLine(FirstPlayer.Name);
        else
            Console.WriteLine(SecondPlayer.Name);

        Console.WriteLine("\nНажмите любую клавишу...");
        Console.ReadKey();
    }

    public void Start()
    {
        do
        {
            fieldWriter.Write(FirstPlayer, SecondPlayer);

            if (FirstPlayer[0].Rank >= SecondPlayer[0].Rank)
            {
                FirstPlayer.AddCard(FirstPlayer[0]);
                FirstPlayer.AddCard(SecondPlayer[0]);

                FirstPlayer.RemoveCard(FirstPlayer[0]);
                SecondPlayer.RemoveCard(SecondPlayer[0]);
            }
            else
            {
                SecondPlayer.AddCard(SecondPlayer[0]);
                SecondPlayer.AddCard(FirstPlayer[0]);

                FirstPlayer.RemoveCard(FirstPlayer[0]);
                SecondPlayer.RemoveCard(SecondPlayer[0]);
            }

            Console.WriteLine("\nEnter: продолжить игру");
            Console.WriteLine("Esc  : вернуться в главное меню");

            ConsoleKey key;

            do
            { 
                key = Console.ReadKey().Key;

            } while (key != ConsoleKey.Enter
            && key != ConsoleKey.Escape);

            if (key == ConsoleKey.Escape)
                return;

            Console.Clear();

        } while (!IsGameOver());

        GameOver();
    }
}