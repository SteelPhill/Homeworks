using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ActualHomework;

public class Program
{
    public static void Main()
    {
        try
        {
            Task1And2();
            //Task3And4();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }

    private static void Task1And2()
    {
        IMenu ticTacToeConsoleMenu = new TicTacToeConsoleMenu();
        ticTacToeConsoleMenu.AddComand(new PlayerVsComputerCommand());
        ticTacToeConsoleMenu.AddComand(new PlayerVsPlayerCommand());
        ticTacToeConsoleMenu.Start();
    }

    public static void Task3And4()
    {
        IMenu morseCodeConsoleMenu = new MorseCodeConsoleMenu();
        morseCodeConsoleMenu.AddComand(new EncodeCommand());
        morseCodeConsoleMenu.AddComand(new DecodeInEnglishCommand());
        morseCodeConsoleMenu.AddComand(new DecodeInRussianCommand());
        morseCodeConsoleMenu.Start();
    }
}

interface IMenu
{
    void AddComand(IMenuCommand command);
    void Start();
}

public interface IMenuCommand
{
    string GetDiscription();
    void Execute();
}

interface ITextBlackOnWhiteWriter
{
    void Write(string text);
    void WriteLine(string text);
}

public class ConsoleTextBlackOnWhiteWriter : ITextBlackOnWhiteWriter
{
    public void Write(string text)
    {
        Console.BackgroundColor = ConsoleColor.White;
        Console.ForegroundColor = ConsoleColor.Black;
        Console.Write(text);
        Console.BackgroundColor = ConsoleColor.Black;
        Console.ForegroundColor = ConsoleColor.White;
    }

    public void WriteLine(string text)
    {
        Console.BackgroundColor = ConsoleColor.White;
        Console.ForegroundColor = ConsoleColor.Black;
        Console.WriteLine(text);
        Console.BackgroundColor = ConsoleColor.Black;
        Console.ForegroundColor = ConsoleColor.White;
    }
}

/*     
*          ЗАДАНИЕ №1
* Создайте приложение «Крестики-Нолики». 
* Пользователь играет с компьютером. 
* При старте игры случайным образом выбирается, 
* кто ходит первым. Игроки ходят по очереди.
* Игра может закончиться победой одного из игроков или ничьей. 
* Используйте механизмы пространств имён.
*   
*          ЗАДАНИЕ №2
* Добавьте к первому заданию возможность
* игры с другим пользователем.
*/

public class TicTacToeConsoleMenu : IMenu
{
    private List<IMenuCommand> commands;
    private static ITextBlackOnWhiteWriter textWriter;

    public TicTacToeConsoleMenu()
    {
        commands = new List<IMenuCommand>();
        textWriter = new ConsoleTextBlackOnWhiteWriter();
    }

    public void AddComand(IMenuCommand command)
    {
        commands.Add(command);
    }

    public void Start()
    {
        while (true)
        {
            int selector = 0;

            selector = ChangeSelector(commands.Count + 1, selector);
            if (selector == commands.Count)
                break;

            Console.Clear();
            ExecuteCommand(selector);
        }
    }

    private void PrintMenu(int selector)
    {
        Console.WriteLine("     Tic Tac Toe\n");
        Console.WriteLine("\tMenu");

        for (int i = 0; i < commands.Count; i++)
        {
            if (selector == i)
                textWriter.WriteLine(commands[i].GetDiscription());

            else
                Console.WriteLine(commands[i].GetDiscription());
        }

        if (selector == commands.Count)
            textWriter.Write("Exit");
        else
            Console.WriteLine("Exit");
    }

    private int ChangeSelector(int elementsNumber, int selector)
    {
        ConsoleKey key;

        do
        {
            Console.Clear();
            PrintMenu(selector);

            key = Console.ReadKey().Key;
            if (key == ConsoleKey.DownArrow && 
                selector < elementsNumber - 1)
                selector++;
            else if (key == ConsoleKey.UpArrow && selector > 0)
                selector--;
            else if (key == ConsoleKey.Enter)
                return selector;

        } while (true);
    }

    private void ExecuteCommand(int selector)
    {
        try
        {
            commands[selector].Execute();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error has occurred: {ex.Message}");
            Console.ReadKey();
        }

        Console.WriteLine();
        Console.Clear();
    }
}

public class PlayerVsPlayerCommand : IMenuCommand
{
    private bool isCrossMove;
    private static Field field;
    private static IPlayerMover playerMover;
    private static IGameOverChecker gameOverChecker;
    private static (string Name, char Symbol) cross;
    private static (string Name, char Symbol) zero;

    public PlayerVsPlayerCommand()
    {
        isCrossMove = true;
        field = new Field();
        playerMover = new PlayerMover();
        gameOverChecker = new GameOverChecker();
        cross = ("Cross", 'X');
        zero = ("Zero", 'O');
    }

    public string GetDiscription()
    {
        return "Player vs. Player";
    }

    public void Execute()
    {
        isCrossMove = true;
        bool isCrossWin = false;
        bool isZeroWin = false;

        field.ReturnToOriginalState();
        Console.Clear();

        do
        {
            Console.WriteLine($"Mode: {GetDiscription()}\n");

            if (isCrossMove)
            {
                if (!playerMover.TryMove(
                    cross.Name, ref field,
                    cross.Symbol, ref isCrossMove))
                    return;
                if (gameOverChecker.IsWin(field))
                    isCrossWin = true;
            }
            else
            {
                if (!playerMover.TryMove(
                    zero.Name, ref field, 
                    zero.Symbol, ref isCrossMove))
                    return;
                if (gameOverChecker.IsWin(field))
                    isZeroWin = true;
            }

            Console.Clear();

            if (isCrossWin || isZeroWin)
                break;

            if (gameOverChecker.IsDrawnGame(field))
                break;

        } while (true);

        Console.Write("Result: ");

        if (isCrossWin)
            Console.WriteLine("Cross Win!");
        else if (isZeroWin)
            Console.WriteLine("Zero Win!");
        else
            Console.WriteLine("Drawn game!");

        Console.ReadKey();
    }
}

public class PlayerVsComputerCommand : IMenuCommand
{
    private bool isCrossMove;
    private Field field;
    private static IPlayerMover playerMover;
    private static IComputerMover computerMover;
    private static IGameOverChecker gameOverChecker;
    private static Random random;
    private static (string Name, char Symbol) cross;
    private static (string Name, char Symbol) zero;

    public PlayerVsComputerCommand()
    {
        isCrossMove = true;
        field = new Field();
        playerMover = new PlayerMover();
        computerMover = new ComputerMover();
        gameOverChecker = new GameOverChecker();
        random = new Random();
        cross = ("Cross", 'X');
        zero = ("Zero", 'O');
    }

    public string GetDiscription()
    {
        return "Player vs. Computer";
    }

    public void Execute()
    {
        isCrossMove = true;
        bool isComputerMoveFirst = IsComputerMoveFirst();
        bool isCrossWin = false;
        bool isZeroWin = false;

        field.ReturnToOriginalState();

        do
        {
            Console.WriteLine($"Mode: {GetDiscription()}\n");

            if (isCrossMove)
            {
                if (isComputerMoveFirst)
                {
                    computerMover.Move(
                        ref field,
                        cross.Symbol,
                        ref isCrossMove);
                }
                else
                {
                    if (!playerMover.TryMove(
                        cross.Name, ref field,
                        cross.Symbol, ref isCrossMove))
                        return;
                }

                if (gameOverChecker.IsWin(field))
                    isCrossWin = true;
            }
            else
            {
                if (!isComputerMoveFirst)
                {
                    computerMover.Move(
                        ref field, 
                        zero.Symbol, 
                        ref isCrossMove);
                }
                else
                {
                    if (!playerMover.TryMove(
                        zero.Name, ref field,
                        zero.Symbol, ref isCrossMove))
                        return;

                    if (gameOverChecker.IsWin(field))
                        isZeroWin = true;
                }
            }

            Console.Clear();

            if (isCrossWin || isZeroWin)
                break;

            if (gameOverChecker.IsDrawnGame(field))
                break;

        } while (true);

        Console.Write("Result: ");

        if (isCrossWin)
            Console.WriteLine("Cross Win!");
        else if (isZeroWin)
            Console.WriteLine("Zero Win!");
        else
            Console.WriteLine("Drawn game!");

        Console.ReadKey();
    }

    private bool IsComputerMoveFirst()
    {
        return random.Next(0, 2) == 0 ? true : false;
    }
}

interface IPlayerMover
{
    bool TryMove(
        string name,
        ref Field field,
        char symbol,
        ref bool isCrossMove);
}

public class PlayerMover : IPlayerMover
{
    private static string[] numPads = {
            "NumPad1",
            "NumPad2",
            "NumPad3",
            "NumPad4",
            "NumPad5",
            "NumPad6",
            "NumPad7",
            "NumPad8",
            "NumPad9"
    };
    private static ICellChecker cellChecker = new CellChecker();
    private const int StartCell = 1;
    private const int EndCell = 9;

    public bool TryMove(
        string name,
        ref Field field,
        char symbol,
        ref bool isCrossMove)
    {
        isCrossMove = isCrossMove == true ? false : true;

        Console.WriteLine($"\t{name} move\n");
        field.Print();

        Console.WriteLine("\nPress a digit on the numpad " +
            "to select a free cell");
        Console.WriteLine("or press Enter to return to the menu\n");
        Console.Write("=> ");

        do
        {
            string key = Console.ReadKey().Key.ToString();
            if (key == "Enter")
                return false;

            int cellIndex = numPads.TakeWhile(s => s != key).Count();

            if (!cellChecker.IsOutOfRange(cellIndex + 1) &&
                !cellChecker.IsBusy(field, cellIndex + 1))
            {
                ShiftSymbol(ref field, cellIndex, symbol);
                return true;
            }
        } while (true);
    }

    private void ShiftSymbol(
        ref Field field, 
        int cellIndex, 
        char symbol)
    {
        field[cellIndex] = symbol;
    }
}

interface IComputerMover
{
    void Move(ref Field field, char symbol, ref bool isCrossMove);
}

public class ComputerMover : IComputerMover
{
    private static WinIndexes winIndexes = new WinIndexes();
    private static Random random = new Random();
    private static ICellChecker cellChecker = new CellChecker();
    private const char Cross = 'X';
    private const char Zero = 'O';
    private const int StartCell = 1;
    private const int EndCell = 9;

    public void Move(
        ref Field field, 
        char symbol, 
        ref bool isCrossMove)
    {
        int indexForAttack = -1;
        int indexForProtection = -1;

        isCrossMove = isCrossMove == true ? false : true;

        for (int i = 0; i < winIndexes.Length; i++)
        {
            indexForAttack = IndexForShift(
                field, 
                winIndexes[i], 
                symbol);

            if (indexForAttack != -1)
            {
                if (!cellChecker.IsBusy(field, indexForAttack + 1))
                {
                    ShiftSymbol(ref field, indexForAttack, symbol);
                    return;
                }
            }

            if (indexForProtection == -1)
            {
                indexForProtection = IndexForShift(
                    field, 
                    winIndexes[i], 
                    symbol == Cross ? Zero : Cross);

                if (indexForProtection != -1)
                {
                    if (cellChecker
                        .IsBusy(field, indexForProtection + 1))
                        indexForProtection = -1;
                }
            }
        }

        if (indexForProtection != -1)
        {
            ShiftSymbol(ref field, indexForProtection, symbol);
            return;
        }

        do
        {
            int cell = random.Next(StartCell, EndCell + 1);

            if (!cellChecker.IsOutOfRange(cell) && 
                !cellChecker.IsBusy(field, cell))
            {
                ShiftSymbol(ref field, cell - 1, symbol);
                break;
            }
        } while (true);
    }

    private int IndexForShift(Field field, int[] indexes, char symbol)
    {
        if (field[indexes[1]] == field[indexes[2]] &&
            field[indexes[1]] == symbol)
            return indexes[0];
        if (field[indexes[0]] == field[indexes[2]] &&
            field[indexes[0]] == symbol)
            return indexes[1];
        if (field[indexes[0]] == field[indexes[1]] &&
            field[indexes[0]] == symbol)
            return indexes[2];

        return -1;
    }

    private void ShiftSymbol(
        ref Field field, 
        int cellIndex, 
        char symbol)
    {
        field[cellIndex] = symbol;
    }
}

interface IGameOverChecker
{
    bool IsWin(Field field);
    bool IsDrawnGame(Field field);
}

public class GameOverChecker : IGameOverChecker
{
    private static WinIndexes winIndexes = new WinIndexes();

    public bool IsWin(Field field)
    {
        for (int i = 0; i < winIndexes.Length; i++)
            if (IsSymbolsEquals(
                field[winIndexes[i][0]],
                field[winIndexes[i][1]],
                field[winIndexes[i][2]]))
                return true;

        return false;
    }

    private bool IsSymbolsEquals(char first, char second, char third)
    {
        return first == second && second == third;
    }

    public bool IsDrawnGame(Field field)
    {
        return field.All(ch => !char.IsDigit(ch));
    }
}

interface ICellChecker
{
    bool IsBusy(Field field, int index);
    bool IsBusy(char[] field, int index);
    bool IsOutOfRange(int cell);
}

public class CellChecker : ICellChecker
{
    private const char Cross = 'X';
    private const char Zero = 'O';
    private const int StartCell = 1;
    private const int EndCell = 9;

    public bool IsBusy(Field field, int cell)
    {
        return field[cell - 1] == Cross || field[cell - 1] == Zero;
    }

    public bool IsBusy(char[] field, int cell)
    {
        return field[cell - 1] == Cross || field[cell - 1] == Zero;
    }

    public bool IsOutOfRange(int cell)
    {
        return cell < StartCell || cell > EndCell;
    }
}

public class Field : IEnumerable<char>
{
    private char[] field;
    private static StringBuilder sb;
    private static ITextBlackOnWhiteWriter textWriter;
    private static ICellChecker cellChecker;
    private const int CellsInRow = 3;

    public Field()
    {
        field = "123456789".ToCharArray();
        sb = new StringBuilder();
        textWriter = new ConsoleTextBlackOnWhiteWriter();
        cellChecker = new CellChecker();
    }

    public int Length => field.Length;

    public char this[int index]
    {
        get => field[index];
        set => field[index] = value;
    }

    public void ReturnToOriginalState()
    {
        field = "123456789".ToCharArray();
    }

    public void Print()
    {
        Console.Write("\t");
        for (int i = 1; i <= field.Length; i++)
            if (i % CellsInRow == 0)
            {
                if (cellChecker.IsBusy(field, i))
                {
                    textWriter.Write($"[{field[i - 1]}]");
                    Console.Write("\n\t");
                }
                else
                    Console.Write($"[{field[i - 1]}]\n\t");
            }
            else
            {
                if (cellChecker.IsBusy(field, i))
                    textWriter.Write($"[{field[i - 1]}]");
                else
                    Console.Write($"[{field[i - 1]}]");
            }
    }

    public override string ToString()
    {
        sb.Clear();
        sb.Append("\t");

        for (int i = 1; i <= field.Length; i++)
            if (i % CellsInRow == 0)
                sb.Append($"[{field[i - 1]}]\n\t");
            else
                sb.Append($"[{field[i - 1]}]");

        return sb.ToString();
    }

    public IEnumerator<char> GetEnumerator()
    {
        return ((IEnumerable<char>)field).GetEnumerator();
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return ((IEnumerable<char>)field).GetEnumerator();
    }
}

public class WinIndexes
{
    private static int[][] winIndexes = {
            [0, 1, 2],
            [3, 4, 5],
            [6, 7, 8],
            [0, 3, 6],
            [1, 4, 7],
            [2, 5, 8],
            [0, 4, 8],
            [2, 4, 6]
    };

    public int Length => winIndexes.Length;

    public int[] this[int index]
    {
        get => winIndexes[index];
    }
}

/*     
*          ЗАДАНИЕ №3
* Создайте приложение для перевода обычного текста
* в азбуку Морзе. Пользователь вводит текст. 
* Приложение отображает введенный текст азбукой Морзе. 
* Используйте механизмы пространств имён.
*   
*          ЗАДАНИЕ №4
* Добавьте к предыдущему заданию механизм перевода 
* текста из азбуки Морзе в обычный текст.
*/

public class MorseCodeConsoleMenu : IMenu
{
    private List<IMenuCommand> commands;
    private static ITextBlackOnWhiteWriter textWriter;

    public MorseCodeConsoleMenu()
    {
        commands = new List<IMenuCommand>();
        textWriter = new ConsoleTextBlackOnWhiteWriter();
    }

    public void AddComand(IMenuCommand command)
    {
        commands.Add(command);
    }

    public void Start()
    {
        while (true)
        {
            int selector = 0;

            selector = ChangeSelector(commands.Count + 1, selector);
            if (selector == commands.Count)
                break;

            Console.Clear();
            ExecuteCommand(selector);
        }
    }

    private void PrintMenu(int selector)
    {
        Console.WriteLine("     Morse code\n");
        Console.WriteLine("\tMenu");

        for (int i = 0; i < commands.Count; i++)
        {
            if (selector == i)
                textWriter.WriteLine(commands[i].GetDiscription());
            else
                Console.WriteLine(commands[i].GetDiscription());
        }

        if (selector == commands.Count)
            textWriter.Write("Exit");
        else
            Console.WriteLine("Exit");
    }

    private int ChangeSelector(int elementsNumber, int selector)
    {
        ConsoleKey key;

        do
        {
            Console.Clear();
            PrintMenu(selector);

            key = Console.ReadKey().Key;
            if (key == ConsoleKey.DownArrow && 
                selector < elementsNumber - 1)
                selector++;
            else if (key == ConsoleKey.UpArrow && selector > 0)
                selector--;
            else if (key == ConsoleKey.Enter)
                return selector;

        } while (true);
    }

    private void ExecuteCommand(int selector)
    {
        try
        {
            commands[selector].Execute();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error has occurred: " +
                $"{ex.Message}");
            Console.ReadKey();
        }

        Console.WriteLine();
        Console.Clear();
    }
}

public class EncodeCommand : IMenuCommand
{
    private static MorseDB morseDB;
    private static IMorseWorker rusLetters;
    private static IMorseWorker engLetters;
    private static IMorseWorker digits;
    private static IMorseWorker punctuation;
    private static StringBuilder sb;

