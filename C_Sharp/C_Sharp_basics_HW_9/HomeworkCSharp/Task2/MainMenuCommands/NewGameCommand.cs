namespace HomeworkCSharp;

public class NewGameCommand : IMenuCommand
{ 
    CardsDeck deck;

    public NewGameCommand()
    {
        deck = new CardsDeck();
    }

    public string Description()
    {
        return "Новая игра";
    }

    public void Execute()
    {
        var firstPlayer = new Player("Первый игрок");
        var secondPlayer = new Player("Второй игрок");

        var game = new Game(firstPlayer, secondPlayer, deck);

        game.ShuffleCardsDeck();
        game.HandOutCards();
        game.Start();
    }
}