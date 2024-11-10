using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace ActualHomework;

public class C_Sharp_basics_HW_6
{
    public static void Main()
    {
        try
        {
            Task1();
            //Task2();
            //Task3();
        }
        catch (Exception ex)
        {
            Console.Clear();
            Console.WriteLine($"Error: {ex.Message}");
        }
    }

    private static void Task1()
    {
        var journal1 = new Journal(5);
        Console.WriteLine(
            $"journal1.EmployeesNumber = {journal1.EmployeesNumber}");

        var journal2 = new Journal();
        journal2.EmployeesNumber = 5;
        Console.WriteLine(
            $"journal2.EmployeesNumber = {journal2.EmployeesNumber}\n");

        Console.WriteLine("  operator== Test:");
        if (journal1 == journal2)
            Console.WriteLine("journal1 == journal2");
        Console.WriteLine();

        Console.WriteLine("  operator+ Test:");
        Console.WriteLine($"journal1 + 10 = {journal1 += 10}");
        Console.WriteLine();

        Console.WriteLine("  operator!= Test:");
        if (journal1 != journal2)
            Console.WriteLine("journal1 != journal2");
        Console.WriteLine();

        Console.WriteLine("  operator- Test:");
        Console.WriteLine($"journal2 - 1 = {journal2 -= 1}");
        Console.WriteLine();

        Console.WriteLine("  operator< Test:");
        if (journal2 < journal1)
            Console.WriteLine("journal2 < journal1");
        Console.WriteLine();

        Console.WriteLine("  operator> Test:");
        if (journal1 > journal2)
            Console.WriteLine("journal1 > journal2");
        Console.WriteLine();

        Console.ReadKey();
    }

    private static void Task2()
    {
        var store1 = new Store();
        store1.Square = 200;
        Console.WriteLine($"store1.Square = {store1}");
        var store2 = new Store(200);
        Console.WriteLine($"store2.Square = {store2}\n");

        Console.WriteLine("  operator== Test:");
        if (store1 == store2)
            Console.WriteLine("store1 == store2");
        Console.WriteLine();

        Console.WriteLine("  operator+ Test:");
        Console.WriteLine($"store1 + 200 = {store1 += 200}");
        Console.WriteLine();

        Console.WriteLine("  operator!= Test:");
        if (store1 != store2)
            Console.WriteLine("store1 != store2");
        Console.WriteLine();

        Console.WriteLine("  operator- Test:");
        Console.WriteLine($"store2 - 50 = {store2 -= 50}");
        Console.WriteLine();

        Console.WriteLine("  operator< Test:");
        if (store2 < store1)
            Console.WriteLine("store2 < store1");
        Console.WriteLine();

        Console.WriteLine("  operator> Test:");
        if (store1 > store2)
            Console.WriteLine("store1 > store2");
        Console.WriteLine();

        Console.ReadKey();
    }

    private static void Task3()
    {
        IMenu booksListToReadConsoleMenu = 
            new BooksListToReadConsoleMenu();

        booksListToReadConsoleMenu.AddComand(new ShowAllBooksCommand());
        booksListToReadConsoleMenu.AddComand(new CheckBookCommand());
        booksListToReadConsoleMenu.AddComand(new AddBookCommand());
        booksListToReadConsoleMenu.AddComand(new RemoveBookCommand());

        booksListToReadConsoleMenu.Start();
    }
}

/*     
*          ЗАДАНИЕ №1
* Ранее в одном из практических заданий вы создавали класс «Журнал». 
* Добавьте к уже созданному классу информацию о количестве сотрудников. 
* Выполните перегрузку:
* + (для увеличения количества сотрудников на указанную величину),
* — (для уменьшения количества сотрудников на указанную величину), 
* == (проверка на равенство количества сотрудников), 
* < и > (проверка на меньше или больше количества сотрудников), 
* != и Equals. 
* Используйте механизм свойств для полей класса.
*/

public class Journal
{
    public int EmployeesNumber { get; set; }

    public Journal()
    {
        EmployeesNumber = 0;
    }

    public Journal(int employeesNumber)
    {
        EmployeesNumber = employeesNumber;
    }

    public static Journal operator +(Journal journal, int value)
    {
        return new Journal(journal.EmployeesNumber + value);
    }

    public static Journal operator +(int value, Journal journal)
    {
        return journal + value;
    }

    public static Journal operator -(Journal journal, int value)
    {
        return new Journal(journal.EmployeesNumber - value);
    }

    public static bool operator ==(Journal left, Journal right)
    {
        return (left is null && right is null) || 
            ((left is not null && right is not null) && left?.Equals(right) == true);
    }