    public EncodeCommand()
    {
        morseDB = new MorseDB();
        rusLetters = new MorseWorker(morseDB.RusLetters);
        engLetters = new MorseWorker(morseDB.EngLetters);
        digits = new MorseWorker(morseDB.Digits);
        punctuation = new MorseWorker(morseDB.Punctuation);
        sb = new StringBuilder();
    }

    public string GetDiscription()
    {
        return "Encoding";
    }

    public void Execute()
    {
        sb.Clear();

        Console.WriteLine("Input normal text and press Enter:\n");
        string text = Console.ReadLine().ToLower();

        foreach (var ch in text)
            sb.Append(GetMorseValue(ch));

        Console.WriteLine($"\n\tResult:\n\n{sb.ToString()}");
        Console.ReadKey();
    }

    private string GetMorseValue(char symbol)
    {
        if (symbol == ' ')
            return "/ ";

        if (symbol == '\n')
            return "/\n";

        string result;

        result = engLetters[symbol];
        if (result != default)
            return $"{result} ";

        result = rusLetters[symbol];
        if (result != default)
            return $"{result} ";

        result = digits[symbol];
        if (result != default)
            return $"{result} ";

        result = punctuation[symbol];
        if (result != default)
            return $"{result} ";

        return "";
    }
}

public class DecodeInEnglishCommand : IMenuCommand
{
    private IMorseDecoder decoder = new MorseDecoder();

