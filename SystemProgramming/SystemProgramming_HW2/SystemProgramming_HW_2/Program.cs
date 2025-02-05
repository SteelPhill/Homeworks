using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using SystemProgramming_HW_2.Helpers;

namespace SystemProgramming_HW_2;

public static class Program
{
    public static void Main(string[] args)
    {
        Task1();
        //Task2();
        //Task3();
        //Task4();

        Console.WriteLine();
        Console.WriteLine("Нажмите любую клавишу...");
        Console.ReadKey();
    }

    /*      Задание №1
     *
     * Разработайте приложение, которое умеет запускать дочерний процесс и ожидать его завершения. 
     * Когда дочерний процесс завершен, родительское приложение должно отобразить код завершения.
     * 
     */

    private static void Task1()
    {
        var subProcess = Process.Start("notepad");
        if (subProcess == null)
        {
            Console.WriteLine("Не удалось запустить дочерний процесс!");
            return;
        }

        subProcess.WaitForExit();
        Console.WriteLine("Дочерний процесс завершен.");
    }

    /*      Задание №2
     *
     * Разработайте приложение, которое умеет запускать дочерний процесс. 
     * В зависимости от выбора пользователя родительское приложение должно ожидать завершения дочернего процесса и 
     * отображать код завершения либо принудительно завершать работу дочернего процесса.
     * 
     */

    private static void Task2()
    {
        var subProcess = Process.Start("notepad");
        if (subProcess == null)
        {
            Console.WriteLine("Не удалось запустить дочерний процесс!");
            return;
        }

        var commands = new List<string>
        {
            "Ждать завершение дочернего процесса",
            "Завершить дочерний процесс принудительно"
        };

        ConsoleMenuHelper.PrintCommands(commands, "Выход");

        var selector = ConsoleReadHelper.ReadInt(" => ", 0, commands.Count);
        Console.WriteLine();

        switch (selector)
        {
            case 0:
                return;
            case 1:
                Console.WriteLine("Ожидание завершения дочернего процесса...");
                Console.WriteLine();
                subProcess.WaitForExit();
                Console.WriteLine("Дочерний процесс завершен.");
                return;
            case 2:
                subProcess.Kill();
                Console.WriteLine("Дочерний процесс завершен принудительно.");
                return;
            default:
                return;
        }
    }

    /*      Задание №3
     *
     * Разработайте приложение, которое умеет запускать дочерний процесс и передавать ему аргументы командной строки. 
     * В качестве аргументов должно быть два числа и операция, которую необходимо выполнить. 
     * Например, аргументы: 
     * - 7;
     * - 3; 
     * - +.
     * Дочерний процесс должен отобразить аргументы и вывести результат сложения 10 на экран. 
     * 
     */

    private static void Task3()
    {
        var args = Environment.GetCommandLineArgs();
        if (args.Length != 4 || !double.TryParse(args[1], out var firstValue) || !double.TryParse(args[2], out var secondValue))
        {
            Console.WriteLine("Аргументы командной строки переданы неверно!");
            return;
        }
        var operation = args[3];

        var tempFilePath = Path.GetTempFileName();

        switch (operation)
        {
            case "+":
                File.WriteAllText(tempFilePath, $"{firstValue} + {secondValue} = {firstValue + secondValue}");
                break;
            case "-":
                File.WriteAllText(tempFilePath, $"{firstValue} - {secondValue} = {firstValue - secondValue}");
                break;
            case "*":
                File.WriteAllText(tempFilePath, $"{firstValue} * {secondValue} = {firstValue * secondValue}");
                break;
            case "/":
                File.WriteAllText(tempFilePath, $"{firstValue} / {secondValue} = {firstValue / secondValue}");
                break;
            default:
                Console.WriteLine("Аргументы командной строки переданы неверно!");
                return;
        }

        var subProcess = new Process();
        subProcess.StartInfo.FileName = "notepad";
        subProcess.StartInfo.Arguments = tempFilePath;
        subProcess.Start();
        if (subProcess == null)
            Console.WriteLine("Не удалось запустить дочерний процесс!");
    }

    /*      Задание №4
     *
     * Разработайте приложение, которое умеет запускать дочерний процесс и передавать ему аргументы командной строки. 
     * В качестве аргументов должны быть путь к файлу и слово для поиска. 
     * Например, аргументы: 
     * - E:\someFolder; 
     * - bicycle. 
     * Дочерний процесс должен отобразить количество раз, сколько слово bicycle встречается в файле.
     * 
     */

    private static void Task4()
    {
        var args = Environment.GetCommandLineArgs();

        if (args.Length < 3)
        {
            Console.WriteLine("Аргументы командной строки переданы неверно!");
            return;
        }

        var path = args[1];
        var searchedWord = args[2];

        var count = File
            .ReadAllLines(path)
            .SelectMany(w => w.Split(' '))          
            .Where(w => w == searchedWord)
            .Count();

        var tempFilePath = Path.GetTempFileName();
        File.WriteAllText(tempFilePath, $"Слово \"{searchedWord}\" повторяется {count} раз(а).");

        var subProcess = new Process();
        subProcess.StartInfo.FileName = "notepad";
        subProcess.StartInfo.Arguments = tempFilePath;
        subProcess.Start();
        if (subProcess == null)
            Console.WriteLine("Не удалось запустить дочерний процесс!");
    }
}