    public static bool operator !=(Journal left, Journal right)
    {
        return (left is not null || right is not null) &&
            left?.Equals(right) != true;
    }

    public static bool operator <(Journal left, Journal right)
    {
        return left is not null && right is not null && 
            left.EmployeesNumber < right.EmployeesNumber;
    }

    public static bool operator >(Journal left, Journal right)
    {
        return left is not null && right is not null && 
            left.EmployeesNumber > right.EmployeesNumber;
    }

    public override bool Equals(object obj)
    {
        return obj is Journal journal && 
            EmployeesNumber == journal.EmployeesNumber;
    }

    public override int GetHashCode()
    {
        return EmployeesNumber;
    }

    public override string ToString()
    {
        return $"{EmployeesNumber}";
    }
}

/*     
*          ЗАДАНИЕ №2
* Ранее в одном из практических заданий вы создавали класс «Магазин». 
* Добавьте к уже созданному классу информацию о площади магазина. 
* Выполните перегрузку:
* + (для увеличения площади магазина на указанную величину), 
* — (для уменьшения площади магазина на указанную величину), 
* == (проверка на равенство площадей магазинов), 
* < и > (проверка на меньше или больше площади магазина), 
* != и Equals. 
* Используйте механизм свойств для полей класса.
*/

public class Store
{
    public int Square { get; set; }

    public Store()
    {
        Square = 0;
    }

    public Store(int square)
    {
        Square = square;
    }

    public static Store operator +(Store store, int value)
    {
        return new Store(store.Square + value);
    }

    public static Store operator +(int value, Store store)
    {
        return store + value;
    }

    public static Store operator -(Store store, int value)
    {
        return new Store(store.Square - value);
    }

    public static bool operator ==(Store left, Store right)
    {
        return (left is null && right is null) || 
            ((left is not null && right is not null) && left?.Equals(right) == true);
    }

    public static bool operator !=(Store left, Store right)
    {
        return (left is not null || right is not null) &&
            left?.Equals(right) != true;
    }

    public static bool operator <(Store left, Store right)
    {
        return left is not null && right is not null &&
            left.Square < right.Square;
    }

    public static bool operator >(Store left, Store right)
    {
        return left is not null && right is not null &&
            left.Square > right.Square;
    }

    public override bool Equals(object obj)
    {
        return obj is Store store && Square == store.Square;
    }

    public override int GetHashCode()
    {
        return Square;
    }

    public override string ToString()
    {
        return $"{Square}";
    }
}

/*     
*          ЗАДАНИЕ №3
* Создайте приложение «Список книг для прочтения». 
* Приложение должно позволять добавлять книги в список, 
* удалять книги из списка, проверять есть ли книга в списке, и т. д. 
* Используйте механизм свойств, перегрузки операторов, индексаторов. 
*/

public class Book
{
    public string Name { get; set; }
    public string Author { get; set; }

    public Book(string name, string author)
    {
        Name = name;
        Author = author;
    }

    public override string ToString()
    {
        return $"Name: {Name}\nAuthor: {Author}\n";
    }
}

public class BookDB
{
    private List<Book> books = new List<Book>();

    public BookDB() { }

    public BookDB(BookDB bookDB)
    {
        books = bookDB.books;
    }

    public int Length => books.Count;

    public Book this[int index]
    {
        get => books[index];
        set => books[index] = value;
    }

    public static BookDB operator +(BookDB bookDB, Book book)
    {
        if (!bookDB.IsContain(book))
            bookDB.books.Add(book);
        return new BookDB(bookDB);
    }

    public static BookDB operator -(BookDB bookDB, Book book)
    {
        bookDB
            .books
            .RemoveAll(
            b => b.Name == book.Name && b.Author == book.Author);
        return new BookDB(bookDB);
    }

    public bool IsContain(Book book)
    { 
        return books
            .Any(
            b => b.Name == book.Name && b.Author == book.Author); 
    }

    public override string ToString()
    {
        StringBuilder sb = new StringBuilder();

        foreach (var book in books)
            sb.AppendLine(book.ToString());

        return sb.ToString();
    }
}

interface IMenu
{
    void AddComand(IMenuCommand command);
    void Start();
}

public class BooksListToReadConsoleMenu : IMenu
{
    private List<IMenuCommand> commands;
    private BookDB bookDB;
    private static IMenuSelector consoleSelector;
    private const string ProgramName = "Books list to read";

    public BooksListToReadConsoleMenu()
    {
        commands = new List<IMenuCommand>();
        consoleSelector = new MenuSelector();
        bookDB = new BookDB();

        bookDB += new Book("Book1", "Author1");
        bookDB += new Book("Book2", "Author2");
        bookDB += new Book("Book3", "Author3");
    }