    public string GetDiscription()
    {
        return "Decode in English";
    }

    public void Execute()
    {
        decoder.DecodeInEnglishOrRussian(true);        
    }
}

public class DecodeInRussianCommand : IMenuCommand
{
    private IMorseDecoder decoder = new MorseDecoder();

    public string GetDiscription()
    {
        return "Decode in Russian";
    }

    public void Execute()
    {
        decoder.DecodeInEnglishOrRussian(false);       
    }
}

interface IMorseDecoder
{
    void DecodeInEnglishOrRussian(bool isIntoEng);
}

public class MorseDecoder : IMorseDecoder
{
    bool isIntoEng;
    private static MorseDB morseDB;
    private static IMorseWorker engLetters;
    private static IMorseWorker rusLetters;
    private static IMorseWorker digits;
    private static IMorseWorker punctuation;
    private static StringBuilder sb;

    public MorseDecoder()
    {
        isIntoEng = true;
        morseDB = new MorseDB();
        engLetters = new MorseWorker(morseDB.EngLetters);
        rusLetters = new MorseWorker(morseDB.RusLetters);
        digits = new MorseWorker(morseDB.Digits);
        punctuation = new MorseWorker(morseDB.Punctuation);
        sb = new StringBuilder();
    }

    public void DecodeInEnglishOrRussian(bool isIntoEng)
    {
        this.isIntoEng = isIntoEng;

        sb.Clear();

        Console.WriteLine("Input morse text and press Enter:\n");
        var text = Console.ReadLine().ToLower();

        var splitByWords = text.Split('/');
        foreach (var str in splitByWords)
            sb.Append(str.TrimEnd()
                .Split()
                .Select(s => GetNormalLetter(s))
                .ToArray());

        Console.WriteLine($"\n\tResult:\n\n{sb.ToString()}");
        Console.ReadKey();
    }

