using System.Collections.Generic;

namespace HomeworkCSharp;

public class Player
{
    public string Name { get; }
    public List<Card> Cards { get; }

    public Player(string name)
    {
        Name = name;
        Cards = new List<Card>();
    }

    public int CardsNumber() => Cards.Count;

    public Card this[int index] => Cards[index];

    public void AddCard(Card card) => Cards.Add(card);

    public void RemoveCard(Card card) => Cards.Remove(card);
}