    public void AddComand(IMenuCommand command)
    {
        commands.Add(command);
    }

    public void Start()
    {
        while (true)
        {
            int selector = 
                consoleSelector.Select(ProgramName, commands);
            if (selector == commands.Count)
                break;

            Console.Clear();
            ExecuteCommand(selector);
        }
    }

    private void ExecuteCommand(int selector)
    {
        try
        {
            commands[selector].Execute(bookDB);
        }
        catch (Exception ex)
        {
            Console.Clear();
            Console.WriteLine(
                $"An error has occurred: {ex.Message}");
            Console.ReadKey();
        }

        Console.WriteLine();
        Console.Clear();
    }
}

public interface IMenuCommand
{
    string GetDiscription();
    void Execute(BookDB bookDB);
}

public class AddBookCommand : IMenuCommand
{
    private static IConsoleBookReader consoleBookReader;

    public AddBookCommand()
    {
        consoleBookReader = new ConsoleBookReader();
    }

    public string GetDiscription()
    {
        return "Add book";
    }

    public void Execute(BookDB bookDB)
    {
        Book book = consoleBookReader.Read();
        bookDB = bookDB + book;
    }
}

public class RemoveBookCommand : IMenuCommand
{
    private static IConsoleBookReader consoleBookReader;

    public RemoveBookCommand()
    {
        consoleBookReader = new ConsoleBookReader();
    }

    public string GetDiscription()
    {
        return "Remove book";
    }

    public void Execute(BookDB bookDB)
    {
        Book book = consoleBookReader.Read();
        bookDB -= book;
    }
}

public class CheckBookCommand : IMenuCommand
{
    private static IConsoleBookReader consoleBookReader;

    public CheckBookCommand()
    {
        consoleBookReader = new ConsoleBookReader();
    }

    public string GetDiscription()
    {
        return "Check book";
    }

    public void Execute(BookDB bookDB)
    {
        Book book = consoleBookReader.Read();

        if (bookDB.IsContain(book))
            Console.WriteLine(
                "\nThis book is on books list to read");
        else
            Console.WriteLine(
                "\nThis book is NOT on books list to read");

        Console.ReadKey();
    }
}

public class ShowAllBooksCommand : IMenuCommand
{
    private static IConsoleBookReader consoleBookReader;

    public ShowAllBooksCommand()
    {
        consoleBookReader = new ConsoleBookReader();
    }

    public string GetDiscription()
    {
        return "Show all books";
    }

    public void Execute(BookDB bookDB)
    {
        Console.WriteLine("Books list to read\n");
        Console.WriteLine(bookDB);
        Console.ReadKey();
    }
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

interface IMenuSelector
{
    int Select(
        string programName,
        List<IMenuCommand> commands);
}

public class MenuSelector : IMenuSelector
{
    private IMenuPrinter menuPrinter = new MenuPrinter();

    public int Select(
        string programName,
        List<IMenuCommand> commands)
    {
        int selector = 0;
        int elementsNumber = commands.Count + 1;
        ConsoleKey key;

        do
        {
            Console.Clear();
            menuPrinter.Print(programName, commands, selector);

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
}

interface IMenuPrinter
{
    void Print(
        string programName,
        List<IMenuCommand> commands,
        int selector);
}

public class MenuPrinter : IMenuPrinter
{
    private static ITextBlackOnWhiteWriter textWriter;

    public MenuPrinter()
    {
        textWriter = new ConsoleTextBlackOnWhiteWriter();
    }

    public void Print(
        string programName,
        List<IMenuCommand> commands,
        int selector)
    {
        Console.WriteLine($"{programName}\n");
        Console.WriteLine("\tMenu");

        for (int i = 0; i < commands.Count; i++)
        {
            if (selector == i)
                textWriter.WriteLine(commands[i].GetDiscription());

            else
                Console.WriteLine(commands[i].GetDiscription());
        }

        if (selector == commands.Count)
            textWriter.WriteLine("Exit");
        else
            Console.WriteLine("Exit");
    }
}

interface IConsoleBookReader
{
    Book Read();
}

public class ConsoleBookReader : IConsoleBookReader
{
    public Book Read()
    {
        Console.Write("Input book name => ");
        string name = Console.ReadLine();

        Console.Write("Input book author => ");
        string author = Console.ReadLine();

        if (string.IsNullOrEmpty(name) || string.IsNullOrEmpty(author))
            throw new Exception("Empty line");

        return new Book(name, author);
    }
}