    private char GetNormalLetter(string morseStr)
    {
        char letter = default;

        if (isIntoEng)
            letter = engLetters[morseStr];
        else
            letter = rusLetters[morseStr];

        if (letter != default)
            return letter;

        letter = digits[morseStr];
        if (letter != default)
            return letter;

        letter = punctuation[morseStr];
        if (letter != default)
            return letter;

        return letter;
    }
}

interface IMorseWorker
{
    int Length { get; }
    char this[string code] { get; }
    string this[char letter] { get; }
}

public class MorseWorker : IMorseWorker
{
    private Dictionary<string, char> morse;
    private static StringBuilder sb;

    public MorseWorker(Dictionary<string, char> morse)
    {
        this.morse = morse;
        sb = new StringBuilder();
    }

    public int Length => morse.Count;

    public char this[string code]
    {
        get
        {
            if (!morse.TryGetValue(code, out var letter))
                return default;         
            return letter;
        }
    }

    public string this[char letter]
    {
        get => morse
            .Where(x => x.Value == letter)
            .FirstOrDefault().Key;
    }

    public override string ToString()
    {
        foreach (var i in morse)
            sb.AppendLine($"{i.Key} = {i.Value}");
        return sb.ToString();
    }
}

public class MorseDB
{
    private Dictionary<string, char> rusLetters;
    private Dictionary<string, char> engLetters;
    private Dictionary<string, char> digits;
    private Dictionary<string, char> punctuation;

