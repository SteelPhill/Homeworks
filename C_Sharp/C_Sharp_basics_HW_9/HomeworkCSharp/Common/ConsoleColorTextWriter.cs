using System;

namespace HomeworkCSharp;

public class ConsoleColorTextWriter : IColorTextWriter
{
    private ConsoleColor backgroundColor;
    private ConsoleColor foregroundColor;

    public ConsoleColorTextWriter(
        ConsoleColor backgroundColor, ConsoleColor foregroundColor)
    {
        this.backgroundColor = backgroundColor;
        this.foregroundColor = foregroundColor;
    }

    public void Write(string text)
    {
        Console.BackgroundColor = backgroundColor;
        Console.ForegroundColor = foregroundColor;
        Console.Write(text);
        Console.BackgroundColor = ConsoleColor.Black;
        Console.ForegroundColor = ConsoleColor.White;
    }

    public void WriteLine(string text)
    {
        Console.BackgroundColor = backgroundColor;
        Console.ForegroundColor = foregroundColor;
        Console.WriteLine(text);
        Console.BackgroundColor = ConsoleColor.Black;
        Console.ForegroundColor = ConsoleColor.White;
    }
}