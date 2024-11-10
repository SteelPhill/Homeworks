using System.Collections.Generic;

namespace HomeworkCSharp;

public class CardsDeck
{
    public List<Card> Deck { get; }

    public CardsDeck()
    {
        Deck = new List<Card>()
        {
            new(RankCard.Six, SuitCard.Spades),
            new(RankCard.Six, SuitCard.Clubs),
            new(RankCard.Six, SuitCard.Hearts),
            new(RankCard.Six, SuitCard.Diamonds),
            new(RankCard.Seven, SuitCard.Spades),
            new(RankCard.Seven, SuitCard.Clubs),
            new(RankCard.Seven, SuitCard.Hearts),
            new(RankCard.Seven, SuitCard.Diamonds),
            new(RankCard.Eight, SuitCard.Spades),
            new(RankCard.Eight, SuitCard.Clubs),
            new(RankCard.Eight, SuitCard.Hearts),
            new(RankCard.Eight, SuitCard.Diamonds),
            new(RankCard.Nine, SuitCard.Spades),
            new(RankCard.Nine, SuitCard.Clubs),
            new(RankCard.Nine, SuitCard.Hearts),
            new(RankCard.Nine, SuitCard.Diamonds),
            new(RankCard.Ten, SuitCard.Spades),
            new(RankCard.Ten, SuitCard.Clubs),
            new(RankCard.Ten, SuitCard.Hearts),
            new(RankCard.Ten, SuitCard.Diamonds),
            new(RankCard.Jack, SuitCard.Spades),
            new(RankCard.Jack, SuitCard.Clubs),
            new(RankCard.Jack, SuitCard.Hearts),
            new(RankCard.Jack, SuitCard.Diamonds),
            new(RankCard.Queen, SuitCard.Spades),
            new(RankCard.Queen, SuitCard.Clubs),
            new(RankCard.Queen, SuitCard.Hearts),
            new(RankCard.Queen, SuitCard.Diamonds),
            new(RankCard.King, SuitCard.Spades),
            new(RankCard.King, SuitCard.Clubs),
            new(RankCard.King, SuitCard.Hearts),
            new(RankCard.King, SuitCard.Diamonds),
            new(RankCard.Ace, SuitCard.Spades),
            new(RankCard.Ace, SuitCard.Clubs),
            new(RankCard.Ace, SuitCard.Hearts),
            new(RankCard.Ace, SuitCard.Diamonds)
        };
    }
}