    public MorseDB()
    {
        rusLetters = new Dictionary<string, char>();
        rusLetters.Add(".-", 'а');
        rusLetters.Add("-...", 'б');
        rusLetters.Add(".--", 'в');
        rusLetters.Add("--.", 'г');
        rusLetters.Add("-..", 'д');
        rusLetters.Add(".", 'е');
        rusLetters.Add("...-", 'ж');
        rusLetters.Add("--..", 'з');
        rusLetters.Add("..", 'и');
        rusLetters.Add(".---", 'й');
        rusLetters.Add("-.-", 'к');
        rusLetters.Add(".-..", 'л');
        rusLetters.Add("--", 'м');
        rusLetters.Add("-.", 'н');
        rusLetters.Add("---", 'о');
        rusLetters.Add(".--.", 'п');
        rusLetters.Add(".-.", 'р');
        rusLetters.Add("...", 'с');
        rusLetters.Add("-", 'т');
        rusLetters.Add("..-", 'у');
        rusLetters.Add("..-.", 'ф');
        rusLetters.Add("....", 'х');
        rusLetters.Add("-.-.", 'ц');
        rusLetters.Add("---.", 'ч');
        rusLetters.Add("----", 'ш');
        rusLetters.Add("--.-", 'щ');
        rusLetters.Add(".--.-.", 'ъ');
        rusLetters.Add("-.--", 'ы');
        rusLetters.Add("-..-", 'ь');
        rusLetters.Add("..-..", 'э');
        rusLetters.Add("..--", 'ю');
        rusLetters.Add(".-.-", 'я');

        engLetters = new Dictionary<string, char>();
        engLetters.Add(".-", 'a');
        engLetters.Add("-...", 'b');
        engLetters.Add("-.-.", 'c');
        engLetters.Add("-..", 'd');
        engLetters.Add(".", 'e');
        engLetters.Add("..-.", 'f');
        engLetters.Add("--.", 'g');
        engLetters.Add("....", 'h');
        engLetters.Add("..", 'i');
        engLetters.Add(".---", 'j');
        engLetters.Add("-.-", 'k');
        engLetters.Add(".-..", 'l');
        engLetters.Add("--", 'm');
        engLetters.Add("-.", 'n');
        engLetters.Add("---", 'o');
        engLetters.Add(".--.", 'p');
        engLetters.Add("--.-", 'q');
        engLetters.Add(".-.", 'r');
        engLetters.Add("...", 's');
        engLetters.Add("-", 't');
        engLetters.Add("..-", 'u');
        engLetters.Add("...-", 'v');
        engLetters.Add(".--", 'w');
        engLetters.Add("-..-", 'x');
        engLetters.Add("-.--", 'y');
        engLetters.Add("--..", 'z');

        digits = new Dictionary<string, char>();
        digits.Add("-----", '0');
        digits.Add(".----", '1');
        digits.Add("..---", '2');
        digits.Add("...--", '3');
        digits.Add("....-", '4');
        digits.Add(".....", '5');
        digits.Add("-....", '6');
        digits.Add("--...", '7');
        digits.Add("---..", '8');
        digits.Add("----.", '9');

        punctuation = new Dictionary<string, char>();
        punctuation.Add("......", '.');
        punctuation.Add(".-.-.-", ',');
        punctuation.Add("..--.-", '_');
        punctuation.Add("..--..", '?');
        punctuation.Add("-.-.--", '!');
        punctuation.Add("-.-.-.", ';');
        punctuation.Add("---...", ':');
        punctuation.Add("-....-", '-');
        punctuation.Add("...-..-", '$');
        punctuation.Add(".--.-.", '@');
        punctuation.Add(".----.", '`');
        punctuation.Add(".-...", '&');
        punctuation.Add(".-.-.", '+');
        punctuation.Add("-...-", '=');
    }

    public Dictionary<string, char> RusLetters => rusLetters;
    public Dictionary<string, char> EngLetters => engLetters;
    public Dictionary<string, char> Digits => digits;
    public Dictionary<string, char> Punctuation => punctuation;
}