namespace HomeworkCSharp;

public class Card
{
    public RankCard Rank { get; }
    public SuitCard Suit { get; }

    public Card(RankCard rank, SuitCard suit)
    {
        Rank = rank;
        Suit = suit;
    }

    public string RankToString()
    {
        switch (Rank)
        {
            case RankCard.Six:
                return "6 ";
            case RankCard.Seven:
                return "7 ";
            case RankCard.Eight:
                return "8 ";
            case RankCard.Nine:
                return "9 ";
            case RankCard.Ten:
                return "10";
            case RankCard.Jack:
                return "В ";
            case RankCard.Queen:
                return "Д ";
            case RankCard.King:
                return "К ";
            case RankCard.Ace:
                return "Т ";
            default:
                return default;
        }
    }

    public string SuitToString()
    {
        switch (Suit)
        {
            case SuitCard.Spades:
                return new string('\u2660', 1);
            case SuitCard.Clubs:
                return new string('\u2663', 1);
            case SuitCard.Hearts:
                return new string('\u2665', 1);
            case SuitCard.Diamonds:
                return  new string('\u2666', 1);
            default:
                return default;
        }
    }
}